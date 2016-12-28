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

int unique_paths(const int& m, const int& n) {
    if( m <= 0 || n <= 0) {
        printf("Invalid value m & n: %d, %d\n", m, n);
        return -1;
    }

    std::vector<int> vec(n, 1); // a n-element vector and each element is integer 1
    for(int i = 1; i < m; i++) {
        for(size_t j = 1; j < vec.size(); j++) {
            vec[j] = vec[j - 1] + vec[j];
        }
    }

    return vec[n - 1];
}

void print_sketch(int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if( (i == 0) && (j == 0) )  {
                printf("S ");
            } else if ((i == r - 1) && (j == c -1)) {
                printf("E (S -- > E)");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main()
{
    const int tnum = 5;
    int r[tnum] = {5,  1, 3, 2, 4};
    int c[tnum] = {10, 2, 7, 3, 8};


    printf("\nOnly east & south directions are allowed\n");
    printf("---------------\n");
    for(int k = 0; k < tnum; k++) {
        int uni_paths = unique_paths(r[k], c[k]);
        printf("Start from (0,0) and walk to (%d, %d) unique paths number: %d \n", r[k] - 1, c[k] - 1, uni_paths);
        print_sketch(r[k], c[k]);
        printf("\n");
    }

    return 0;
}

