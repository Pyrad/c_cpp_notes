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
typedef CU::lnode lnode;

const int tree_node_num = 15;

int find_node_in_array(const int* a, int len, int v) {
    int res = -1;
    for(int i = 0; i < len; i++) {
        if(a[i] == v) {
            res = i;
            break;
        }
    }

    return res;
}

node* restore_tree(const int* pre, int s1, int e1, const int* in, int s2, int e2) {
    if( s1 > e1 || s2 > e2) {
        return NULL;
    }

    node *p = new node(pre[s1]);
    int k = find_node_in_array(in, tree_node_num, pre[s1]);
    p->left = restore_tree(pre, s1 + 1, s1 + k - s2, in, s2, k - 1);
    p->right = restore_tree(pre, s1 + k - s2 + 1, e1, in, k + 1, e2);

    return p;
}


int main()
{
    int tnum = tree_node_num;
    node *root = restore_tree(TD::golden_pre_order_2, 0, tnum - 1, TD::golden_in_order_2, 0, tnum - 1);

    printf("Post order traversal of a tree\n");
    CU::post_order(root);
    printf("\nGolden is(post-order):\n");
    CU::print_array(TD::golden_post_order_2, TD::num);
    printf("\n");

    CU::release_tree(root);

    return 0;
}

