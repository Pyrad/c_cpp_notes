//============================================================================
// Name        : CIG_1.cpp
// Author      : Pyrad
// Version     :
// Copyright   : Copyright reserved by Pyrad
// Description : Code Implementation for Book Coding Interview Guide Code Implementation
// Usage	   : !!!! set CHAPTER_1_ISSUE_XX to 1 when testing that issue !!!!
//============================================================================

#include "CIG_1.hpp" // Real implementation of issue 1~10 in chapter 1

#include <iostream>

#define CHAPTER_1_ISSUE_1	0	// Get min stack
#define CHAPTER_1_ISSUE_2	0	// Queue consists of two stacks
#define CHAPTER_1_ISSUE_3	0	// Reverse a stack by just using recursion
#define CHAPTER_1_ISSUE_4	0	// Cat dog queue
#define CHAPTER_1_ISSUE_5	0	// Sort a stack by using another stack
#define CHAPTER_1_ISSUE_6	0	// Restricted Hanoi Tower Problem
#define CHAPTER_1_ISSUE_7	0	// Max values of a sliding window in an array
#define CHAPTER_1_ISSUE_8	0	// Max Tree Issue of a given array
#define CHAPTER_1_ISSUE_9	0	// Max child matrix area(sum)
#define CHAPTER_1_ISSUE_10	0	// Get total array number which meets condition "MAX - MIN <= limit"

using namespace std;


/////////////////////////////////////////////////////////////////////////////
////////
////////  Data for testing use
////////
/////////////////////////////////////////////////////////////////////////////
int array[] = {432, 456, 96, 120, 121, 90, 589, 998, 20, 80, 965, 852, 123, 11, 456, 789};
int len = sizeof(array) / sizeof(array[0]);

int array_simple[] = {5, 3, 2, 1, 4};
int len_sim = sizeof(array_simple) / sizeof(array_simple[0]);

int array_no_repeat[] = {3, 4, 5, 1, 2};
int len_array_no_repeat = sizeof(array_no_repeat) / sizeof(array_no_repeat[0]);

const int row = 3;
const int col = 4;
const int matrix[row][col] = {
		{1, 0, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 1, 0}
};
/////////////////////////////////////////////////////////////////////////////

