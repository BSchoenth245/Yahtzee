#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Functions.h"
using namespace std;


int main(){
    srand(std::time(0));
    int players;
    cout << "Enter the number of players: ";
    cin >> players;
    int rows = players + 1;

    vector<vector<string>> ScoreCard;
    ScoreCard.resize(18, vector<string>(rows));

    SetupScorecard(ScoreCard, rows);

    for(int i = 0; i < players; i++){
        cout << "What is the name of player " << i + 1 << "?" << endl;
        cin >> ScoreCard[0][i + 1];
    }
    cout << endl << endl;
    printScorecard(ScoreCard, rows);

    int Die1 = RollDice();
    int Die2 = RollDice();
    int Die3 = RollDice();
    int Die4 = RollDice();
    int Die5 = RollDice();

    cout << Die1 << endl << Die2 << endl << Die3 << endl << Die4 << endl << Die5 << endl;

    return 0;
}