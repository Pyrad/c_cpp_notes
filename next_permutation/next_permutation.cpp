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


/*
 * Steps,
 * 1. From right to left, find the first one element which is less than or
 *    equal to the one on the right hand next to it. Say the index is 'pivot'
 * 2. From right to left, find the first one which is bigger than the pivot
 *    Say it 'change'
 * 3. Swap the value of 'pivot' and 'change'
 * 4. Reverse the elements on the right side of 'pivot'
 *
 */

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

bool next_permutation(std::vector<int>& ivec) {
    int pivot;
    for(pivot = ivec.size() - 2; pivot != -1; pivot--) {
        if(ivec[pivot] <= ivec[pivot + 1]) {
            break;
        }
    }
    if(pivot == -1) {
        // This permutation is already the last one of all
        return false;
    }

    int change;
    for(change = ivec.size() - 1; change != -1; change--) {
        if(ivec[change] > ivec[pivot]) {
            break;
        }
    }
    // std::swap(ivec[pivot], ivec[change]);
    swap(ivec[pivot], ivec[change]);
    std::reverse(ivec.begin() + pivot + 1, ivec.end());

    return true;
}

void print_all_permutations(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
    int cnt = 0;
    do {
        printf("%d: ", ++cnt);
        CU::print_int_vector(vec);
    } while(next_permutation(vec));
}

int main()
{
    std::vector<int> permutation;
    const int num = 4;
    for(int i = 0; i < num; i++) {
        permutation.push_back(i + 1);
    }

#if 0
    printf("Permuation before\n");
    CU::print_int_vector(permutation);
    printf("\n");

    next_permutation(permutation);
    printf("Permuation After\n");
    CU::print_int_vector(permutation);
#endif

    printf("Original array for permutation: ");
    CU::print_int_vector(permutation);
    printf("\n");

    printf("All permuations\n");
    print_all_permutations(permutation);

    return 0;
}

