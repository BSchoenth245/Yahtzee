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
    for(int i = 1; i < 18; i++){
        for(int j = 1; j < rows; j++){
            ScoreCard[i][j] = "0";
        }
    }
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

void turn(int RollResults[]){
    int NumRolls = 0;
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

vector<vector<string>> scoring(int userFinalDice[], vector<vector<string>> ScoreCard, int player){
    int userChoice;
    int score = 0;

    cout << "How would you like to score your dice?(1-13)" << endl;
    cout << "1: 1s" << endl;
    cout << "2: 2s" << endl;
    cout << "3: 3s" << endl;
    cout << "4: 4s" << endl;
    cout << "5: 5s" << endl;
    cout << "6: 6s" << endl;
    cout << "7: 3 of a Kind" << endl;
    cout << "8: 4 of a Kind" << endl;
    cout << "9: Full House" << endl;
    cout << "10: Small Straight" << endl;
    cout << "11: Large Straight" << endl;
    cout << "12: YAHTZEE" << endl;
    cout << "13: Choice" << endl;
    cin >> userChoice;

    switch(userChoice){
        case 1:
            //cout << "Entered case 1" << endl;
            for(int i = 0; i < 5; i++){
                if(userFinalDice[i] == 1){
                    score += 1;
                }
                //cout << score << endl;
            }
            ScoreCard[1][1] = to_string(score);
            //cout << ScoreCard[1][1] << endl;
            break;
        case 2:
            //cout << "Entered case 2" << endl;
            for(int i = 0; i < 5; i++){
                if(userFinalDice[i] == 2){
                    score += 2;
                }
                //cout << score << endl;
            }
            ScoreCard[2][1] = to_string(score);
            //cout << ScoreCard[2][1] << endl;
            break;
        case 3:
            //cout << "Entered case 3" << endl;
            for(int i = 0; i < 5; i++){
                if(userFinalDice[i] == 3){
                    score += 3;
                }
                //cout << score << endl;
            }
            ScoreCard[3][1] = to_string(score);
            //cout << ScoreCard[3][1] << endl;
            break;
        case 4:
            //cout << "Entered case 4" << endl;
            for(int i = 0; i < 5; i++){
                if(userFinalDice[i] == 4){
                    score += 4;
                }
                //cout << score << endl;
            }
            ScoreCard[4][1] = to_string(score);
            //cout << ScoreCard[4][1] << endl;
            break;
        case 5:
            //cout << "Entered case 5" << endl;
            for(int i = 0; i < 5; i++){
                if(userFinalDice[i] == 5){
                    score += 5;
                }
                //cout << score << endl;
            }
            ScoreCard[5][1] = to_string(score);
            //cout << ScoreCard[5][1] << endl;
            break;
        case 6:
            //cout << "Entered case 6" << endl;
            for(int i = 0; i < 5; i++){
                if(userFinalDice[i] == 6){
                    score += 6;
                }
                //cout << score << endl;
            }
            ScoreCard[6][1] = to_string(score);
            //cout << ScoreCard[6][1] << endl;
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        default:
            break;
    };
return ScoreCard;
};

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