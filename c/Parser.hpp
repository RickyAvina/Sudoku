//
//  Parser.hpp
//  c++
//
//  Created by Enrique Avina on 5/20/18.
//  Copyright © 2018 Enrique Avina. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <tuple>

using namespace std;

class Parser {
public:
    Parser();
    void removeCharsFromString(string &str, char* charsToRemove); // generic function to strip characters from a string
    string* getLevelArray();
    int getLevel();
private:
    ifstream inputFile; // The text file containing all of the sudoku levels
    string line; // to look through file line-by-line
    string levels[40][9]; // collection of levels in string form to allow for blank spaces. Dimensionality: 1 dimensional array: 9 to account for rowscontained within an encompassing 40 element array
    int level, row, chosenLevel; // used to keep track of array indices and difficulty
    bool checkIfArrayFull(string array[40][9]);
    int pickRandomBoard(int difficulty); // chooses a random baord of given difficulty
};

#endif /* Parser_hpp */
