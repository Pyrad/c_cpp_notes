#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>
#include<string>
#include<vector>
#include<sstream>
#include<stack>
#include<stdio.h>
#include<queue>

#include "../common_utils.hpp"
#include "../test_data.hpp"

// alias to namespaces
namespace CU = common_utils;
namespace TD = test_data;

// type definitions
typedef CU::node node;   // Binary tree node
typedef CU::snode snode; // Binary tree node with sibling
typedef CU::lnode lnode; // Linked list node

bool is_palindrome(const std::string& s) {
    if(s.empty()) {
        return true;
    }
    size_t start = 0;
    size_t end = s.size() - 1;
    while( (start < end) && (s[start] == s[end]) ) {
        start++;
        end--;
    }

    return start >= end;
}

void dfs(const std::string& s, 
         std::vector<std::string>& path, 
         std::vector<std::vector<std::string> >& res,
         size_t start ) {
    if(start == s.size()) {
        res.push_back(path);
        return ;
    }

    for(size_t i = start; i < s.size(); i++) {
        const std::string ssub = s.substr(start, i - start + 1);
        if(is_palindrome(ssub)) {
            path.push_back(ssub);
            dfs(s, path, res, i + 1);
            path.pop_back();
        }
    }
}

int main()
{
    std::string test_string("vacab");
    std::vector<std::vector<std::string> > all_partitions;
    std::vector<std::string> path;

    dfs(test_string, path, all_partitions, 0);

    printf("The string to do partition and statisfy all partitions are palindromes:\n");
    std::cout << test_string << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "All partitions are:" << std::endl;
    CU::print_vector_vector<std::string>(all_partitions);

    all_partitions.clear();
    path.clear();
    printf("\n");

    test_string = "vaabcabbcbbaddyx";
    dfs(test_string, path, all_partitions, 0);
    printf("The string to do partition and statisfy all partitions are palindromes:\n");
    std::cout << test_string << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "All partitions are:" << std::endl;
    CU::print_vector_vector<std::string>(all_partitions);

    return 0;
}

