#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <algorithm>
using namespace std;

void printScorecard(vector<vector<string>> ScoreCard, int rows){
    for(int i = 0; i < 18; i++){
        for(int j = 0; j < rows; j++){
            if(ScoreCard[i][j].length() < 5){
                cout << "| " << ScoreCard[i][j] << " \t\t";
            }
            else{
                cout << "| " << ScoreCard[i][j] << " \t";
            }
        }
        cout << "|" << endl ;
    }
}

void SetupScorecard(vector<vector<string>>& ScoreCard, int rows){
    ScoreCard[0][0] = "YAHTZEE!!";
    ScoreCard[1][0] = "1s: \t";
    ScoreCard[2][0] = "2s: \t";
    ScoreCard[3][0] = "3s: \t";
    ScoreCard[4][0] = "4s: \t";
    ScoreCard[5][0] = "5s: \t";
    ScoreCard[6][0] = "6s: \t";
    ScoreCard[7][0] = "Bonus: ";
    ScoreCard[8][0] = "Up Tot: ";
    ScoreCard[9][0] = "3 of Kind: ";
    ScoreCard[10][0] = "4 of Kind: ";
    ScoreCard[11][0] = "Full House: ";
    ScoreCard[12][0] = "Small Str: ";
    ScoreCard[13][0] = "Large Str: ";
    ScoreCard[14][0] = "Yahtzee: ";
    ScoreCard[15][0] = "Chance: ";
    ScoreCard[16][0] = "Low Tot: ";
    ScoreCard[17][0] = "Total: ";
}

int RollDice(){
    
    int randomNum = rand() % 6 + 1;
    return randomNum;
}

void printDice(int dieFace){

    switch(dieFace){
        case 1:
        cout << " _____" << endl;
        cout << "|     |" << endl;
        cout << "|  *  |" << endl;
        cout << "|_____|" << endl;
        break;

        case 2:
        cout << " _____" << endl;
        cout << "|    *|" << endl;
        cout << "|     |" << endl;
        cout << "|*____|" << endl;
        break;

        case 3:
        cout << " _____" << endl;
        cout << "|    *|" << endl;
        cout << "|  *  |" << endl;
        cout << "|*____|" << endl;
        break;

        case 4:
        cout << " _____" << endl;
        cout << "|*   *|" << endl;
        cout << "|     |" << endl;
        cout << "|*___*|" << endl;
        break;

        case 5:
        cout << " _____" << endl;
        cout << "|*   *|" << endl;
        cout << "|  *  |" << endl;
        cout << "|*___*|" << endl;
        break;

        case 6:
        cout << " _____" << endl;
        cout << "|*   *|" << endl;
        cout << "|*   *|" << endl;
        cout << "|*___*|" << endl;
        break;

        default:
        break;
    };
}

void turn(){
    int NumRolls = 0;
    int userFinalDice[5] = {0};
    int RollResults[5] = {0};
    string DiceKept = "";
    string unsavedDice = "12345";

    while(NumRolls < 3){
        
        for(int i = 0; i < (5 - DiceKept.length()); i++){
            cout << "unsaved Dice: " << unsavedDice << endl;

            RollResults[((int)unsavedDice[i] - 49)] = RollDice();

        }
        for(int i = 0; i < 5; i++){
            printDice(RollResults[i]);
        }
            unsavedDice = "12345";
            cout << "Which dice would you like to keep?" << endl;
            cout << "EX: 145" << endl;
            cin >> DiceKept;
            cout << "Dice kept: " << DiceKept << endl;
            for(int i = 0; i < DiceKept.length(); i++){
                unsavedDice.erase(remove(unsavedDice.begin(), unsavedDice.end(), DiceKept[i]), unsavedDice.end());
            }
            NumRolls++;
            
    }
}

#endif


//  _____
// |     |
// |  *  |             
// |_____| 

//  _____
// |    *|
// |     |
// |*____|

//  _____
// |    *|
// |  *  |
// |*____|

//  _____
// |*   *|
// |     |
// |*___*|

//  _____
// |*   *|
// |  *  |
// |*___*|

//  _____
// |*   *|
// |*   *|
// |*___*|