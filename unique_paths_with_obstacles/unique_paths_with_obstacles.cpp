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


int all_ways(const int& m, const int& n, int** map) {
    if(m <= 0 || n <= 0) {
        return -1; // No way if map is invalid
    }
    std::vector<int> vec(n, 0); // a vector contains zeros of n-column
    if(map[0][0] != 0 || map[m - 1][n - 1] != 0)  { // which means (0, 0) or (m-1, n-1) is placed with an obstalce
        return -1;
    }
    vec[0] = 1;
    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            if(map[r][c] != 0){
                vec[c] = 0;
            } else {
                if(c == 0) {
                    vec[c] = 0/*no way from left side*/ + vec[c];
                } else {
                    vec[c] = vec[c - 1]/*ways from left side*/ + vec[c];
                }
            }
        }
    }

    return vec[n - 1];
}


int main()
{
    int rows = 3;
    int cols = 3;

    // Create a matrix and put obstacles
    int* *m = new int*[rows];
    for(int i = 0; i < rows; i++) {
        m[i] = new int[cols];
    }
    // Put obstale(s)
    m[1][1] = 9;

    int possible_ways = all_ways(rows, cols, m);
    CU::print_matrix<int>(rows, cols, m);
    printf("---------\n");
    printf("All possible ways to walk from S(0, 0) to E(%d, %d): %d\n", rows - 1, cols - 1, possible_ways);

    // Release map
    for(int i = 0; i < rows; i++) {
        delete [] m[i];
    }
    delete [] m;

    return 0;
}

