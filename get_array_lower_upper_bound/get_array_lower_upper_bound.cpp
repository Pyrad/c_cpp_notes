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


// Get the lower bound of a target value in an array
// return -1 If not found
int get_lower_bound(const int* arr, const int& size, const int& value) {
    assert(size > 0);
    int start = 0;
    int end = size - 1;
    while(start != end) {
        int mid = (start + end) / 2;
        if(value > arr[mid]) {
            start = mid + 1;
        } else { // value <= arr[mid]
            end = mid;
        }
    }

    if(start < 0 || arr[start] != value) {// Check if value is found
        return -1;
    } else {
        return start;
    }
}

// Get the upper bound of a target value in an array
// return -1 If not found
int get_upper_bound(const int* arr, const int& size, const int& value) {
    assert(size > 0);
    int start = 0;
    int end = size - 1;
    while(start != end) {
        int mid = (start + end) / 2;
        if(value >= arr[mid]) {        // The only different place compared with 'get_lower_bound'
            start = mid + 1;
        } else { // value < arr[mid]
            end = mid;
        }
    }


    if((start == size - 1) && (arr[start] == value)) {
        return start;
    } else if((start > 0) && (arr[start - 1] == value) ) {
        return start - 1;
    } else {
        return -1;
    }
}

int main()
{
    std::vector<int> ivec(TD::test_array_3, TD::test_array_3 + TD::test_array_3_size);
    std::sort(ivec.begin(), ivec.end());
    int *arr = new int[TD::test_array_3_size];
    int *p = arr;
    for(std::vector<int>::iterator itr = ivec.begin(); itr != ivec.end(); itr++, p++) {
        *p = *itr;
    }

    printf("Test array is:\n");
    CU::print_array(arr, TD::test_array_3_size);

    const int t_num = 6;
    int target_value[t_num] = {6, 199, -55, 38, 41, -98};
    for(int i = 0; i < t_num; i++) {
        int v = target_value[i];
        int lower_bound = get_lower_bound(arr, TD::test_array_3_size, v);
        int upper_bound = get_upper_bound(arr, TD::test_array_3_size, v);
        printf("The lower & upper bound of value %d is : %d & %d\n", v, lower_bound, upper_bound);
    }

    delete [] arr;

    return 0;
}

