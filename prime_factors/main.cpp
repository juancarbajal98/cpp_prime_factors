//
//  main.cpp
//  prime_factors
//
//  Created by Juan Carbajal on 11/7/20.
//  Copyright © 2020 Juan Carbajal. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

// recursive helper function in charge of factoring individual numbers
string factor(int current){
    string output = "";
    // start by checking for as many factors of two as possible
    while (current % 2 == 0){
        output += "2 x ";
        current = current / 2;
    }
    
    // check every next factor
    for(int i = 3; i <=sqrt(current); i+=2){
        while (current % i == 0)
        {
            output += (to_string(i) + " x ");
            current  = current / i;
        }
        
    }
    
    // here is the case for the LAST factor
    if(current > 2){
        
        // in this case we have previous factors inside of output, so our current is storing the last factor to add
        if(output != ""){
            output += (to_string(current));
        }
        
        // in this case that output IS empty then we know to have a prime number
        else {output += "prime!";}
    }
    
    // gets rid of trailing "x " from output strings to that every factorization ends with its last number
    if(output.substr(output.length()-1,1) == " "){
        output = output.substr(0,output.length()-2);
    }
    return output;
}

// function that takes in range of ints and returns their factors as a string
// @param l - lower bound
// @param u - upper bound
string factorizeRange(int l,int u){
    // string to maintain output as we iterate through range
    string output = "";
    int iter = l;
    while(iter <= u){
        // on each iterable we call recursive factor method that returns
        // factor string
        output += to_string(iter) + ": " + factor(iter) +"\n";
        iter++;
    }
    
    return output;
}

int main() {
    // declare ints to store user input
    int lower = 0, upper=0;
    // ask for input
    cout << "Enter a range of numbers to factorize. Enter lower and upper bounds separated by a space: ";
    cin >> lower >> upper ;
    
    // function that returns output string
    cout << factorizeRange(lower,upper);
    return 0;
}
