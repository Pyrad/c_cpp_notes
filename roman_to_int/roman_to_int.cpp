#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>
#include<string>
#include<vector>

#include "../common_utils.hpp"

void print_array(int *a, int s) {
	for(int i = 0; i < s; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

namespace CU = common_utils;

int vmap(const char& c) {
    int res = 0;
    switch(c) {
        case 'I': res = 1; break;
        case 'V': res = 5; break;
        case 'X': res = 10; break;
        case 'L': res = 50; break;
        case 'C': res = 100; break;
        case 'D': res = 500; break;
        case 'M': res = 1000; break;
        default: res = 0; break;
    }

    return res;
}

int roman_to_int(const std::string& s) {
    int res = 0;
    for(size_t i = 0; i < s.size(); i++) {
        if((i != 0) && (vmap(s[i]) > vmap(s[i - 1]))) {
            res += vmap(s[i]) - 2 * vmap(s[i - 1]);
        } else {
            res += vmap(s[i]);
        }
    }

    return res;
}

int main()
{
    const int num = 14;
    // int test[num] = {1, 5, 7, 9, 10, 23, 49, 50, 51, 89, 228, 1832, 2285, 3331};
    std::string ss[num] = { "I", "V", "VII", "IX", "X", "XXIII", "XLIX", 
                            "L", "LI", "LXXXIX", "CCXXVIII", "MDCCCXXXII", "MMCCLXXXV", "MMMCCCXXXI"};

    for(int i = 0; i < num; i++) {
        std::cout << "Roman number string " << ss[i] << " convert to int: " << roman_to_int(ss[i]) << std::endl;
    }

    return 0;
}

