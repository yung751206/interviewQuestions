//
//  sumUpIntegerFromFile.cpp
//  interview
//
//  Created by Edison on 10/25/14.
//  Copyright (c) 2014 edison. All rights reserved.
//

#include "sumUpIntegerFromFile.h"
#include <string>
#include <fstream>
#include <iostream>

int sumUpIntegerFromFile(std::string fileName){
    std::ifstream input;
    std::string line;
    int result = 0;
    input.open(fileName);
    while(getline(input,line)){
        result += stoi(line);
    }
    input.close();
    return result;
}