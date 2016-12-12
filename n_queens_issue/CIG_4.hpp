/*
 * CIG_4.hpp
 *
 *  Created on: 2016Äê11ÔÂ10ÈÕ
 *      Author: Pyrad
 */

/*
 * CIG_4.hpp
 *
 *  Created on: Nov 10, 2016
 *      Author: longc
 */

#ifndef CIG_4_HPP_
#define CIG_4_HPP_

#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>

namespace CIG_4 {

class n_queens_issue {

public:
    n_queens_issue(int queen_num): m_num(queen_num) { }
    ~n_queens_issue() { }

    inline int get_queen_num() { return m_num;}

    void set_queen_num(int n) { m_num = n; }

    void execute();

    void execute(int num);

    bool is_valid(int row, int col, int* records);

    int process(int i, int* records, int len);

private:
    int m_num;
};

}


#endif /* CIG_4_HPP_ */

