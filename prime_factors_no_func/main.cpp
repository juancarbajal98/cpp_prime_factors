//
//  main.cpp
//  prime_factors_no_func
//
//  Created by TXT-52 on 11/7/20.
//  Copyright © 2020 Juan Carbajal. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
    // declare ints to store user input
    int lower = 0, upper=0;
    // ask for input
    cout << "Enter a range of numbers to factorize. Enter lower and upper bounds separated by a space: ";
    cin >> lower >> upper ;
    // vector of strings of size of range to manage a line for every # in range
    vector<string> output(upper-lower);
    vector<int> factorCounter(upper-lower);
    
    int current = lower;
    int counter = 0;
    
    while(current <= upper){
        for (int i=2; i<= current;i++){
            while(current % i == 0){
                // reduce current
                current /= i;
                // append another factor to the factor string for this index
                output[counter] += (to_string(i) +  " x ");
                // increment the factor count for this index
                factorCounter[counter]++;
            }
        }
        // increment counter
        counter++;
        // reset the current value with +1
        current = lower + counter;
    }
    
    for (int j =0;j<=output.size();j++){
        
        // changes text in prime factors by finding the strings of length 9 == strings with only one factor
        if (factorCounter[j] == 1){
            output[j] = "prime!";
        }
        
        // handles dangling " x "
        if(output[j].substr(output[j].length()-1,1) == " "){
            output[j] = output[j].substr(0,output[j].length()-2);
        }
        // print out numbers followed by their respective factor string
        cout << lower + j << " : " << output[j] << endl;
    }
    return 0;
}
