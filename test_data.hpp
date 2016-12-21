#ifndef _TEST_DATA_HPP
#define _TEST_DATA_HPP

#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>

namespace test_data {

    //  the tree below showed in the array
    //                       0
    //                       |
    //                  ------------
    //                  |          |
    //                  1          2
    //                  |          |
    //              --------     -------- 
    //              |      |     |      |
    //              3      4     5      6
    //              |      |     |      |
    //            -----  ----- -----  ------
    //            |   |  |   | |   |  |    |
    //            7   8  9  10 11 12  13  14

    const int num = 15;
    const int tnodes[num] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    // To compare with golden to see if any errors
    const int golden_pre_order[num] = {0, 1, 3, 7, 8, 4, 9, 10, 2, 5, 11, 12, 6, 13, 14};
    const int golden_in_order[num] = {7, 3, 8, 1, 9, 4, 10, 0, 11, 5, 12, 2, 13, 6, 14};
    const int golden_post_order[num] = {7, 8, 3, 9, 10, 4, 1, 11, 12, 5, 13, 14, 6, 2, 0};


    // Some arrays for testing
    const int test_array_1_size = 15;
    const int test_array_1[test_array_1_size] = {67, -2, 55, -51, 41, 98, 21, -36, -48, 37, -39, 47, -33, -84, -21};

    const int test_array_2_size = 10;
    const int test_array_2[test_array_2_size] = {-55, -51, 41, -98, 21, 36, 48, -37, -39, 47};

} // namespace test_data


#endif // _TEST_DATA_HPP
