//
//  Palindrome.cpp
//  interview
//
//  Created by Edison on 10/24/14.
//  Copyright (c) 2014 edison. All rights reserved.
//

#include "Palindrome.h"
#include <string>
#include <cctype>

bool isPalindrome(std::string word){
    size_t j = word.length()-1;
    for(int i=0;i<word.length()/2;i++){       //i index starts from the beginning of the word.
        while(!isalpha(word[i])){           //j index starts from the end of the word.
            i++;                            //if i and j contain the same letter, then check next
        }                                   //if not return false;
        while(!isalpha(word[j])){
            j--;
        }
        if(i>=j){
            break;
        }
        else{
            if(tolower(word[i])==tolower(word[j])){
                j--;
                continue;
            }
            else{
                return false;
            }
        }
    }
    return true;
}