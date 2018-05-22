//
//  Parser.cpp
//  c++
//
//  Created by Enrique Avina on 5/20/18.
//  Copyright © 2018 Enrique Avina. All rights reserved.
//

#include "Parser.hpp"

Parser::Parser(){
    srand(time(NULL));
    level = row = chosenLevel = 0;
    
    /* Initialize Level Array */
    inputFile.open("/Users/enriqueavina/Desktop/c++/c++/levels.txt");
    while(!inputFile.eof()){
        getline(inputFile, line); // temporarily store every line
        if (line.length() == 22) { // regular line
            removeCharsFromString(line, " |"); // strip pipe and space characters
            levels[level][row] = line;
            row++;
            
            if (row % 9 == 0){
                level++;
                row = 0;
            }
        }
    }
    row = 0;
    /* Finish Initializing Level Array */
    
    
    /* Ask for diffulty */
    cout << "What difficulty would you like to play?\nSuper Easy - 0\nEasy - 1\nMedium - 2\nHard - 3\nPlease enter a number: ";
    cin >> chosenLevel;
    
    chosenLevel = pickRandomBoard(chosenLevel);

}



string* Parser::getLevelArray(){
    string *strPointers[9];
    for (int i = 0; i < 9; i++) {
        strPointers[i] = NULL;
    }
    
    for (int i = 0; i < 9; i++){
        strPointers[i] = &levels[chosenLevel][i];
        // cout << &strPointers[i] << endl;
    }
    
   // cout << *strPointers[0] << endl;
    
   // for (int i = 0; i < 9; i++) {
   //     cout << *strPointers[i] << endl;
   // }
    
    return *strPointers;
}

int Parser::getLevel(){
    return chosenLevel;
}

void Parser::removeCharsFromString(string &str, char *charsToRemove){
    for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
        str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
    }
}

bool Parser::checkIfArrayFull(string array[40][9]){
    for (int i = 0; i < 40; i++){
        for (int j = 0; i < 9; i++){
            if (array[i][j].length()==0){
                return false;
            }
        }
    }
    return true;
}

int Parser::pickRandomBoard(int difficulty){
    return rand() % 10 + difficulty*10; //(((difficulty*10 + 5)/10)*10); // add a random number between 0 and 9 to the closest difficulty
}

