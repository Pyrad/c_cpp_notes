//============================================================================
// Name        : CIG_9.cpp
// Author      : Pyrad
// Version     :
// Copyright   : Pyrad
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CIG_9.hpp"
using namespace std;

int main() {

	int a[5] = {1, 3, 5, 8, 12};
	int residential_num = 5;
	int office_num = 3;

	int shortest_length_sum = CIG_9::get_shortest_length_sum(a, residential_num, office_num);

	printf("%d residents and %d offices, shortest length sum is: %d\n", residential_num, office_num, shortest_length_sum);

	return 0;
}
