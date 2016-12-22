#ifndef _COMMON_UTILS_HPP
#define _COMMON_UTILS_HPP

#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>

namespace common_utils {

// Binary tree node definition
class binary_tree_node {

public:
    binary_tree_node(int v): left(NULL), right(NULL), value(v) { }
    ~binary_tree_node() { }

public:
    binary_tree_node* left;
    binary_tree_node* right;
    int value;
};

typedef binary_tree_node node;

// Binary tree node with sibling definition
class binary_tree_node_with_sibling : public binary_tree_node {
public:
    binary_tree_node_with_sibling(int v): binary_tree_node(v), next(NULL) { }

public:
    binary_tree_node* next;
};

typedef binary_tree_node_with_sibling snode;

// Linked list node definition
class linked_list_node {
public:
    linked_list_node(int v): next(NULL), value(v) { }

public:
    linked_list_node *next;
    int value;
};

typedef linked_list_node lnode;


// Random digits generator
// [a, b]
int gen_random_int_1(const int& a, const int& b) {
    srand((unsigned)time(NULL));
    return a + rand() % (b - a + 1);
}
// [a, b)
int gen_random_int_2(const int& a, const int& b) {
    srand((unsigned)time(NULL));
    return a + rand() % (b - a);
}
// (a, b]
int gen_random_int_3(const int& a, const int& b) {
    srand((unsigned)time(NULL));
    return a + rand() % (b - a) + 1;
}
// (a, b)
int gen_random_int_4(const int& a, const int& b) {
    srand((unsigned)time(NULL));
    return a + rand() % (b - a + 1) - 1;
}


void VISIT(node* h) {
    if(h) {
        printf("%d ", h->value);
    } else {
        printf("INVALID_NODE_NULL ");
    }
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

// --------- Delete a tree ---------
void DELETE_TREE_NODE(node* h) {
    if(h) {
        delete h;
    }
}

void pre_order_release(node* h) {
    if(!h) {
        return ;
    }
    DELETE_TREE_NODE(h);
    pre_order_release(h->left);
    pre_order_release(h->right);
}

void in_order_release(node* h) {
    if(!h) {
        return ;
    }
    in_order_release(h->left);
    DELETE_TREE_NODE(h);
    in_order_release(h->right);
}

void post_order_release(node* h) {
    if(!h) {
        return ;
    }
    post_order_release(h->left);
    post_order_release(h->right);
    DELETE_TREE_NODE(h);
}

void release_tree(node* h, int which_method = 99) {
    switch(which_method) {
        case 0:
            pre_order_release(h);
            break;
        case 1:
            in_order_release(h);
            break;
        case 2:
            post_order_release(h);
            break;
        default:
            post_order_release(h);
    }
    std::cout << "(Tree is released)" << std::endl;
}
// --------- End of delete a tree ---------

// Tree traversal in recursive method
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


void print_array(const int *a, int s) {
	for(int i = 0; i < s; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void print_string_vector(const std::vector<std::string>& svec) {
    for(std::vector<std::string>::const_iterator itr = svec.begin(); itr < svec.end(); itr++) {
        std::cout << *itr << " ";
    }
	std::cout << std::endl;
}

} // NAMESPACE common_utils

#endif // _COMMON_UTILS_HPP
