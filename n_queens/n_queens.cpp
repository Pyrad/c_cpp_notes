#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>
#include<string>
#include<vector>
#include<sstream>
#include<stack>
#include<stdio.h>
#include<queue>

#include "../common_utils.hpp"
#include "../test_data.hpp"

// alias to namespaces
namespace CU = common_utils;
namespace TD = test_data;

// type definitions
typedef CU::node node;   // Binary tree node
typedef CU::snode snode; // Binary tree node with sibling
typedef CU::lnode lnode; // Linked list node

void print_n_queens_chessboard(int* rec, const int& n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(rec[i] == j) {
                printf("Q ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }

}

bool is_valid(const int& i, const int& j, int* rec) {
    for(int k = 0; k < i; k++) {
        if(rec[k] == j) { // if any column of rows of [0, i - 1] is placed a queen
            return false;
        }
        if(std::abs(i - k) == std::abs(j - rec[k])) { // diagonal
            return false;
        }
    }

    return true;
}

int n_queens(int row, int* rec, const int& n) {
    if(row == n) {
        print_n_queens_chessboard(rec, n);
        printf("----------\n");
        return 1;
    }

    int res = 0;
    for(int j = 0; j < n; j++) {
        if(is_valid(row, j, rec)) {
            rec[row] = j;
            res += n_queens(row + 1, rec, n);
            rec[row] = 0;
        }
    }

    return res;
}

int main()
{
    const int limits = 6;
    for(int num = 0; num < limits; num++) {
        int *records = new int[num];
        printf("All possible ways of placement for N=%d queen(s) issue\n", num);
        printf("---------------------------\n");
        int total = n_queens(0, records, num);
        printf("Total ways to place %d queen(s) in a chessboard of %dx%d\n", total, num, num);
        printf("\n");
        delete [] records;
    }
    return 0;
}

