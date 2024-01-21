#include <iostream>
#include "AllFunctions.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    NonogramLevel levels[MAX_DIFFICULTY_LEVEL];
    loadLevels(levels);

   string username;
   cout << "Enter your username: ";
   cin >> username;

    UserProfile user;
    user.username = username;
    user.currentLevel = 1;
    bool newuser = true;
    //if (loadGame(user, MAX_SIZE)) 
    {
       cout << "Do you want to continue your last attempt? (Y/N): ";
        char choice;
       cin >> choice;
        newuser = false;

        if (choice == 'Y' || choice == 'y') {
            loadGame(user, MAX_SIZE);
            playGame(user, levels[user.currentLevel - 1], newuser);
        }
        else {
            user.currentLevel = 1;
            int difficultyChoice = getDifficultyChoice();
            playGame(user, levels[difficultyChoice - 1],newuser);
        }
    }
   /* else {
        user.currentLevel = 1;
        int difficultyChoice = getDifficultyChoice();
        playGame(user, levels[difficultyChoice - 1], newuser);
    }*/
	}
