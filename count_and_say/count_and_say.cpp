#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>
#include<string>
#include<vector>
#include<sstream>

#include "../common_utils.hpp"

void print_array(int *a, int s) {
	for(int i = 0; i < s; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

namespace CU = common_utils;

std::string get_next(const std::string& s) {
    std::stringstream ss;
    size_t i = 0; 
    while(i < s.size()) {
        int j = i;
        while( (i < s.size() - 1) && (s[i] == s[i + 1]) ) {
            i++;
        }
        j = i - j + 1;
        ss << j << s[i++];
    }

    return ss.str();
}

std::string kth_count_and_say(const int& k, int iv = 1) {
    // iv is initial value
    if(k <= 0) {
        return std::string("-1");
    }
    std::stringstream sstr;
    sstr << iv;
    if(k == 1) {
        return sstr.str();
    }
    int cnt = k;
    std::string res(sstr.str());
    std::cout << k - cnt + 1 << ". " << res << std::endl;
    while(--cnt) {
        res = get_next(res);
        std::cout << k - cnt + 1 << ". " << res << std::endl;
    }


    return res;
}

int main()
{
    const int init = 1;
    int kth = 10;
    std::cout << "Initial value of count & say string is: " << init << std::endl;
    std::string kv = kth_count_and_say(kth, init);
    std::cout << "Kth(No."<< kth << ") count & say string is: " << kv << std::endl;

    return 0;
}

