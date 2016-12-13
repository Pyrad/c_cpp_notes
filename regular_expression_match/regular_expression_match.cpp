#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>

#include "../common_utils.hpp"

void print_array(int *a, int s) {
	for(int i = 0; i < s; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

namespace CU = common_utils;

bool reg_match(const char *s, const char *p) {
    if( *p == '\0' ) {
        return *s == '\0';
    }

    if( *(p + 1) != '*') {
        if( (*p == *s) || ((*p == '.') && (*s != '\0')) ) {
            return reg_match(s + 1, p + 1);
        } else {
            return false;
        }
    } 

    while( (*p == *s) || ((*p == '.') && (*s != '\0')) ) {
        if(reg_match(s, p + 2)) {
            return true;
        }
        s++;
    }

    return reg_match(s, p + 2);
}

int main()
{
    std::string str("abaaabcd");
    std::string pattern("aba*bcd");

    std::cout << "Pattern: " << pattern << ", string: " << str << std::endl;
    if(reg_match(str.c_str(), pattern.c_str())) {
        std::cout << "Matched: Yes" << std::endl;
    } else {
        std::cout << "Matched: False" << std::endl;
    }

    return 0;
}

