#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>

#include "../common_utils.hpp"

namespace CU = common_utils;

int median(const int *a, int asize, const int *b, int bsize) {

    assert(asize == bsize);

    int s1 = 0, s2 = 0;
    int e1 = asize - 1, e2 = bsize - 1;
    int m1 = 0, m2 = 0;

    while(s1 < e1) {
        m1 = (s1 + e1) / 2;
        m2 = (s2 + e2) / 2;
        if(a[m1] == b[m2]) {
            return a[m1]; // or return b[m2];
        } else if(a[m1] > b[m2]) {
            if( (e1 - s1) % 2 == 0 ) { // even length
                e1 = m1;
                s2 = m2 + 1;
            } else { // odd length
                e1 = m1;
                s2 = m2;
            }
        } else { // a[m1] < b[m2]
            if( (e1 - s1) % 2 == 0 ) { // even length
                e2 = m2;
                s1 = m1 + 1;
            } else { // odd length
                e2 = m2;
                s1 = m1;
            }
        }
    }

    return std::min(a[s1], b[s2]);
}


int main()
{
    int m = -1;

    const int a[6] = {1, 2, 3, 4, 5, 6};
    const int b[6] = {3, 4, 5, 6, 7, 8};
    m = median(a, 6, b, 6);
    std::cout << "2 arrays" << std::endl;
    CU::print_array(a, 6);
    CU::print_array(b, 6);
    std::cout << "Median element is: " << m << std::endl;
    std::cout << std::endl;

    const int c[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    const int d[9] = {9, 10, 11, 12, 13, 14, 15, 16, 17};
    m = median(c, 9, d, 9);
    std::cout << "2 arrays" << std::endl;
    CU::print_array(c, 9);
    CU::print_array(d, 9);
    std::cout << "Median element is: " << m << std::endl;
    std::cout << std::endl;

    return 0;
}
