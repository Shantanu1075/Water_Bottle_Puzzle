#ifndef USERDATA_H
#define USERDATA_H

#include <string>
#include <unordered_map>

void loadUsersFromFile();
void saveUsersToFile();
void userAuthentication(bool &isAuthenticated, std::string &username, int &lastCompletedLevel);
void saveUserProgress(const std::string &username, int lastCompletedLevel);
void loadUserProgress(const std::string &username, int &lastCompletedLevel);
void displayLeaderboard();

#endif
