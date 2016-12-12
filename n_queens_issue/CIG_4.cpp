//============================================================================
// Name        : CIG_4.cpp
// Author      : Pyrad
// Version     :
// Copyright   : Pyrad
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>

#include "CIG_4.hpp"

namespace CIG_4 {

void n_queens_issue::execute() {
	if( get_queen_num() < 1) {
		std::cout << "No solution for queen number: " << get_queen_num() << std::endl;
		return ;
	}
    int* records = new int[get_queen_num()];
    int result = process(0, records, get_queen_num());
    delete [] records;

    std::cout << "All possible ways for " << get_queen_num() << " issue is: " << result << std::endl;
}

void n_queens_issue::execute(int num) {
    	if( num < 1) {
    		std::cout << "No solution for queen number: " << num << std::endl;
    		return ;
    	}
        int *records = new int[num];
        int result = process(0, records, num);
        delete [] records;

        std::cout << "All possible ways for " << num << " issue is: " << result << std::endl;
}

bool n_queens_issue::is_valid(int row, int col, int* records) {
    for(int k = 0; k < row; k++) {
        if(records[k] == col) {
            return false;
        }
        if(abs(row - k) == abs(col - records[k])) {
            return false;
        }
    }
    return true;
}

int n_queens_issue::process(int i, int* records, int len) {
    if(i == len) {
        return 1;
    }
    int res = 0;
    for(int j = 0; j < len; j++) {
        if(is_valid(i, j, records)) {
            records[i] = j;
            res += process(i+1, records, len);
        }
    }
    return res;
}

}
