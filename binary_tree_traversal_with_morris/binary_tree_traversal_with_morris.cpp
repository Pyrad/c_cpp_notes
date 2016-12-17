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
    node* p = h;
    node* r = NULL;
    while(p) {
        r = p->left;
        if(r) {
            while(r->right && (r->right != p)) {
                r = r->right;
            }
            if(!r->right) {
                CU::VISIT(p);
                r->right = p;
                p = p->left;
                continue;
            } else {
                r->right = NULL;
            }
        } else {
            CU::VISIT(p);
        }
        p = p->right;
    }

    return ;
}

void in_order(node* h) {
    node* p = h;
    node* r = NULL;
    while(p) {
        r = p->left;
        if(r) {
            while(r->right && (r->right != p)) {
                r = r->right;
            }
            if(!r->right) {
                r->right = p;
                p = p->left;
                continue;
            } else {
                r->right = NULL;
            }
        }
        CU::VISIT(p);
        p = p->right;
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

#if 0
    printf("Post order traversal of a tree\n");
    post_order(head);
    printf("\nGolden is(post-order):\n");
    CU::print_array(TD::golden_post_order, TD::num);
    printf("\n");
#endif // 0

    CU::release_tree(head);

    return 0;
}

