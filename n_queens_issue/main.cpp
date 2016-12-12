/*
 * main.cpp
 *
 *  Created on: 2016��11��10��
 *      Author: Pyrad
 */


#include <iostream>
#include "CIG_4.hpp"

using namespace std;

int main() {

	CIG_4::n_queens_issue* p = new CIG_4::n_queens_issue(0);

	int MAX_QUEENS = 15;

	for(int i = 0; i < MAX_QUEENS; i++) {
		p->set_queen_num(i);
		p->execute();
	}

	return 0;
}

