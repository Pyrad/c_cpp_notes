#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>
#include<string>
#include<vector>
#include<sstream>
#include<stack>
#include<stdlib.h>


#include "../common_utils.hpp"

namespace CU = common_utils;

bool is_operator(const std::string& s) {
    std::string op("+-*/");
    return !s.empty() && (op.find(s) != std::string::npos) && (s.size() == 1);
}

int reverse_polish_notation_solver(const std::vector<std::string>& rpn) {
    std::stack<int> stk;
    for(std::vector<std::string>::const_iterator itr = rpn.begin(); itr < rpn.end(); itr++) {
        if(!is_operator(*itr)) {
            stk.push(atoi(itr->c_str()));
        } else {
            int op1 = stk.top();
            stk.pop();
            int op2 = stk.top();
            stk.pop();
            if(*itr == std::string("+")) {
                op1 += op2;
            } else if(*itr == std::string("-")) {
                op1 -= op2;
            } else if(*itr == std::string("*")) {
                op1 *= op2;
            } else if(*itr == std::string("/")) {
                op1 /= op2;
            }
            stk.push(op1);
        }
    }

    return stk.top();
}

int main()
{
    std::vector<std::string> svec;
    svec.push_back("5");
    svec.push_back("7");
    svec.push_back("+");
    svec.push_back("9");
    svec.push_back("*");

    std::cout << "Reverse polish notation string is: ";
    CU::print_string_vector(svec);

    std::cout << "Reverse polish notation result is: " << reverse_polish_notation_solver(svec) << std::endl;

    return 0;
}

