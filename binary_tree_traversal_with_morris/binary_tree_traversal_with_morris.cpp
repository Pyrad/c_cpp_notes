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

// -------- The binary tree traversal in post order with Morris method -------- 
// Reverse right edge of a sub-tree
node* reverse(node* h) {
    node* pre = NULL;
    node* next = h;
    node* cur = h;
    while(next) {
        next = cur->right;
        cur->right = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

// Print a sub-tree's right edge in reverse order
void print_edge(node* h) {
    node* tail = reverse(h);
    node* t = tail;
    while(t) {
        CU::VISIT(t);
        t = t->right;
    }
    reverse(tail);
}

void post_order(node* h) {
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
                print_edge(p->left);
            }
        }
        p = p->right;
    }

    print_edge(h);

    return ;
}
// -------- END of the binary tree traversal in post order with Morris method -------- 

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

