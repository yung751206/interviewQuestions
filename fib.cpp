//
//  fib.cpp
//  interview
//
//  Created by Edison on 10/25/14.
//  Copyright (c) 2014 edison. All rights reserved.
//

#include "fib.h"

long int fib(long int n){
    long int *A = new long int[n];
    for(int i=0;i<n;i++){
        A[i] = 0;
    }
    return fibHelper(n, A);
}


long int fibHelper(long int n,long int*A){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(A[n]!=0){
        return A[n];
    }
    else{
        A[n] = fibHelper(n-1,A)+fibHelper(n-2,A);
    }
    return A[n];
}

