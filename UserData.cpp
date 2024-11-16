#include "UserData.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cctype>
#include <string>
#include <iomanip>   
#include <algorithm> 
#include <vector>

using namespace std;

unordered_map<string, pair<string, int>> users; // username -> <password, lastCompletedLevel>

bool isValidUsername(const string &username)
{
    if (username.length() < 4)
    {
        return false; 
    }

    for (char ch : username)
    {
        if (!isalpha(ch))
        {
            return false;
        }
    }
    return true;
}

void loadUsersFromFile()            // Function to load users from a CSV file
{
    ifstream infile("user_data.csv");
    if (!infile.is_open())
    {
        return;
    }

    string line;
    while (getline(infile, line))
    {
        stringstream ss(line);
        string username, password;
        int lastCompletedLevel;

        getline(ss, username, ','); // Read username until the comma
        getline(ss, password, ','); // Read password until the comma
        ss >> lastCompletedLevel;   // Read the last completed level

        users[username] = {password, lastCompletedLevel};
    }

    infile.close();
}

// Function to save users to a CSV file
void saveUsersToFile()
{
    ofstream outfile("user_data.csv");
    for (const auto &user : users)
    {
        outfile << user.first << "," << user.second.first << "," << user.second.second << "\n";
    }
    outfile.close();
}

void userAuthentication(bool &isAuthenticated, string &username, int &lastCompletedLevel)
{
    loadUsersFromFile(); // Load users from CSV file

    int choice;
    cout << "\n----------------------------------------------+---------------------------------------------\n";
    cout << "------------------------------------+ LOGIN FOR PLAYERS +-----------------------------------\n";
    cout << "----------------------------------------------+---------------------------------------------\n\n";
    cout << "                                         1. LOG IN\n";
    cout << "                                         2. SIGN UP\n";
    cout << "                                     ENTER YOUR CHOICE :- ";
    cin >> choice;

    if (choice == 1)
    {
        // Log In
        cout << "\n----------------------------------------------+---------------------------------------------\n\n";
        cout << "                                     ENTER USERNAME :- ";
        cin >> username;
        cout << "                                     ENTER PASSWORD :- ";
        string password;
        cin >> password;
        cout << "\n----------------------------------------------+---------------------------------------------\n\n";

        
        if (users.find(username) != users.end() && users[username].first == password)       // Authenticate user
        {
            isAuthenticated = true;
            lastCompletedLevel = users[username].second;                                   // Get the last completed level
            cout << "                                      HELLO AGAIN , " << username << " !\n";
            cout << "\n----------------------------------------------+---------------------------------------------\n";
        }
        else
        {
            cout << "                                 INVALID USERNAME OR PASSWORD!\n";
            isAuthenticated = false;
        }
    }
    else if (choice == 2)
    {
        cout << "\n----------------------------------------------+---------------------------------------------\n\n";

        // Sign Up
       while (true)
    {
        cout << "                                 ENTER A NEW USERNAME :- ";
        cin >> username;

        if (isValidUsername(username))
        {
            break;                            
        }
        else
        {
            cout << "    INVALID USERNAME. USERNAME MUST BE AT LEAST 4 LETTERS AND CONTAIN ONLY ALPHABETS.\n";
            cout << "\n----------------------------------------------+---------------------------------------------\n\n";
        }
    }
        if (users.find(username) != users.end())
        {
            cout << "                       USERNAME ALREADY EXISTS. PLEASE TRY LOGGING IN.\n";
            isAuthenticated = false;
            return;
        }
    

        cout << "                                 ENTER THE PASSWORD :- ";
        string password;
        cin >> password;

        // Register new user
        users[username] = {password, 0};                           // Set the initial level to 0 for new users
        lastCompletedLevel = 0;
        isAuthenticated = true;
        cout << "\n----------------------------------------------+---------------------------------------------\n\n";
        cout << "                                  AN ACCOUNT HAS BEEN CREATED !\n";
        cout << "\n----------------------------------------------+---------------------------------------------\n";

        saveUsersToFile(); 
    }
    else
    {
        cout << "\n----------------------------------------------+---------------------------------------------\n\n";
        cout << "                                    INVALID CHOICE. EXITING ...\n";
        cout << "\n----------------------------------------------+---------------------------------------------\n";
        isAuthenticated = false;
    }
}

// Function to save user progress
void saveUserProgress(const string &username, int lastCompletedLevel)
{
    if (users.find(username) != users.end())
    {
        users[username].second = lastCompletedLevel; // Update the last completed level
        saveUsersToFile();                           // Save the updated user data to the CSV file
    }
}

// Function to load user progress
void loadUserProgress(const string &username, int &lastCompletedLevel)
{
    if (users.find(username) != users.end())
    {
        lastCompletedLevel = users[username].second; // Get the last completed level
    }
    else
    {
        lastCompletedLevel = 0; // Default to level 0 if user not found
    }
}

void displayLeaderboard()
{
    vector<pair<string, int>> leaderboard;
    for (const auto &user : users)
    {
        leaderboard.emplace_back(user.first, user.second.second); // <username, lastCompletedLevel>
    }

    // Sort the leaderboard in descending order based on levels completed
    sort(leaderboard.begin(), leaderboard.end(), [](const auto &a, const auto &b)
         {
             return a.second > b.second;
         });

    cout << "\n----------------------------------------------+---------------------------------------------\n";
    cout << "----------------------------------------+ LEADERBOARD +-------------------------------------\n";
    cout << "----------------------------------------------+---------------------------------------------\n\n";

    cout << "----------------------------------------\n";
    cout << left << setw(20) << "USER" << setw(20) << "LEVEL COMPLETED" << endl;
    cout << "----------------------------------------\n";

    for (const auto &entry : leaderboard)
    {
        cout << left << setw(20) << entry.first << setw(20) << entry.second << endl;
    }

    cout << "----------------------------------------\n";
    cout << "\n----------------------------------------------+---------------------------------------------\n";
}