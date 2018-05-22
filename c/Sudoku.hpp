//
//  Sudoku.hpp
//  c++
//
//  Created by Enrique Avina on 5/20/18.
//  Copyright © 2018 Enrique Avina. All rights reserved.
//

#ifndef Sudoku_hpp
#define Sudoku_hpp

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define NUM_SECONDS 10

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Parser.hpp"

class Sudoku {
public:
    Sudoku();
    void startGame();
    void setColor(int value);
    int row, column, chosenLevel;
    string* level;
    bool gameFinished, quit;
    string quitString;
private:
    Parser parser;
    char move;
    int difficulty, count, points; // 0 = easy, 1 = medium, 2 = hard
    void printBoard(); // prints out the current board
    void chooseMove(); // allows you to pick your next move};
    bool moveVerified(int row, int column, int move); // verifies move
    void initializeGame();
    void endScreen();
    void isGameOver();
    double timeCounter;
};

#endif /* Sudoku_hpp */
