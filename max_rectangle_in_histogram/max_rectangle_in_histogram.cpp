#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>
#include<string>
#include<vector>
#include<sstream>
#include<stack>


#include "../common_utils.hpp"

void print_array(const int *a, int s) {
	for(int i = 0; i < s; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}


int max_rectangle_in_histogram(const int *h, int size) {

    std::stack<int> stk;

    int max_rect = 0;

    for(int i = 0; i < size; i++) {
        while(!stk.empty() && h[i] <= h[stk.top()]) {
            int height = h[stk.top()]; // expand this to left & right to form a rectangle
            stk.pop();
            int right = i - 1; // expand to left most
            int left = stk.empty() ? -1 : (stk.top() + 1); // expand to left most
            int cur_rect = height * (right - left + 1); // actually is "i - stk.top() - 1"
            max_rect = std::max(max_rect, cur_rect);
        }
        stk.push(i);
    }

    int last = size;

    while(!stk.empty()) {
        int height = h[stk.top()]; // expand this to left & right to form a rectangle
        stk.pop();
        int right = last - 1; // expand to left most
        int left = stk.empty() ? -1 : (stk.top() + 1); // expand to left most
        int cur_rect = height * (right - left + 1); // actually is "i - stk.top() - 1"
        max_rect = std::max(max_rect, cur_rect);
    }

    return max_rect;
}

int max_rectangle_in_histogram(std::vector<int>& ivec) {

    std::stack<int> stk;

    int max_rect = 0;

    ivec.push_back(0); // consider to pop all in the stack after the for-loop

    for(size_t i = 0; i < ivec.size(); i++) {
        while(!stk.empty() && ivec[i] <= ivec[stk.top()]) {
            int height = ivec[stk.top()]; // expand this to left & right to form a rectangle
            stk.pop();
            int right = i - 1; // expand to left most
            int left = stk.empty() ? -1 : (stk.top() + 1); // expand to left most
            int cur_rect = height * (right - left + 1); // actually is "i - stk.top() - 1"
            max_rect = std::max(max_rect, cur_rect);
        }
        stk.push(i);
    }

    return max_rect;
}



namespace CU = common_utils;

int main()
{
    const int asize = 5;
    const int a[asize] = {1, 3, 5, 3, 1};
    std::vector<int> av(a, a + sizeof(a) / sizeof(int));

    std::cout << "Original histogram is " << std::endl;
    print_array(a, asize);

    std::cout << "Maximum rectangle in this histogram is: " << max_rectangle_in_histogram(a, asize) << std::endl;
    std::cout << "Maximum rectangle in this histogram is: " << max_rectangle_in_histogram(av) << std::endl;

    std::cout << "\n---separator---\n" << std::endl;

    const int bsize = 10;
    const int b[bsize] = {9, 13, 5, 3, 9, 8, 8, 25, 2, 1};
    std::vector<int> bv(b, b + sizeof(b) / sizeof(int));

    std::cout << "Original histogram is " << std::endl;
    print_array(b, bsize);

    std::cout << "Maximum rectangle in this histogram is: " << max_rectangle_in_histogram(b, bsize) << std::endl;
    std::cout << "Maximum rectangle in this histogram is: " << max_rectangle_in_histogram(bv) << std::endl;

    return 0;
}

