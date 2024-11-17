#include "Bottle.h"

// member functions of the Bottle class

bool Bottle::isFull() const
{
    return colors.size() == 4;
}

bool Bottle::isEmpty() const
{
    return colors.empty();
}

char Bottle::top() const
{
    if (!colors.empty())
    {
        return colors.front(); // Get the top color
    }
    return ' '; // Return empty space if the bottle is empty
}

void Bottle::pop(int count)
{
    for (int i = 0; i < count && !colors.empty(); i++)
    {
        colors.erase(colors.begin()); // pop the top color from top of the bottle
    }
}

void Bottle::push(char color)
{
    if (colors.size() < 4)
    {
        colors.insert(colors.begin(), color); // Add color to the top of the bottle
    }
}

bool Bottle::canPourInto(const Bottle &other) const
{
    return !colors.empty() && (other.isEmpty() || other.top() == top()) && other.colors.size() < 4;
}

bool Bottle::isSorted() const
{
    if (colors.empty())
        return true;
    return all_of(colors.begin(), colors.end(), [&](char c)
                  { return c == colors[0]; });
}

bool Bottle::isFullySorted() const
{
    return isSorted() && colors.size() == 4; // Check if all four colors are the same
}

int Bottle::pourableCount() const // number of consecutive colors from the top of the Bottle that can be poured
{
    if (colors.empty())
        return 0;
    char topColor = top();
    int count = 0;
    for (char color : colors)
    {
        if (color == topColor)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}

string Bottle::getColorCode(char color) const // ANSI ESCAPE CODES
{
    switch (color)
    {
    case 'R':
        return "\033[41m"; // Red background
    case 'G':
        return "\033[42m"; // Green background
    case 'B':
        return "\033[44m"; // Blue background
    case 'Y':
        return "\033[43m"; // Yellow background
    case 'P':
        return "\033[45m"; // Purple background
    case 'C':
        return "\033[46m"; // Cyan background
    case 'O':
        return "\033[48;5;214m"; // Orange background
    case 'M':
        return "\033[48;5;125m"; // Magenta background
    case 'L':
        return "\033[48;5;220m"; // Light Yellow background
    case 'A':
        return "\033[48;5;208m"; // Amber background
    case 'D':
        return "\033[48;5;34m"; // Dark Green background
    case 'E':
        return "\033[48;5;202m"; // Earth Brown background
    case 'I':
        return "\033[48;5;93m"; // Indigo background
    case 'S':
        return "\033[48;5;240m"; // Silver background
    case 'H':
        return "\033[48;5;255m"; // Light Grey background
    case 'N':
        return "\033[48;5;27m"; // Navy Blue background
    case 'V':
        return "\033[48;5;129m"; // Violet background
    case 'Q':
        return "\033[48;5;160m"; // Crimson background
    case 'T':
        return "\033[48;5;100m"; // Teal background
    case 'F':
        return "\033[48;5;214m"; // Firebrick background
    default:
        return "\033[40m"; // Default to black background if an undefined color is used
    }
}

string Bottle::displayRow(int row) const
{
    if (row < 4 - colors.size())
    {
        return "   "; // 3 spaces to keep the bottles aligned
    }
    else
    {
        char color = colors[row - (4 - colors.size())];
        return getColorCode(color) + "   " + "\033[0m"; // Add color to background with fixed 3-space width
    }
}

// Implement the external functions

void displayBottles(const vector<Bottle> &bottles)
{
    int rows = 4; // Each bottle has up to 4 colors
    for (int row = 0; row < rows; row++)
    {
        for (int i = 0; i < bottles.size(); i++)
        {
            cout << "| " << bottles[i].displayRow(row) << " |   "; // Display with colors and spacing
        }
        cout << "\n";
    }
    for (int i = 0; i < bottles.size(); i++)
    {
        cout << "-------   "; // Bottles base
    }
    cout << "\n";

    for (int i = 0; i < bottles.size(); i++) // Display numbering for each bottle
    {
        cout << "   " << i + 1 << "      ";
    }
    cout << "\n";
}

bool isGameCompleted(const vector<Bottle> &bottles)
{
    int emptyCount = 0;
    for (const auto &bottle : bottles)
    {
        if (bottle.isEmpty())
        {
            emptyCount++;
        }
    }

    if (emptyCount < 2)
    {
        return false;
    }

    for (size_t i = 0; i < bottles.size(); i++)
    {
        if (!bottles[i].isSorted() && !bottles[i].isEmpty())
            return false;
    }

    return true;
}

string stateToString(const vector<Bottle> &bottles)
{
    string state;
    for (const auto &bottle : bottles)
    {
        for (char color : bottle.colors)
        {
            state += color;
        }
        state += '|'; // Separate each bottle with a pipe
    }
    return state;
}

bool moveWater(vector<Bottle> &bottles, int from, int to)
{
    if (from == to || bottles[from].isEmpty())
    {
        return false;
    }

    if (bottles[from].canPourInto(bottles[to]))
    {
        int pourCount = bottles[from].pourableCount();
        if (pourCount > (4 - bottles[to].colors.size()))
        {
            pourCount = 4 - bottles[to].colors.size();
        }

        char movingColor = bottles[from].top();
        bottles[from].pop(pourCount);

        for (int i = 0; i < pourCount; i++)
        {
            bottles[to].push(movingColor);
        }

        return true;
    }
    return false;
}

bool solvePuzzle(vector<Bottle> &bottles, set<string> &visitedStates, vector<pair<int, int>> &solution, int &moveCount)
{
    if (isGameCompleted(bottles))
    {
        return true;
    }

    string currentState = stateToString(bottles);

    if (visitedStates.count(currentState))
    {
        return false;
    }

    visitedStates.insert(currentState);

    // Move from bottles that are not fully sorted
    for (int i = 0; i < bottles.size(); i++)
    {
        if (bottles[i].isFullySorted() || bottles[i].isEmpty())
        {
            continue; // Skip fully sorted or empty bottles
        }

        char topColor = bottles[i].top();

        // Attempt to pour into a bottle with the same top color
        for (int j = 0; j < bottles.size(); j++)
        {
            if (i != j && bottles[j].top() == topColor && !bottles[j].isFullySorted() && bottles[j].colors.size() < 4)
            {
                vector<Bottle> tempBottles = bottles;
                if (moveWater(tempBottles, i, j))
                {
                    solution.push_back({i + 1, j + 1});
                    moveCount++;

                    cout << "\n"
                         << moveCount << "] AFTER MOVING FROM BOTTLE " << i + 1 << " TO BOTTLE " << j + 1 << " :-\n\n";
                    displayBottles(tempBottles);

                    if (solvePuzzle(tempBottles, visitedStates, solution, moveCount))
                    {
                        return true;
                    }
                    solution.pop_back();
                    moveCount--; // Backtrack the move count on unsuccessful paths
                }
            }
        }

        // Check for other bottles that might have the same top color and pour into the current bottle first
        for (int j = 0; j < bottles.size(); j++)
        {
            if (i != j && bottles[j].top() == topColor && !bottles[j].isFullySorted())
            {
                vector<Bottle> tempBottles = bottles;
                if (moveWater(tempBottles, j, i)) // Move the matching color from Bottle j to Bottle i
                {
                    solution.push_back({j + 1, i + 1});
                    moveCount++;

                    cout << "\n"
                         << moveCount << "] AFTER MOVING FROM BOTTLE " << j + 1 << " TO BOTTLE " << i + 1 << " :-\n\n";
                    displayBottles(tempBottles);

                    if (solvePuzzle(tempBottles, visitedStates, solution, moveCount))
                    {
                        return true;
                    }
                    solution.pop_back();
                    moveCount--;
                }
            }
        }

        // If no suitable bottle with the same top color is found, then try moving to empty bottles
        for (int j = 0; j < bottles.size(); j++)
        {
            if (i != j && bottles[j].isEmpty())
            {
                vector<Bottle> tempBottles = bottles;
                if (moveWater(tempBottles, i, j))
                {
                    solution.push_back({i + 1, j + 1});
                    moveCount++;

                    cout << "\n"
                         << moveCount << "] AFTER MOVING FROM BOTTLE " << i + 1 << " TO BOTTLE " << j + 1 << " :-\n\n";
                    displayBottles(tempBottles);

                    if (solvePuzzle(tempBottles, visitedStates, solution, moveCount))
                    {
                        return true;
                    }
                    solution.pop_back();
                    moveCount--;
                }
            }
        }
    }

    return false;
}

void manualSolve(vector<Bottle> &bottles, set<string> &visitedStates, vector<pair<int, int>> &solution, int &moveCount)
{
    stack<pair<int, int>> moveStack;      // Stack to keep track of moves
    stack<vector<Bottle>> previousStates; // Stack to keep track of previous bottle states

    int from, to;

    while (!isGameCompleted(bottles))
    {
        cout << "ENTER THE BOTTLE NUMBER TO MOVE [FROM AND TO] OR [PRESS 0 TO LET THE COMPUTER SOLVE] OR [PRESS -1 TO UNDO] :- ";
        cin >> from;

        if (from == 0) // Let the computer solve the puzzle
        {
            cout << "\nCOMPUTER IS NOW SOLVING THE PUZZLE ...\n";
            if (solvePuzzle(bottles, visitedStates, solution, moveCount))
            {
                cout << "\n                                  PUZZLE SOLVED IN " << moveCount << " MOVES !\n";
            }
            else
            {
                cout << "NO SOLUTION POSSIBLE !\n";
            }
            return;
        }
        else if (from == -1) // Undo the last move
        {
            if (!moveStack.empty() && !previousStates.empty())
            {
                moveStack.pop();                // Remove the last move from the stack
                bottles = previousStates.top(); // Restore the previous bottle state
                previousStates.pop();           // Remove the state from the stack

                moveCount--;
                cout << "UNDID THE PRIVIOUS MOVE. THIS IS THE MOST RECENT BOTTLE STATE :- \n\n";
                displayBottles(bottles);
            }
            else
            {
                cout << "NO MOVES TO UNDO.\n\n";
            }
            continue;
        }

        cin >> to;

        if (from < 1 || from > bottles.size() || to < 1 || to > bottles.size())
        {
            cout << "INVALID MOVE! PLEASE ENTER VALID BOTTLE NUMBERS BETWEEN 1 AND " << bottles.size() << ".\n\n";
            displayBottles(bottles);
            cout << "\n";
            continue;
        }

        if (from == to)
        {
            cout << "INVALID MOVE! SOURCE AND DESTINATION BOTTLES CANNOT BE THE SAME.\n\n";
            displayBottles(bottles);
            cout << "\n";
            continue;
        }

        previousStates.push(bottles); // Store the current state before making a move
        if (moveWater(bottles, from - 1, to - 1))
        {
            moveStack.push({from - 1, to - 1}); // Store the move
            moveCount++;
            cout << moveCount << "] MOVED FROM BOTTLE " << from << " TO BOTTLE " << to << ".\n\n";
        }
        else
        {
            cout << "INVALID MOVE. TRY AGAIN !\n\n";
            bottles = previousStates.top();
            previousStates.pop();
        }

        displayBottles(bottles);
        cout << "\n";
    }

    cout << "                CONGRATULATIONS! YOU'VE COMPLETED THE PUZZLE IN " << moveCount << " MOVES !\n";
}
void displayColorOptions()
{
    cout << "                              AVAILABEL COLOURS AND THEIR INITIALS :- \n\n";
    cout << "                                      R -> RED            " << "\033[41m   \033[0m\n";       // Red
    cout << "                                      G -> GREEN          " << "\033[42m   \033[0m\n";       // Green
    cout << "                                      B -> BLUE           " << "\033[44m   \033[0m\n";       // Blue
    cout << "                                      Y -> YELLOW         " << "\033[43m   \033[0m\n";       // Yellow
    cout << "                                      P -> PURPLE         " << "\033[45m   \033[0m\n";       // Purple
    cout << "                                      C -> CYAN           " << "\033[46m   \033[0m\n";       // Cyan
    cout << "                                      O -> ORANGE         " << "\033[48;5;214m   \033[0m\n"; // Orange
    cout << "                                      M -> MAGENTA        " << "\033[48;5;125m   \033[0m\n"; // Magenta
    cout << "                                      L -> LIGHT YELLOW   " << "\033[48;5;220m   \033[0m\n"; // Light Yellow
    cout << "                                      A -> AMBER          " << "\033[48;5;208m   \033[0m\n"; // Amber
    cout << "                                      D -> DARK GREEN     " << "\033[48;5;34m   \033[0m\n";  // Dark Green
    cout << "                                      E -> EARTH BROWN    " << "\033[48;5;202m   \033[0m\n"; // Earth Brown
    cout << "                                      I -> INDIGO         " << "\033[48;5;93m   \033[0m\n";  // Indigo
    cout << "                                      S -> SILVER         " << "\033[48;5;240m   \033[0m\n"; // Silver
    cout << "                                      H -> LIGHT GREY     " << "\033[48;5;255m   \033[0m\n"; // Light Grey
    cout << "                                      N -> NAVY BLUE      " << "\033[48;5;27m   \033[0m\n";  // Navy Blue
    cout << "                                      V -> VIOLET         " << "\033[48;5;129m   \033[0m\n"; // Violet
    cout << "                                      Q -> CRIMSON        " << "\033[48;5;160m   \033[0m\n"; // Crimson
    cout << "                                      T -> TEAL           " << "\033[48;5;100m   \033[0m\n"; // Teal
    cout << "                                      F -> FIREBRICK      " << "\033[48;5;214m   \033[0m\n"; // Firebrick
}
