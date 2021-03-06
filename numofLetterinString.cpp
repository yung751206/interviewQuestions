//
//  numofLetterinString.cpp
//  interview
//
//  Created by Edison on 10/24/14.
//  Copyright (c) 2014 edison. All rights reserved.
//

#include "numofLetterinString.h"
#include <iostream>
#include <string>

void printNumofLetterinString(std::string sentence,int frequencyArray[26]){
    for(int i=0;i<26;i++){
        frequencyArray[i] = 0;
    }
    int ascii;
    for(int i=0;i<sentence.length();i++){
        if(!isalpha(sentence[i])){
            continue;
        }
        ascii = tolower(sentence[i]) - 'a';
        frequencyArray[ascii]++;
    }
    for(int i=0;i<26;i++){
        
        int max = frequencyArray[0];            
        int index = 0;
        for(int j=0;j<26;j++){
            if(frequencyArray[j] > max){
                max = frequencyArray[j];
                index = j;
            }
        }
        if(max == 0){
            break;
        }
        char c = index + 'a';
        std::cout<<c<<" "<<max<<std::endl;
        frequencyArray[index] = 0;
    }
}