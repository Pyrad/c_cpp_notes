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

void subset(const std::vector<int>& ivec, unsigned int plen, std::vector<int>& path, std::vector<std::vector<int> >& res) {
    if(plen == ivec.size()) {
        res.push_back(path);
        return ;
    }
    subset(ivec, plen + 1, path, res);
    path.push_back(ivec[plen]);
    subset(ivec, plen + 1, path, res);
    path.pop_back(); // <--- Very important
}

void all_subsets(const std::vector<int>& ivec) {

    std::vector<std::vector<int> > all_results;
    std::vector<int> path;

    subset(ivec, 0, path, all_results);

    int scnt = 0;
    for(std::vector<std::vector<int> >::iterator vitr = all_results.begin(); vitr != all_results.end(); vitr++ ) {
        printf("Subset %d: ", ++scnt);
        for(std::vector<int>::iterator itr = vitr->begin(); itr != vitr->end(); itr++) {
            printf("%d ", *itr);
        }
        printf("\n");
    }

}

int main()
{
    std::vector<int> v;
    const int num = 4;
    for(int i = 0; i < num; i++) {
        v.push_back(i + 1);
    }

    all_subsets(v);

    return 0;
}

