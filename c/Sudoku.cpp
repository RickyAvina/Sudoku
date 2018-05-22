//
//  Sudoku.cpp
//  c++
//
//  Created by Enrique Avina on 5/20/18.
//  Copyright © 2018 Enrique Avina. All rights reserved.
//

#include "Sudoku.hpp"

Sudoku::Sudoku(){
    initializeGame();
}

void Sudoku::initializeGame(){
    gameFinished = quit = false;
    move = 0;
    points = 0;
    chosenLevel = parser.getLevel();
    level = parser.getLevelArray();
    
    timeCounter = 0;
    
    startGame();
}

void Sudoku::startGame(){
    while(!gameFinished || !quit){
        isGameOver();
        if (!gameFinished){
            chooseMove();
        }
    }
    
    endScreen();
    cout << "Do you wanna play again?(1-yes 0-no):";
    cin >> quitString;
    if (quitString == "0"){
        exit(0);
    } else {
        initializeGame();
    }
}

void Sudoku::isGameOver(){
    int count = 0;
    for (int i = 0; i < 9; i++){
        if (level[i].find('.') == string::npos){
            count++;
        }
    }
    if (count == 9){
        cout << "OVER" << endl;
        gameFinished = true;
    } else {
        count = 0;
    }
}

void Sudoku::chooseMove(){
    printBoard();
    
    cout << "Would you like to quit? (Type n to continue or any other key to quit): ";
    cin >> quitString;
    if ((quitString != "n") && (quitString != "N")){
        endScreen();
        exit(0);
    }
    cout << "Choose a row: ";
    cin >> row;
    //cout << endl;
    cout << "Choose a column: ";
    cin >> column;
   // cout << endl;
    cout << "What's your move? (1-9): ";
    cin >> move;
    
    if (moveVerified(row, column, move)){
        level[row][column] = move; // INSTEAD REPLACE CHAR
        points += 10;
    } else {
        while(timeCounter < 5){ // code for making the console flash when you make a bad move
            cout.flush();
           // system("clear"); // for Windows
            level[row][column] = move;
            printBoard();
            std::this_thread::sleep_for(std::chrono::milliseconds(800));
            level[row][column] = ' ';
            timeCounter++;
            printBoard();
            points -= 5;
        }
        cout << "INVALID MOVE" << endl;
    }
}

void Sudoku::endScreen(){
    cout << endl << endl;
    cout << "You finished with " << points << " points!" << endl;
    // play again
}

bool Sudoku::moveVerified(int row, int column, int move){
    //cout << level[row] << endl;
    if (isdigit(level[row][column])){
        cout << "SPACE TAKEN" << endl;
        return false;
    }
    if (level[row].find(move) != string::npos){
        cout << "Nope!" << endl;
        return false;
    }
    
    for (int r = 0; r < 9; r++){
        if (level[r][column] == move){
          return false;
        }
    }
    return true;
}

void Sudoku::printBoard(){
    for (int r = 0; r < 9; r++){
        if ((r%3==0)&&(r!=0)) cout << "---------|---------|-------- " << endl;

        for (int c = 0; c < 9; c++){
            if ((c%3==0) && (c!=0)){ cout << "|"; }
            if (level[r][c] == '.'){    // because text file includes . where there are blanks, I have to account for this
                cout << "   ";
            } else {  cout << " " << level[r][c] << " "; }
        }
        cout << "       " << r;
        cout << endl;
    }
    cout << endl << endl;
    cout << " 0  1  2   3  4  5   6  7  8" << endl << endl << endl; // should also be colored
}
