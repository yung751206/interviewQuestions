//
//  printMultiplication12.cpp
//  interview
//
//  Created by Edison on 10/25/14.
//  Copyright (c) 2014 edison. All rights reserved.
//

#include "printMultiplication.h"
#include <iostream>
#include <iomanip>

void printMultiplication(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cout<<std::setw(4)<<(i+1)*(j+1)<<" ";
        }
        std::cout<<std::endl;
    }
}