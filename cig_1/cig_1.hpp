/*
 * CIG_1.hpp
 *
 *  Created on: January 20th, 2016
 *      Author: longc
 */

#ifndef CIG_1_HPP_
#define CIG_1_HPP_

#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <limits>
#include <string.h> // This is C-style included, could use "#include <cstring>" instead for C++ style
#include <stdlib.h> // This is C-style included, could use "#include <cstdlib>" instead for C++ style

//////////////////////////////////////////////////////////////////////////////////////
////
////			Common Utilities
////
//////////////////////////////////////////////////////////////////////////////////////
// C Style
void print_array(int* pArray, int size, bool newLineEnd = true) {
	if(!pArray || size <= 0)
		return ;
	for(int i = 0; i < size; i++)
		printf("%d ", pArray[i]);
	if(newLineEnd)
		printf("\n");
	else
		printf("\t");

	return ;
}

// C++ Style
template < unsigned int N >
void print_array(int(& pArray)[N], bool newLineEnd = true) {

	if(!pArray) {
		printf("Empty array! Can't print!\n");
		return ;
	}

	// Calculate array length
	// int aLen = sizeof(pArray) / sizeof(pArray[0]);
	for(unsigned int i = 0; i < N; i++) {
		printf("%d ", pArray[i]);
	}
	if(newLineEnd)
		printf("\n");
	else
		printf("\t");

	return ;
}
//////////////////////////////////////////////////////////////////////////////////////

/*******************************CIG Chapter 1 Issue 1*****************************************/
// Code related to getMin issue
class minStack {
public:
	int top();
	bool empty();
	void pop();
	void push(int value);
	int getMin();
	int size();

private:
	std::stack<int> stack_store;
	std::stack<int> stack_min;
};

int minStack::top() { return stack_store.top(); }
bool minStack::empty() { return stack_store.empty(); }
int minStack::getMin() { return stack_min.top(); }
int minStack::size() { return stack_store.size(); }
void minStack::pop() {
	stack_store.pop();
	stack_min.pop();
}
void minStack::push(int value) {
	if(empty()) {
		stack_store.push(value);
		stack_min.push(value);
	} else {
		stack_store.push(value);
		if( value < stack_min.top()) {
			stack_min.push(value);
		} else {
			stack_min.push(stack_min.top());
		}
	}
}


// Alternative code related to getMin issue
class minStackAlt {
public:
	int top();
	bool empty();
	void pop();
	void push(int value);
	int getMin();
	int size();

private:
	std::stack<int> stack_store;
	std::stack<int> stack_min;
};

int minStackAlt::top() { return stack_store.top(); }
bool minStackAlt::empty() { return stack_store.empty(); }
int minStackAlt::getMin() { return stack_min.top(); }
int minStackAlt::size() { return stack_store.size(); }
void minStackAlt::pop() {
	if(stack_min.top() == stack_store.top())
		stack_min.pop();
	stack_store.pop();

}
void minStackAlt::push(int value) {
	if(empty()) {
		stack_store.push(value);
		stack_min.push(value);
	} else {
		stack_store.push(value);
		if( value <= stack_min.top()) {
			stack_min.push(value);
		}
	}
}
/*---------------------------------------------------------------------------------*/


/*******************************CIG Chapter 1 Issue 2*****************************************/
// Issue of a self-defined queue using two stacks
class queueUseStack {
public:
	void push(int value);
	int front();
	int back();
	void pop();
private:
	std::stack<int> stackIn;
	std::stack<int> stackOut;
};

void queueUseStack::push(int value) {
	stackIn.push(value);
}
int queueUseStack::front() {
	if(stackOut.empty()) {
		while(!stackIn.empty()) {
			stackOut.push(stackIn.top());
			stackIn.pop();
		}
	}
	if(stackOut.empty()) {
		printf("Queue is empty!\n");
		return -1;
	}
	return stackOut.top();
}
int queueUseStack::back() {
	if(stackIn.empty()) {
		int temp = 0;
		while(!stackOut.empty()) {
			temp = stackOut.top();
			stackIn.push(temp);
		}
	}
	if(stackIn.empty()) {
		printf("Queue is empty!\n");
		return -1;
	}
	return stackIn.top();
}
void queueUseStack::pop() {
	if(stackOut.empty()) {
		while(!stackIn.empty()) {
			stackOut.push(stackIn.top());
			stackIn.pop();
		}
	}
	if(stackOut.empty()) {
		printf("Queue is empty!\n");
		return ;
	}
	stackOut.pop();
	return ;
}
/*---------------------------------------------------------------------------------*/

