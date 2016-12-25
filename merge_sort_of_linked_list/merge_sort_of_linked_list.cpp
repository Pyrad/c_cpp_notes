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

lnode* merge_two_sorted_link(lnode *link1, lnode *link2){
    lnode dummy(-1);
    lnode *p(&dummy);
    while(link1 && link2) {
        if(link1->value < link2->value) {
            p->next = link1;
            link1 = link1->next;
        } else {
            p->next = link2;
            link2 = link2->next;
        }
        p = p->next;
    }
    if(link1) {
        p->next = link1;
    }
    if(link2) {
        p->next = link2;
    }

    return dummy.next;
}

lnode *merge_sort(lnode *head) {
    if(!head || !head->next) {
        return head;
    }
    lnode *slow = head;
    lnode *fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
#if 1
    lnode *p = merge_sort(head);
    lnode *q = merge_sort(fast);
    return merge_two_sorted_link(p, q);
#else
    CU::print_link(head);
    CU::print_link(fast);
    return merge_two_sorted_link(head, fast);
#endif
}

int main()
{
    const int t_num = 10;
    for(int i = 0; i < t_num; i++) {
        lnode *head = CU::gen_linked_list(i);
        CU::print_link(head);

        printf("After sorted\n");
        lnode *nhead = merge_sort(head);
        CU::print_link(nhead);
        printf("\n");
    }

    return 0;
}

