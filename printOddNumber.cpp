//
//  printOddNumber.cpp
//  interview
//
//  Created by Edison on 10/26/14.
//  Copyright (c) 2014 edison. All rights reserved.
//

#include "printOddNumber.h"
#include <iostream>

void printOddNumber(int n){
    for(int i=1;i<=n;i++){
        if(i%2 == 0){
            continue;
        }
        else{
            std::cout<<i<<std::endl;
        }
    }
}
