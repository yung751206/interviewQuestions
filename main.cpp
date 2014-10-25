//
//  main.cpp
//  interview
//
//  Created by Edison on 10/24/14.
//  Copyright (c) 2014 edison. All rights reserved.
//

#include <iostream>
#include "reverseString.h"

int main(int argc, const char * argv[]) {
    std::string word;
    getline(std::cin,word);
    reverseString(word);
    std::cout<<word<<std::endl;
    return 0;
}
