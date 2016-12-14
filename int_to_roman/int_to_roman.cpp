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

std::string int_to_roman(int d) {
    const int n = 13;
    const int radix[n] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const std::string roman[n] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    std::string res;
    for(int i = 0; i < n; i++) {
        int cnt = d / radix[i];
        for(; cnt > 0; cnt--) {
            res += roman[i];
        }
        d = d % radix[i];
    }

    return res;
}



int main()
{
    const int num = 14;
    // std::vector<int> test = {1, 5, 7, 9, 10, 23, 49, 50, 51, 89, 228, 1832, 2285, 3331};
    int test[num] = {1, 5, 7, 9, 10, 23, 49, 50, 51, 89, 228, 1832, 2285, 3331};

    for(int i = 0; i < num; i++) {
        std::cout << "Convert number " << test[i] << " to Roman: " << int_to_roman(test[i]) << std::endl;
    }

    /*
    int number = 10;
    std::cout << "Convert number " << number << " to Roman: " << int_to_roman(number) << std::endl;

    number = 49;
    std::cout << "Convert number " << number << " to Roman: " << int_to_roman(number) << std::endl;

    number = 49;
    std::cout << "Convert number " << number << " to Roman: " << int_to_roman(number) << std::endl;
    */

    return 0;
}

