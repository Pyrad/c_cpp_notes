
/*
 * CIG_9.hpp
 *
 *  Created on: 2016年12月5日
 *      Author: Pyrad
 */

#ifndef CIG_9_HPP_
#define CIG_9_HPP_

#include<stdio.h>
#include<stdlib.h>
#include<climits>
#include<cmath>
#include<algorithm>

namespace CIG_9 {

// Problem of post office and residential area

int** get_matrix(int row, int col) {
	int** m = (int**) malloc(sizeof(int*) * row);
	for(int i = 0; i < col; i++) {
		m[i] = (int*) malloc(sizeof(int) * col);
	}
	return m;
}

void free_matrix(int** m, int row, int col) {
	for(int i = 0; i < row; i++) {
		free(m[i]);
	}

	free(m);
}


int** build_one_between_i_j_matrix(int* residents, int residential_num, int office_num) {
	// int** w = new int[office_num + 1][residential_num + 1];

	int** w = get_matrix(office_num + 1, residential_num + 1);

	for(int i = 0; i < office_num; i++) {
		for(int j = i + 1; j < residential_num; j++) {
			w[i][j] = w[i][j - 1] + residents[j] - residents[(i + j) / 2];
		}
	}

	return w;
}

int get_shortest_length_sum(int* residents, int residential_num, int office_num) {

	if(residential_num <= 0 || office_num <= 0 || office_num >= residential_num) {
		return 0;
	}

	// int** dp = new int[office_num][residential_num];
	int** dp = get_matrix(office_num, residential_num);

	int** w = build_one_between_i_j_matrix(residents, residential_num, office_num);

	for(int k = 0; k < residential_num; k++) {
		dp[0][k] = w[0][k];
	}

	for(int i = 1; i < office_num; i++) {
		for(int j = i + 1; j < residential_num; j++) {
			dp[i][j] = INT_MAX;
			for(int k = 0; k <= j; k++) {
				dp[i][j] = std::min(dp[i][j], dp[i][k] + w[k+1][j]);
			}
		}
	}

	int shortest = dp[office_num - 1][residential_num - 1];

	free_matrix(w, office_num + 1, residential_num + 1);
	free_matrix(dp, office_num, residential_num);

	return shortest;

}

}



#endif /* CIG_9_HPP_ */
