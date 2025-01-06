#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
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

    // for(int i = 0; i < 18; i++){
    //     for(int j = 1; j < rows; j++){
    //         ScoreCard[i][j] = "\t";
    //     }
    // }
}

#endif