/*******************************CIG Chapter 1 Issue 3*****************************************/
int getAndRemoveLastElement(std::stack<int>& iStack) {
	int result = iStack.top();
	iStack.pop();
	if(iStack.empty()) {
		return result;
	} else {
		int last = getAndRemoveLastElement(iStack);
		iStack.push(result);
		return last;
	}
}

void reverseStack(std::stack<int>& iStack) {
	if(iStack.empty()) {
		return ;
	}
	int temp = getAndRemoveLastElement(iStack);
	reverseStack(iStack);
	iStack.push(temp);
}
/*---------------------------------------------------------------------------------*/



/*******************************CIG Chapter 1 Issue 4*****************************************/
class Pet {
public:
	Pet(std::string type) { m_type = type; }
	std::string getType() { return m_type; }
private:
	std::string m_type;
};

class Dog : public Pet {
private:
	Dog():Pet("dog") {};
};
class Cat : public Pet {
private:
	Cat():Pet("cat") {};
};

class PetEnterQueue {
public:
	PetEnterQueue(Pet p, int c):pet(p), count(c) {}
	PetEnterQueue(Cat /*p*/, int c):pet("cat"), count(c) {}
	PetEnterQueue(Dog /*p*/, int c):pet("dog"), count(c) {}
	inline int getCount() { return count; }
	inline std::string getType() { return pet.getType(); }
	Pet getPet() { return pet; }
private:
	Pet pet;
	int count;
};

class CatDogQueue {
public:
	CatDogQueue(): petCount(0) {}
	void add(Pet p);
	void add(Cat c);
	void add(Dog d);
	void pop();
	void popCatQueue();
	void popDogQueue();
	bool empty();
	bool emptyCatQueue();
	bool emptyDogQueue();
private:
	std::queue<PetEnterQueue> dogQ;
	std::queue<PetEnterQueue> catQ;
	int petCount;
};
void CatDogQueue::add(Pet p) {
	if(p.getType() == "dog") {
		dogQ.push(PetEnterQueue(p, ++petCount));
	} else if(p.getType() == "cat") {
		catQ.push(PetEnterQueue(p, ++petCount));
	} else {
		std::cout << "Unknown pet. Rejected." << std::endl;
	}
}
void CatDogQueue::add(Cat c) {
	catQ.push(PetEnterQueue(c, ++petCount));
}
void CatDogQueue::add(Dog d) {
	dogQ.push(PetEnterQueue(d, ++petCount));
}
void CatDogQueue::pop() {
	if( !dogQ.empty() && !catQ.empty()) {
		if( dogQ.front().getCount() < catQ.front().getCount() )
			dogQ.pop();
		else if( dogQ.front().getCount() > catQ.front().getCount() )
			catQ.pop();
		else
			std::cout << "Same time stamp, error!" << std::endl;
	} else if (!dogQ.empty()) {
		dogQ.pop();
	} else if (!catQ.empty()) {
		catQ.pop();
	} else {
		std::cout << "All empty!" << std::endl;
	}
}
void CatDogQueue::popCatQueue() { if(!catQ.empty()) catQ.pop(); }
void CatDogQueue::popDogQueue() { if(!dogQ.empty()) dogQ.pop(); }
bool CatDogQueue::empty() { return dogQ.empty() && catQ.empty(); }
inline bool CatDogQueue::emptyCatQueue() { return catQ.empty(); }
inline bool CatDogQueue::emptyDogQueue() { return dogQ.empty(); }

/*-------------------------------------------------------------------------------------------*/


/*******************************CIG Chapter 1 Issue 5*****************************************/
void sortStackByStack(std::stack<int> istack) {
	std::stack<int> stackHelper;
	int temp;
	while(!istack.empty()) {
		temp = istack.top();
		istack.pop();
		while(!stackHelper.empty() && temp > stackHelper.top()) {
			istack.push(stackHelper.top());
			stackHelper.pop();
		}
		stackHelper.push(temp);
	}
	while(!stackHelper.empty()) {
		istack.push(stackHelper.top());
		stackHelper.pop();
	}
}
/*-------------------------------------------------------------------------------------------*/ // Finished time: 22:54, Jan 21, 2016

