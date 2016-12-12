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

}
