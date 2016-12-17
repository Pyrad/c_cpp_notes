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

#include "../common_utils.hpp"
#include "../test_data.hpp"

// alias to namespaces
namespace CU = common_utils;
namespace TD = test_data;

// type definitions
typedef CU::node node;

void pre_order(node* h) {
    std::stack<node*> stk;
    node* p = h;
    while(p || !stk.empty()) {
        while(p) {
            CU::VISIT(p);
            stk.push(p);
            p = p->left;
        }
        p = stk.top();
        stk.pop();
        p = p->right;
    }

    return ;
}

void in_order(node* h) {
    std::stack<node*> stk;
    node* p = h;
    while(p || !stk.empty()) {
        while(p) {
            stk.push(p);
            p = p->left;
        }
        p = stk.top();
        stk.pop();
        CU::VISIT(p);
        p = p->right;
    }

    return ;
}

void post_order(node* h) {
    std::stack<node*> stk;
    std::stack<bool> vstk;
    node* p = h;
    while(p || !stk.empty()) {
        while(p) {
            stk.push(p);
            vstk.push(false);
            p = p->left;
        }
        p = stk.top();
        bool v = vstk.top();
        if(!v) {
            vstk.top() = true;
            p = p->right;
        } else {
            CU::VISIT(p);
            stk.pop();
            vstk.pop();
            p = NULL;
        }
    }

    return ;
}

int main()
{   
    node *head = CU::construct_tree_from_array(TD::tnodes, TD::num);

    printf("Pre order traversal of a tree\n");
    pre_order(head);
    printf("\nGolden is(pre-order):\n");
    CU::print_array(TD::golden_pre_order, TD::num);
    printf("\n");

    printf("In order traversal of a tree\n");
    in_order(head);
    printf("\nGolden is(in-order):\n");
    CU::print_array(TD::golden_in_order, TD::num);
    printf("\n");

    printf("Post order traversal of a tree\n");
    post_order(head);
    printf("\nGolden is(post-order):\n");
    CU::print_array(TD::golden_post_order, TD::num);
    printf("\n");

    CU::release_tree(head);

    return 0;
}

