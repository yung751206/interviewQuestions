//
//  reverseString.cpp
//  interview
//
//  Created by Edison on 10/25/14.
//  Copyright (c) 2014 edison. All rights reserved.
//

#include "reverseString.h"
#include <string>
#include <algorithm>
#include <iostream>

void reverseString(std::string &word){
    for(int i=0;i<word.length()/2;i++){
        char temp = word[i];
        word[i] = word[word.length()-1-i];
        word[word.length()-1-i] = temp;
    }
}