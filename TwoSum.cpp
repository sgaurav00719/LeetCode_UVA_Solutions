/*
 * TwoSum.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: iNviNciBLe
 *
 *      Question: Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
	vector<int> res;
	unordered_map<int, int> map; //Key is target - numbers[i] and value is index i.
	for (size_t i = 0; i < numbers.size(); i++) {
		if (map.find(target - numbers[i]) != map.end()) {
			res.push_back(map[target - numbers[i]]);
			res.push_back(i);
		}

		map[numbers[i]] = i;

	}
	return res;
}
int main(){
	vector<int> v = {2, 7, 11, 15};
	vector<int> res = twoSum(v,9);
	for(auto i : res)
		cout << i << ' ';
	return 0;
}



