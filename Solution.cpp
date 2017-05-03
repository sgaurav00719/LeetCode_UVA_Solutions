/*
 * Solution.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: iNviNciBLe
 */

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <climits>

using namespace std;
/*Solved using kadane's Algorithm
 * It's similar to max sub array problem.
 * O(n)*/

int maxProfit(vector<int>& prices) {
	int max_ending_here = 0, max_so_far = 0;
	for(size_t i = 1; i < prices.size(); i++){
		max_ending_here = max(0,max_ending_here+prices[i] - prices[i-1]/*here put quantity to maximize*/);
		max_so_far = max(max_so_far,max_ending_here);
	}
	return max_so_far;
}

int main(){
	vector<int> v = {7, 6, 4, 3, 1};
	int res = maxProfit(v);
	cout << res;
	return 0;
}