/*******************************CIG Chapter 1 Issue 6*****************************************/
// --> Here's the recursive solution
int restrictedHanoiProcess(const int& tower, const std::string& left, const std::string& middle, const std::string& right,
							 const std::string& from, const std::string& to)
{
	if(tower == 1) {
		if( from != middle && to != middle) {
			printf("Move %d from %s to %s, then move %d from %s to %s\n", tower, from.c_str(), middle.c_str(), tower, middle.c_str(), to.c_str() );
			return 2;
		} else if( (from == middle && to != middle) || (from != middle && to == middle) ) {
			printf("Move %d from %s to %s\n", tower, from.c_str(), to.c_str());
			return 1;
		} else {
			printf("Bad from-to move. (from here is %s, to is %s)\n", from.c_str(), to.c_str());
			return 0;
		}
	}
	if(from != middle && to != middle) {
		int steps1 = restrictedHanoiProcess( tower - 1, left, middle, right, from, to);
		int steps2 = 1; // Move tower-th from "from" to "middle"
		printf("Move %d from %s to %s\n", tower, from.c_str(), middle.c_str());
		int steps3 = restrictedHanoiProcess( tower - 1, left, middle, right, to, from);
		int steps4 = 1; // Move tower-th from "middle" to "to"
		printf("Move %d from %s to %s\n", tower, middle.c_str(), to.c_str());
		int steps5 = restrictedHanoiProcess( tower - 1, left, middle, right, from, to);
		return steps1 + steps2 + steps3 + steps4 + steps5;
	} else if( (from == middle && to != middle) || (from != middle && to == middle) ) {
		std::string another = (from == left) || (to == left) ? right : left ;
		int steps1 = restrictedHanoiProcess(tower - 1, left, middle, right, from, another);
		int steps2 = 1; // Move tower-th from "from" to "to"
		printf("Move %d from %s to %s\n", tower, from.c_str(), to.c_str());
		int steps3 = restrictedHanoiProcess(tower - 1, left, middle, right, another, to);
		return steps1 + steps2 + steps3;
	} else {
		printf("Bad from-to tower\n");
		return 0;
	}
	return 0;
}
// Finished time: 23:01, Jan 22, 2016



// --> Below is non-recursive solution

// INT_MAX & INT_MIN have already been defined in <limits.h>
// #define INT_MAX std::numeric_limits<int>::max()
// #define INT_MIN std::numeric_limits<int>::min()

enum restrictedHanoiMoveAction {
	NOACT = 0,
	LTOM, // Move from tower Left to middle
	MTOL, // Move from tower middle to left
	RTOM, // Move from tower right to middle
	MTOR  // Move from tower middle to right
};
typedef restrictedHanoiMoveAction moveAction;

int frStackToStackRealMove(moveAction& preAct,
						   const moveAction& preNoAct, const moveAction& nowAct,
						   std::stack<int>& frStack, std::stack<int>& toStack,
						   const std::string& from, const std::string& to )
{
	if( preAct != preNoAct && frStack.top() < toStack.top() ) {
		printf("Move %d from %s to %s\n", frStack.top(), from.c_str(), to.c_str());
		preAct = nowAct;
		toStack.push(frStack.top());
		frStack.pop();
		return 1;
	}
	return 0;
}

int restrictedHanoiProcessNonRecursive(int towerNumber,
										const std::string& left, const std::string& middle, const std::string& right)
{
	if(towerNumber <= 0) {
		printf("Error tower number: %d\n", towerNumber);
	}
	std::stack<int> leftTower;
	std::stack<int> middleTower;
	std::stack<int> rightTower;
	int int_max = INT_MAX;
	leftTower.push(int_max);
	middleTower.push(int_max);
	rightTower.push(int_max);
	for(int i = towerNumber; i > 0; i--) {
		leftTower.push(i);
	}
	int step = 0;
	moveAction preAction = NOACT;
	while(static_cast<int>(rightTower.size()) != towerNumber + 1) {
		step += frStackToStackRealMove(preAction, MTOL, LTOM, leftTower, middleTower, left, middle);
		step += frStackToStackRealMove(preAction, LTOM, MTOL, middleTower, leftTower, middle, left);
		step += frStackToStackRealMove(preAction, MTOR, RTOM, rightTower, middleTower, right, middle);
		step += frStackToStackRealMove(preAction, RTOM, MTOR, middleTower, rightTower, middle, right);
	}
	return step;
}

