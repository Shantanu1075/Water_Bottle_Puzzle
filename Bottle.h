#ifndef BOTTLE_H
#define BOTTLE_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

class Bottle
{
public:
    vector<char> colors;

    bool isFull() const;
    bool isEmpty() const;
    char top() const;
    void pop(int count = 1);
    void push(char color);
    bool canPourInto(const Bottle &other) const;
    bool isSorted() const;
    bool isFullySorted() const;
    int pourableCount() const;
    string getColorCode(char color) const;
    string displayRow(int row) const;
};

void displayBottles(const vector<Bottle> &bottles);
bool isGameCompleted(const vector<Bottle> &bottles);
string stateToString(const vector<Bottle> &bottles);
bool moveWater(vector<Bottle> &bottles, int from, int to);
bool solvePuzzle(vector<Bottle> &bottles, set<string> &visitedStates, vector<pair<int, int>> &solution, int &moveCount);
void manualSolve(vector<Bottle> &bottles, set<string> &visitedStates, vector<pair<int, int>> &solution, int &moveCount);
void displayColorOptions();

#endif
