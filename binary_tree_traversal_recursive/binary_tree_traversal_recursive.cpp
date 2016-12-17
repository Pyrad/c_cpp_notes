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

namespace CU = common_utils;
namespace TD = test_data;

typedef CU::node node;

void VISIT(node* h) {
    if(h) {
        printf("%d ", h->value);
    } else {
        printf("INVALID_NODE_NULL ");
    }
}

void pre_order(node* h) {
    if(!h) {
        return ;
    }
    VISIT(h);
    pre_order(h->left);
    pre_order(h->right);
}

void in_order(node* h) {
    if(!h) {
        return ;
    }
    in_order(h->left);
    VISIT(h);
    in_order(h->right);
}

void post_order(node* h) {
    if(!h) {
        return ;
    }
    post_order(h->left);
    post_order(h->right);
    VISIT(h);
}


node* construct_tree_from_array(const int* nds, int size) {
    assert(size > 0);
    node* *p = new node*[size];
    node* head = new node(nds[0]);
    p[0] = head;
    for(int i = 1; i < size; i++) {
        node *cur = new node(nds[i]);
        p[i] = cur;
        int parent = (i - 1) / 2;
        if( i % 2 == 0) {
            p[parent]->right = cur;
        } else {
            p[parent]->left = cur;
        }
    }

    delete [] p;

    return head;
}




int main()
{
    node *head = construct_tree_from_array(TD::tnodes, TD::num);

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