/*-------------------------------------------------------------------------------------------*/

/*******************************CIG Chapter 1 Issue 7*****************************************/
void maxWindowValue(int* pArray, int arrSize, int* pResArray, int resArrSize, int windowSize) {
	// Exceptions
	if( arrSize <= 0 || resArrSize <= 0 || windowSize <= 0 || arrSize < windowSize || resArrSize < arrSize - windowSize + 1) {
		printf("Error array size!\n");
		return ;
	}
	std::deque<int> maxQueue;
	int resIndex = 0;
	for( int i = 0; i < arrSize; i++) {
		while (!maxQueue.empty() && pArray[maxQueue.back()] <= pArray[i]) {
			maxQueue.pop_back();
		}
		maxQueue.push_back(i);
		if(maxQueue.front() == i - windowSize) {
			maxQueue.pop_front();
		}
		if( i >= windowSize - 1) {
			pResArray[resIndex++] = pArray[maxQueue.front()];
		}
	}
	return ;
}
/*-------------------------------------------------------------------------------------------*/

/*******************************CIG Chapter 1 Issue 8*****************************************/
class Node {
public:
	Node(int data):value(data), pleft(NULL), pright(NULL) {}
	~Node() { pleft = NULL;	pright = NULL; }

	int value;
	class Node* pleft;
	class Node* pright;
};

void popStackSetMap(std::stack<class Node*>& ndStack, std::map<class Node*, class Node*>& ndMap) {
	if(ndStack.empty())
		return ;

	class Node* node = ndStack.top();
	ndStack.pop();
	class Node* pNull = NULL;
	if( ndStack.empty() ) {
		ndMap.insert(std::make_pair(node, pNull));
	} else {
		ndMap.insert(std::make_pair(node, ndStack.top()));
	}

	return ;
}

void getMaxTree(int* pArray, int arrLen) {
	class Node* *Nodes = new class Node* [arrLen];
	for(int i = 0; i < arrLen; i++) {
		Nodes[i] = new class Node(pArray[i]);
	}

	std::map<class Node*, class Node*> leftBigValueMap;
	std::map<class Node*, class Node*> rightBigValueMap;

	std::stack<class Node*> nodestack;

	// std::cout << "Allocation finished" << std::endl; /*** Debug message ***/

	class Node* pnode = NULL;
	for(int i = 0; i < arrLen; i++) {
		pnode = Nodes[i];
		while( !nodestack.empty() && pnode->value > nodestack.top()->value ) {
			popStackSetMap(nodestack, leftBigValueMap);
		}
		nodestack.push(pnode);
	}
	while(!nodestack.empty()) {
		popStackSetMap(nodestack, leftBigValueMap);
	}
	// std::cout << "Finished get left big map" << std::endl; /*** Debug message ***/

	for(int i = arrLen - 1; i > -1; i--) {
		pnode = Nodes[i];
		while( !nodestack.empty() && pnode->value > nodestack.top()->value ) {
			popStackSetMap(nodestack, rightBigValueMap);
		}
		nodestack.push(pnode);
	}
	while(!nodestack.empty()) {
		popStackSetMap(nodestack, rightBigValueMap);
	}

	// std::cout << "Finished get right big map" << std::endl; /*** Debug message ***/

	class Node* phead = NULL;
	for(int i = 0; i < arrLen; i++) {
		pnode = Nodes[i];
		class Node* leftBigNode = leftBigValueMap[pnode];
		class Node* rightBigNode = rightBigValueMap[pnode];
		if( !leftBigNode && !rightBigNode ) {
			phead = pnode;
		} else if ( !leftBigNode ) {
			if( !rightBigNode->pleft ) {
				rightBigNode->pleft = pnode;
			} else {
				rightBigNode->pright = pnode;
			}
		} else if ( !rightBigNode) {
			if( !leftBigNode->pleft ) {
				leftBigNode->pleft = pnode;
			} else {
				leftBigNode->pright = pnode;
			}
		} else {
			class Node* pparent = (leftBigNode->value < rightBigNode->value) ? leftBigNode : rightBigNode;
			if(!pparent->pleft) {
				pparent->pleft = pnode;
			} else {
				pparent->pright = pnode;
			}
		}
	}

	// Below is the messages to show the tree
	printf("Tree head is %d\n", phead->value);
	for(int i = 0; i < arrLen; i++) {
		pnode = Nodes[i];
		if(pnode->pleft && pnode->pright) {
			printf("Tree node value [%d], left node value [%d], right node value [%d]\n", pnode->value, pnode->pleft->value, pnode->pright->value);
		} else if (!pnode->pleft && !pnode->pright) {
			printf("Tree node value [%d], left node is NULL, right node is NULL\n", pnode->value);
		} else if (pnode->pleft) {
			printf("Tree node value [%d], left node value [%d], right node is NULL\n", pnode->value, pnode->pleft->value);
		} else {
			printf("Tree node value [%d], left node is NULL, right node value [%d]\n", pnode->value, pnode->pright->value);
		}
	}

	// Clean up for utilities in case of memory leakages
	for(int i = 0; i < arrLen; i++) {
		pnode = Nodes[i];
		delete pnode;
		pnode = NULL;
	}
	delete Nodes;

	return ;
}



