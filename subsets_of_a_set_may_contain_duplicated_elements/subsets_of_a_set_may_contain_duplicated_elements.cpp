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

// This fucntion works for arrays with duplicated elements inside
// but also works for those without duplicated elements
// So it works for both situations
std::vector<std::vector<int> >
subset(std::vector<int>& vec) {
    // Source array must be sorted first
    std::sort(vec.begin(), vec.end());
    // initial value, a vector contains an empty vector
    // which means empty is a subset of vec
    std::vector<std::vector<int> > result(1);

    size_t prev_size = 0;
    for(size_t i = 0; i < vec.size(); i++) {
        size_t cur_size = result.size();
        for(size_t j = 0; j < cur_size; j++) {
            if( i == 0 || vec[i] != vec[i - 1] || j >= prev_size) {
                result.push_back(result[j]);
                result.back().push_back(vec[i]);
            }
        }
        prev_size = cur_size;
    }

    return result;
}


int main()
{
    const int num = 4;
    const int arr1[num] = {1, 2, 3, 4};
    const int arr2[num] = {1, 2, 2, 3};

    std::vector<int> vec(arr1, arr1 + num);
    std::vector<std::vector<int> > res;
    res = subset(vec);
    printf("Array 1(WITHOUT duplicated elements) is: ");
    CU::print_vector<int>(vec);
    printf("All subsets are:\n");
    CU::print_vector_vector<int>(res);

    printf("\n--------separator--------\n\n");

    vec.clear();
    res.clear();
    vec.assign(arr2, arr2 + num);
    printf("Array 2(with duplicated elements) is: ");
    CU::print_vector<int>(vec);
    printf("All subsets are:\n");
    res = subset(vec);
    CU::print_vector_vector<int>(res);

    return 0;
}

