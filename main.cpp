#include <iostream>
#include "LoadLevel.h"
#include "Bottle.h"
#include "UserData.h"

using namespace std;

int main()
{
    bool isAuthenticated = false; 
    string username;             
    int lastCompletedLevel = 0;  
    int level = lastCompletedLevel + 1;

    cout << "\n";
    cout << R"(

▗▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▖
▐▌                                                                                                     ▐▌
▐▌                                                                                                     ▐▌
▐▌    ▗▖ ▗▖ ▗▄▖▗▄▄▄▖▗▄▄▄▖▗▄▄▖     ▗▄▄▖  ▗▄▖▗▄▄▄▖▗▄▄▄▖▗▖   ▗▄▄▄▖    ▗▄▄▖ ▗▖ ▗▖▗▄▄▄▄▖▗▄▄▄▄▖▗▖   ▗▄▄▄▖    ▐▙▄▄▄▄▄▄
▐▌    ▐▌ ▐▌▐▌ ▐▌ █  ▐▌   ▐▌ ▐▌    ▐▌ ▐▌▐▌ ▐▌ █    █  ▐▌   ▐▌       ▐▌ ▐▌▐▌ ▐▌   ▗▞▘   ▗▞▘▐▌   ▐▌       ▐▌     ▐▌
▐▌    ▐▌▄▐▌▐▛▀▜▌ █  ▐▛▀▀▘▐▛▀▚▖    ▐▛▀▚▖▐▌ ▐▌ █    █  ▐▌   ▐▛▀▀▘    ▐▛▀▘ ▐▌ ▐▌ ▗▞▘   ▗▞▘  ▐▌   ▐▛▀▀▘    ▐▌     ▐▌
▐▌    ▐▙█▟▌▐▌ ▐▌ █  ▐▙▄▄▖▐▌ ▐▌    ▐▙▄▞▘▝▚▄▞▘ █    █  ▐▙▄▄▖▐▙▄▄▖    ▐▌   ▝▚▄▞▘▐▙▄▄▄▖▐▙▄▄▄▖▐▙▄▄▖▐▙▄▄▖    ▐▌     ▐▌
▐▌                                                                                                     ▐▙▄▄▄▄▄▟▌
▐▌                                                                                                     ▐▌
▐▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟▌
                                                                                         
                                                                                             
)";

    cout << "\n\n----------------------------------------------+---------------------------------------------\n";
    cout << "---------------------------------------+ INSTRUCTIONS +-------------------------------------\n";
    cout << "----------------------------------------------+---------------------------------------------\n\n";
    cout << "YOUR OBJECTIVE IS TO SORT THE COLORED WATER IN THE BOTTLES UNTIL EACH BOTTLE \n";
    cout << "CONTAINS WATER OF ONLY ONE COLOR.\n\n";
    cout << "HERE'S HOW TO PLAY :\n";

    cout << "1] YOU WILL SEE MULTIPLE BOTTLES FILLED WITH COLORED WATER.\n";
    cout << "2] EACH BOTTLE CAN HOLD A MAXIMUM OF FOUR UNITS OF WATER, AND YOU WILL HAVE 2 EMPTY BOTTLES \n";
    cout << "   TO HELP YOU SORT THE COLORS.\n";

    cout << "3] YOU CAN POUR WATER FROM ONE BOTTLE TO ANOTHER UNDER THE FOLLOWING CONDITIONS :\n";
    cout << "   I) THE TARGET BOTTLE MUST BE EMPTY.\n";
    cout << "   II) THE TOP COLOR MUST MATCH.\n";

    cout << "4] CHOOSE A BOTTLE WITH WATER TO POUR FROM AND SELECT THE TARGET BOTTLE \n";
    cout << "   WHERE YOU WANT TO POUR THE WATER.\n";

    cout << "5] THE GAME IS COMPLETED WHEN ALL THE BOTTLES ARE SORTED, MEANING EACH BOTTLE \n";
    cout << "   CONTAINS WATER OF ONLY ONE COLOR.\n\n";

    cout << "TIPS FOR SUCCESS :\n";
    cout << "1] PLAN YOUR MOVES AHEAD TO AVOID GETTING STUCK.\n";
    cout << "2] USE EMPTY BOTTLES STRATEGICALLY TO ASSIST IN SORTING THE COLORS.\n";

    // Call the user authentication function
    userAuthentication(isAuthenticated, username, lastCompletedLevel);

    if (!isAuthenticated)
    {

        displayLeaderboard(); // Display the leaderboard before exiting
        return 0;             
    }

    int Choice_Menu;
    cout << "\n\n----------------------------------------------+---------------------------------------------\n";
    cout << "-------------------------------------------+ MENU +-----------------------------------------\n";
    cout << "----------------------------------------------+---------------------------------------------\n\n";
    cout << "                                 1. YOU'RE EXCITED TO PLAY\n";
    cout << "                                 2. YOU'RE LOOKING FOR AN ANSWER\n";
    cout << "                                 ENTER YOUR CHOICE :- ";
    cin >> Choice_Menu;
    cout << "\n----------------------------------------------+----------------------------------------------\n\n";

    if (Choice_Menu == 1)
    {
        cout << "                                      LEVEL " << lastCompletedLevel + 1 << " RESUMING !\n";
        cout << "\n----------------------------------------------+----------------------------------------------\n\n";

        for (int level = lastCompletedLevel + 1; level <= 20; ++level) // Loop from level 1 to 20
        {
            if (level >= 1 && level <= 20) 
            {
                vector<Bottle> bottles;
                LoadLevel(bottles, level); // Load the current level

                cout << "                                         LEVEL " << level << " !\n";
                cout << "\n----------------------------------------------+----------------------------------------------\n\n";

                cout << "                                 INITIAL STATE OF BOTTLES :- \n\n";
                displayBottles(bottles);

                set<string> visitedStates;
                vector<pair<int, int>> solution;
                int moveCount = 0;

                int Choice_Solve;
                cout << "\n----------------------------------------------+----------------------------------------------\n\n";
                cout << "                                        CHOOSE AN OPTION :- \n";
                cout << "                                    1. SOLVE IT BY YOURSELF\n";
                cout << "                                    2. SOLVE IT WITH THE COMPUTER\n";
                cout << "                                    3. EXIT\n";
                cout << "                                        ENTER YOUR CHOICE :- ";
                cin >> Choice_Solve;
                cout << "\n----------------------------------------------+----------------------------------------------\n\n";

                if (Choice_Solve == 1)
                {
                    manualSolve(bottles, visitedStates, solution, moveCount);
                }
                else if (Choice_Solve == 2)
                {
                    if (solvePuzzle(bottles, visitedStates, solution, moveCount))
                    {
                        cout << "\n----------------------------------------------+----------------------------------------------\n";
                        cout << "\n                                  PUZZLE SOLVED IN " << moveCount << " MOVES !\n";
                    }
                    else
                    {
                        cout << "\n----------------------------------------------+----------------------------------------------\n";
                        cout << "                                    NO SOLUTION POSSIBLE !!!\n";
                        cout << "\n----------------------------------------------+----------------------------------------------\n";
                    }
                }
                else if (Choice_Solve == 3)
                {
                    cout << "                                  EXITING THE GAME ...\n";
                    cout << "\n----------------------------------------------+----------------------------------------------\n";
                    saveUserProgress(username, level - 1); 
                    displayLeaderboard();                  
                    return 0;
                }
                else
                {
                    cout << "                                  INVALID CHOICE. EXITING !!!\n";
                    saveUserProgress(username, level - 1); 
                    displayLeaderboard();                
                    return 0;
                }

                saveUserProgress(username, level);
                cout << "\n----------------------------------------------+----------------------------------------------\n\n";
                cout << "                                     LEVEL " << level << " COMPLETED !\n";
                cout << "\n----------------------------------------------+----------------------------------------------\n\n";
            }
        }
        cout << "\n----------------------------------------------+----------------------------------------------\n";
        cout << "                                  CONGRATULATIONS! YOU HAVE COMPLETED ALL 20 LEVELS!\n";
        cout << "\n----------------------------------------------+----------------------------------------------\n";
    }
    else if (Choice_Menu == 2)
    {
        int numBottles;
        int moveCount = 0; 

        cout << "                             ENTER THE NUMBER OF BOTTLES :- ";
        cin >> numBottles;
        numBottles += 2; 

        vector<Bottle> bottles(numBottles);
        cout << "              YOU HAVE " << numBottles - 2 << " BOTTLES TO INPUT. EACH BOTTLE WILL HAVE 4 COLOURS.\n";
        cout << "                      TO SOLVE THE PUZZLE , YOU HAVE 2 EXTRA BOTTLES.\n";
        cout << "\n----------------------------------------------+----------------------------------------------\n\n";

        displayColorOptions();

        cout << "\n----------------------------------------------+----------------------------------------------\n\n";

        for (int i = 0; i < numBottles - 2; i++)
        {
            cout << "          ENTER COLOURS FOR BOTTLE " << i + 1 << " (FROM BOTTOM TO TOP, 4 COLOURS) :- ";
            for (int j = 0; j < 4; j++)
            {
                char color;
                cin >> color;

                if (string("RGBYPCEIMHNDVQTF").find(color) == string::npos) // check if color is valid
                {
                    cout << "INVALID COLOR ! PLEASE ENTER A VALID COLOR (R, G, B, Y, P, C, E, I, M, H, N, D, V, Q, T, F): \n";
                    j--; // decrement j to repeat the input
                    continue;
                }

                bottles[i].push(color);
            }
        }

        cout << "\n----------------------------------------------+----------------------------------------------\n\n";

        cout << "                                 INITIAL STATE OF BOTTLES :- \n\n";
        displayBottles(bottles);

        set<string> visitedStates;
        vector<pair<int, int>> solution;

        int Choice_Solve;
        cout << "\n----------------------------------------------+----------------------------------------------\n\n";
        cout << "                                        CHOOSE AN OPTION :- \n";
        cout << "                                    1. SOLVE IT BY YOURSELF\n";
        cout << "                                    2. SOLVE IT WITH THE COMPUTER\n";
        cout << "                                        ENTER YOUR CHOICE :- ";
        cin >> Choice_Solve;
        cout << "\n----------------------------------------------+----------------------------------------------\n\n";

        if (Choice_Solve == 1)
        {
            manualSolve(bottles, visitedStates, solution, moveCount);
            cout << "\n----------------------------------------------+----------------------------------------------\n";
        }
        else if (Choice_Solve == 2)
        {
            if (solvePuzzle(bottles, visitedStates, solution, moveCount))
            {
                cout << "\n                                  PUZZLE SOLVED IN " << moveCount << " MOVES !\n";
            }
            else
            {
                cout << "\n----------------------------------------------+----------------------------------------------\n";
                cout << "                                    NO SOLUTION POSSIBLE !!!\n";
                cout << "\n----------------------------------------------+----------------------------------------------\n";
            }
            cout << "\n----------------------------------------------+----------------------------------------------\n";
        }
        else
        {
            cout << "                                  INVALID CHOICE. EXITING !!!\n";
        }
    }
    else
    {
        cout << "                                  INVALID CHOICE. EXITING !!!\n";
        saveUserProgress(username, level - 1); 
        displayLeaderboard();                 
    }

    return 0;
}
