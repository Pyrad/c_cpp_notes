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
typedef CU::node node;
typedef CU::snode snode;

void tree_level_visit(node* h) {
    node* p = NULL;
    std::queue<node*> stk;
    stk.push(h);
    node* last = h;
    node* tmplast = NULL;
    while(!stk.empty()) {
        p = stk.front();
        CU::VISIT(p);
        stk.pop();
        if(p->left) {
            stk.push(p->left);
            tmplast = p->left;
        }
        if(p->right) {
            stk.push(p->right);
            tmplast = p->right;
        }
        if( p == last ) {
            last = tmplast;
            printf("\n");
        }
    }
}


int main()
{
    node *head = CU::construct_tree_from_array(TD::tnodes, TD::num);

    printf("Pre order traversal of a tree\n");
    tree_level_visit(head);
    printf("\nGolden is(level-order):\n");
    CU::print_array(TD::tnodes, TD::num);
    printf("\n");

    CU::release_tree(head);

    return 0;
}

