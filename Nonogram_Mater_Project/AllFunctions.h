#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 20;
const int MAX_WRONG_ANSWERS = 3;
const int MAX_DIFFICULTY_LEVEL = 5;

struct UserProfile {
    string username;
    int currentLevel;
    int currentWrongAnswers;
    char currentGrid[MAX_SIZE][MAX_SIZE];
};

struct NonogramLevel {
    int size;
    int maxWrongAnswers;
    char picture[MAX_SIZE][MAX_SIZE];
};

void loadLevels(NonogramLevel levels[MAX_DIFFICULTY_LEVEL]) {
    levels[0].size = 5;
    levels[0].maxWrongAnswers = 3;
    char superEasy1[MAX_SIZE][MAX_SIZE] =
    {
        {'X', '-', 'X', '-', 'X'},
        {'X', '-', '-', '-', '-'},
        {'X', '-', '-', '-', '-'},
        {'X', '-', '-', '-', '-'},
        {'X', '-', '-', '-', '-'},
    };
    char superEasy2[MAX_SIZE][MAX_SIZE] =
    {
        {'-', '-', '-', '-', 'X'},
        {'X', '-', '-', '-', '-'},
        {'X', '-', '-', '-', '-'},
        {'X', '-', '-', '-', '-'},
        {'X', '-', '-', '-', '-'},
    };
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            int randomChoice = rand() % 2;

            levels[0].picture[i][j] = (randomChoice == 0) ? superEasy1[i][j] : superEasy2[i][j];
        }
    }

    levels[1].size = 5;
    levels[1].maxWrongAnswers = 3;
    char easy[MAX_SIZE][MAX_SIZE] =
    {
        {'X', '-', 'X', '-', 'X'},
        {'X', '-', 'X', '-', 'X'},
        {'X', '-', 'X', '-', 'X'},
        {'X', '-', 'X', '-', 'X'},
        {'X', '-', 'X', '-', 'X'},
    };
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            levels[1].picture[i][j] = easy[i][j];
        }
    }
}

bool areMatricesEqual(char grid[MAX_SIZE][MAX_SIZE], char picture[MAX_SIZE][MAX_SIZE], int size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (grid[i][j] != picture[i][j]) {
                return false;
            }
        }
    }
    cout << "Matrices are equal\n";
    return true;
}
void saveGame(UserProfile& user, int size) {
    ofstream file(user.username + "_save.txt");
    if (file.is_open()) {
        file << user.currentLevel << '\n';
        file << user.currentWrongAnswers << '\n';
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file << user.currentGrid[i][j] << ' ';
            }
            file << '\n';
        }
        file.close();
        cout << "Game saved successfully.\n";
    }
    else {
        cerr << "Unable to save the game.\n";
    }
}
