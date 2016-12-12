#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>

char* get_manacher_array(const char* a, int size) {
	char* p = new char[size * 2 + 1];
	for(int i = 0; i < size; i++) {
		p[2 * i] = '#';
		p[2 * i + 1] = a[i];
	}
	p[2 * size] = '#';

	return p;
}


// Longest substring length of parlidrome 
int manacher(const char* s, int size) {
	if(!s || size <= 0) {
		return 0;
	}
	const int len = 2 * size + 1;
	char* ss = get_manacher_array(s, size);
	int* p = new int[len];
	int index = -1;
	int pR = -1;
	int max = INT_MIN;
	for(int i = 0; i < len; i++) {
		p[i] = pR > i ? std::min(p[2 * index - i], pR - i) : 1;
		while(i + p[i] < len && i - p[i] > -1) {
			if(ss[i + p[i]] == ss[i - p[i]]) {
				p[i]++;
			} else {
				break;
			}
		}
		if(i + p[i] > pR) {
			pR = i + p[i];
			index = i;
		}
		max = std::max(max, p[i]);
	}

	delete [] ss;
	delete [] p;

	return max - 1;
}


int main() {

	std::string test_str("thiabcvcbaxx");

	int length = manacher(test_str.c_str(), test_str.size());

	std::cout << "test string is: " << test_str << std::endl;
	std::cout << "Longest parlidrome length is : " << length << std::endl;

	return 0;
}






