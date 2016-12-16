#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>

namespace common_utils {

void print_array(const int *a, int s) {
	for(int i = 0; i < s; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void print_string_vector(const std::vector<std::string>& svec) {
    for(std::vector<std::string>::const_iterator itr = svec.begin(); itr < svec.end(); itr++) {
        std::cout << *itr << " ";
    }
	std::cout << std::endl;
}

}
