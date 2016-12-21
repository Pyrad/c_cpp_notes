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
typedef CU::node node;

int max_sub_seq_sum(const int *arr, const int& size, int& res_start, int& res_end) {
    if(!arr || size <= 0) {
        return INT_MIN;
    }

    int cur_sum = 0;
    int max_sum = INT_MIN;
    // res_start & res_end are used to record the range of max sub sequence
    res_start = 1;
    res_end = 1;
    for(int i = 0; i < size; i++) {
        cur_sum += arr[i];
        // max_sum = std::max(max_sum, cur_sum);
        if( max_sum < cur_sum) {
            max_sum = cur_sum;
            res_end = i; // index from 0
            res_end += 1; // index from 1
        }
        if(cur_sum < 0) {
            cur_sum = 0;
            res_start = i + 1; // index from 0
            res_start += 1; // index from 1
        }
    }

    return max_sum;
}

int main()
{
    std::cout << "Test array is " << std::endl;
    CU::print_array(TD::test_array_1, TD::test_array_1_size);

    int start = -1;
    int end = -1;
    int max = max_sub_seq_sum(TD::test_array_1, TD::test_array_1_size, start, end);
    std::cout << "Max sub sequence sum is: " << max << "(start from " << start << " to " << end << " )" << std::endl;

    std::cout << "Test array is " << std::endl;
    CU::print_array(TD::test_array_2, TD::test_array_2_size);
    max = max_sub_seq_sum(TD::test_array_2, TD::test_array_2_size, start, end);
    std::cout << "Max sub sequence sum is: " << max << "(start from " << start << " to " << end << " )" << std::endl;

    return 0;
}

