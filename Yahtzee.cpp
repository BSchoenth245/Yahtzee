#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Functions.h"
using namespace std;


int main(){
    srand(std::time(0));
    int userDice[5] = {0};
    int players;
    cout << "Enter the number of players: ";
    cin >> players;
    int rows = players + 1;


    vector< vector<string> > ScoreCard;
    ScoreCard.resize(18);  // resize top level vector
    for (int i = 0; i < 18; i++)
     {
    ScoreCard[i].resize(rows);  // resize each of the contained vectors
    for (int j = 0; j < rows; j++)
    {
        ScoreCard[i][j] = " ";
    }
}

    SetupScorecard(ScoreCard, rows);

    for(int i = 0; i < players; i++){
        cout << "What is the name of player " << i + 1 << "?" << endl;
        cin >> ScoreCard[0][i + 1];
    }
    cout << endl << endl;
    printScorecard(ScoreCard, rows);
    cout << endl << endl << endl;

    turn(userDice);

    // for(int i = 0; i < 5; i++){
    //     cout << userDice[i];
    // }

    ScoreCard = scoring(userDice, ScoreCard, rows);
    //cout << ScoreCard[1][1] << endl;
    printScorecard(ScoreCard, rows);

    return 0;
}