int main() {
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "--- Coding Interview Guide Implementation of Chapter 1 ---" << std::endl;
	std::cout << "----------------------------------------------------------\n" << std::endl;
#if CHAPTER_1_ISSUE_1
	/*******************************CIG Chapter 1 Issue 1*****************************************/
	{


		minStack stk;
		for (int i = 0; i < len; i++) {
			stk.push(array[i]);
		}
		printf("Print minStack from top to bottom:\n");
		printf("Stack\tMin\n");
		printf("------------------\n");
		while (!stk.empty()) {
			printf("%d\t%d\n", stk.top(), stk.getMin());
			stk.pop();
		}


		minStackAlt stkAlt;
		for (int i = 0; i < len; i++) {
			stkAlt.push(array[i]);
		}
		printf("Print minStack from top to bottom:\n");
		printf("Stack\tMin\n");
		printf("------------------\n");
		while (!stkAlt.empty()) {
			printf("%d\t%d\n", stkAlt.top(), stkAlt.getMin());
			stkAlt.pop();
		}

	}
#endif // CHAPTER_1_ISSUE_1
	/*---------------------------------------------------------------------------------*/


	/*******************************CIG Chapter 1 Issue 2*****************************************/
#if CHAPTER_1_ISSUE_2
#endif // CHAPTER_1_ISSUE_2
	/*----------------------------------------------------------------------------------*/


	/*******************************CIG Chapter 1 Issue 3*****************************************/
#if CHAPTER_1_ISSUE_3
	{
		std::stack<int> iStack;
		std::cout << "array_simple before reverse: " << std::endl;
		for (int i = 0; i < len_sim; i++) {
			iStack.push(array_simple[i]);
			std::cout << array_simple[i] << " ";
		}
		std::cout << std::endl;
		std::vector<int> ivec;
		reverseStack(iStack);
		ivec.clear();
		if(iStack.empty())
			std::cout << "EMPTY" << std::endl;
		while(!iStack.empty()) {
			ivec.push_back(iStack.top());
			iStack.pop();
		}
		std::cout << "array_simple after reverse: " << std::endl;
		for(std::vector<int>::reverse_iterator ritr = ivec.rbegin(); ritr != ivec.rend(); ritr++) {
			std::cout << *ritr << " ";
		}
		std::cout << std::endl;
	}
#endif // CHAPTER_1_ISSUE_3
	/*----------------------------------------------------------------------------------*/

	/*******************************CIG Chapter 1 Issue 4*****************************************/

	/*-------------------------------------------------------------------------------------------*/

	/*******************************CIG Chapter 1 Issue 5*****************************************/

	/*-------------------------------------------------------------------------------------------*/


	/*******************************CIG Chapter 1 Issue 6*****************************************/
#if CHAPTER_1_ISSUE_6
	{
		int towerHeight = 2;
		std::string leftTower("A");
		std::string middleTower("B");
		std::string rightTower("C");
		std::string fromTower(leftTower);
		std::string toTower(rightTower);
		int whole_steps = 0;

		printf("[Using Recursive] Step sequences to move tower of height %d from %s to %s\n", towerHeight, fromTower.c_str(), toTower.c_str());
		printf("------------------------------------------------------\n");
		whole_steps = restrictedHanoiProcess(towerHeight, leftTower, middleTower, rightTower, fromTower, toTower);
		printf("Whole steps to move from %s to %s for tower of height %d: %d \n", fromTower.c_str(), toTower.c_str(), towerHeight, whole_steps);

		whole_steps = 0;
		printf("[Using Non-Recursive] Step sequences to move tower of height %d from %s to %s\n", towerHeight, fromTower.c_str(), toTower.c_str());
		printf("------------------------------------------------------\n");
		whole_steps = restrictedHanoiProcessNonRecursive(towerHeight, leftTower, middleTower, rightTower);
		printf("Whole steps to move from %s to %s for tower of height %d: %d \n", fromTower.c_str(), toTower.c_str(), towerHeight, whole_steps);

	}
#endif // CHAPTER_1_ISSUE_5
	/*----------------------------------------------------------------------------------*/

	/*******************************CIG Chapter 1 Issue 7 *****************************************/
#if CHAPTER_1_ISSUE_7
	{
		int slidingWindowSize = 3;
		int maxWinValueResLen = len - slidingWindowSize + 1;
		// int* maxWinValueRes = new int[len - slidingWindowSize + 1];
		int* maxWinValueRes = (int*) malloc( maxWinValueResLen * sizeof(int) );
		std::cout << "Original array" << std::endl;
		print_array(array, len);
		std::cout << std::endl;
		maxWindowValue(array, len, maxWinValueRes, maxWinValueResLen, slidingWindowSize);
		std::cout << "Max values for sliding window of size " << slidingWindowSize << std::endl;
		print_array(maxWinValueRes, maxWinValueResLen);

		// delete maxWinValueRes;
		free(maxWinValueRes);
	}
#endif // CHAPTER_1_ISSUE_7

	/*-------------------------------------------------------------------------------------------*/


	/*******************************CIG Chapter 1 Issue 8 *****************************************/
#if CHAPTER_1_ISSUE_8
	{
		getMaxTree(array_no_repeat, len_array_no_repeat);
	}
#endif // CHAPTER_1_ISSUE_8
	/*-------------------------------------------------------------------------------------------*/

	/*******************************CIG Chapter 1 Issue 9 *****************************************/
#if CHAPTER_1_ISSUE_9
	{
		int* *testMatrix = new int*[row];
		for(int k = 0; k < row; k++) {
			testMatrix[k] = new int[col];
		}
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				testMatrix[i][j] = matrix[i][j];
			}
		}
		printf("Original Matrix:\n");
		for(int k = 0; k < row; k++) {
			print_array(testMatrix[k], col);
		}
		printf("\n");

		int max_child_matrix_area = maxRectSize(testMatrix, row, col);
		printf("\nMax area of child matrix is: %d", max_child_matrix_area);

		for(int k = 0; k < row; k++) {
			delete testMatrix[k];
		}
		delete testMatrix;
	}
#endif // CHAPTER_1_ISSUE_9
	/*-------------------------------------------------------------------------------------------*/

	/*******************************CIG Chapter 1 Issue 10 *****************************************/
#if CHAPTER_1_ISSUE_10
	{
		int limit = 200;
		int result = getNumMeetCondition(array, len, limit);
		printf("Total %d\n", result);
	}
#endif // CHAPTER_1_ISSUE_10
	/*-------------------------------------------------------------------------------------------*/



	return 0;
}