/*-------------------------------------------------------------------------------------------*/

/*******************************CIG Chapter 1 Issue 9*****************************************/
// Issue of the sum of maximum child matrix form

int maxRectFromBottom(int* height, int size) {
	if(!height || size <= 0) {
		printf("Error height size\n");
		return 0;
	}

	int area;
	int max_area = 0;
	std::stack<int> istack;
	for(int i = 0; i < size; i++) {
		while(!istack.empty() && height[istack.top()] >= height[i]) {
			int j = istack.top();
			istack.pop();
			int k = istack.empty() ? -1 : istack.top();
			area = ( (i - 1)/*right most*/ - (k + 1)/*left most*/ + 1 ) * height[j];
			// Actuall is --> area = (i - k - 1)*height[j]
			if(area > max_area) {
				max_area = area;
			}
		}
		istack.push(i);
	}
	while(!istack.empty()) {
		int j = istack.top();
		istack.pop();
		int k = istack.empty() ? -1 : istack.top();
		area = ( (size - 1)/*right most*/ - (k + 1)/*left most*/ + 1 ) * height[j];
		// Actuall is --> area = (size - k - 1)*height[j]
		if(area > max_area) {
			max_area = area;
		}
	}

	return max_area;
}

int maxRectSize(int** matrix, int rows, int columns) {
	if(!matrix || rows <= 0 || columns <= 0) {
		printf("Error matrix\n");
	}
	int maxArea = 0;
	int temp = 0;
	int* height = new int[columns];
	memset(height, 0, columns * sizeof(int));
	// print_array(height, columns);
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			height[j] = matrix[i][j] == 0 ? 0 : height[j] + 1;
		}
		printf("Height of row %d: ", i + 1);
		print_array(height, columns);
		temp = maxRectFromBottom(height, columns);
		if( temp > maxArea ) {
			maxArea = temp;
		}
	}

	delete height;

	return maxArea;
}
/*-------------------------------------------------------------------------------------------*/ // Finished time Jan 23, 2016 23:00





/*******************************CIG Chapter 1 Issue 10****************************************/
int getNumMeetCondition(int* pArray, int arrSize, int limit) {
	int res = 0;
	if(!pArray || arrSize <=0) {
		printf("Error array!\n");
		return res;
	}
	std::deque<int> maxQueue;
	std::deque<int> minQueue;

	int i = 0;
	int j = 0;

	while( i < arrSize ) {
		while( j < arrSize ) {
			while(!maxQueue.empty() && pArray[maxQueue.back()] <= pArray[j]) {
				maxQueue.pop_back();
			}
			maxQueue.push_back(j);
			while(!minQueue.empty() && pArray[minQueue.back()] >= pArray[j]) {
				minQueue.pop_back();
			}
			minQueue.push_back(j);
			if( pArray[maxQueue.front()] - pArray[minQueue.front()] > limit) {
				break;
			}
			j++;
		}
		if( maxQueue.front() == i) {
			maxQueue.pop_front();
		}
		if( minQueue.front() == i) {
			minQueue.pop_front();
		}
		res += j - i;
		printf("Start index [%d] to end index [%d], total %d meets condition\n", i, j - 1, j - i);
		i++;
	}

	return res;
}
/*-------------------------------------------------------------------------------------------*/

#endif /* CIG_1_HPP_ */
