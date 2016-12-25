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

lnode* mid_point_node(lnode *p) {
    if(!p) {
        return NULL;
    }

    lnode *slow = p;
    lnode *fast = p;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    const int t = 9;
    const int lnode_num[t] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for(int i = 0; i < t; i++) {
        lnode *plink = CU::gen_linked_list(lnode_num[i]);
        CU::print_link(plink);
        lnode *mid = mid_point_node(plink);
        if(mid) {
            printf("Mid point node value is: %d\n", mid->value);
        } else {
            printf("Mid point node is: NULL\n");
        }
        CU::delete_linked_list(plink);
        printf("\n");
    }

    return 0;
}

