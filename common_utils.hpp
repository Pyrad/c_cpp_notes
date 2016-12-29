#ifndef _COMMON_UTILS_HPP
#define _COMMON_UTILS_HPP

#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

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
    for(std::vector<std::string>::const_iterator itr = svec.begin(); itr != svec.end(); itr++) {
        std::cout << *itr << " ";
    }
	std::cout << std::endl;
}

void print_int_vector(const std::vector<int>& vec) {
    for(std::vector<int>::const_iterator itr = vec.begin(); itr != vec.end(); itr++) {
        std::cout << *itr << " ";
    }
	std::cout << std::endl;
}

template<typename T>
void print_vector(const std::vector<T>& vec) {
    size_t vsize = vec.size();
    for(size_t i = 0; i < vsize; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void print_vector_vector(const std::vector<std::vector<T> >& vecv) {
    size_t vsize = vecv.size();
    for(size_t i = 0; i < vsize; i++) {
        std::cout << "vector " << i + 1 << ": ";
        size_t size = vecv[i].size();
        for(size_t j = 0; j < size; j++) {
            std::cout << vecv[i][j] << " ";
        }
        std::cout << std::endl;
    }
}



// ------------------------------------------
// Create a linked list of a given number
lnode* gen_linked_list(int number) {
    if(number <= 0) {
        return NULL;
    }

    if(number > 1) {
        printf("(%d seconds would cost to create a linked list of %d nodes)\n", number, number);
    } else {
        printf("(%d second would cost to create a linked list of %d node)\n", number, number);
    }
    lnode dummy(-1);
    lnode *p(&dummy);

    const int rand_lower = -20000;
    const int rand_upper = 20000;

    for(int i = 0; i < number; i++) {
        sleep(1);
        p->next = new lnode(gen_random_int_1(rand_lower, rand_upper));
        p = p->next;
    }

    return dummy.next;
}

void delete_linked_list(lnode *p) {
    if(!p) {
        return ;
    }

    int cnt = 0;
    while(p) {
        lnode *n = p->next;
        delete p;
        cnt++;
        p = n;
    }

    printf("(Linked list(%d in total) is released)\n", cnt);
}

void print_link(lnode* p) {
    if(!p) {
        printf("(linked list is empty)\n");
        return ;
    }
    while(p) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}


template <typename T>
void print_matrix(const int& r, const int& c, T** m) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

} // NAMESPACE common_utils

#endif // _COMMON_UTILS_HPP
