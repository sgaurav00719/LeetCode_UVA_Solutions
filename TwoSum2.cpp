/*
 * TwoSum2.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: iNviNciBLe
 *
 *
 *      Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Complexity is O(nlogn) space O(1)
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
#include <exception>

using namespace std;

unordered_map<int,int> map;

//binary search
int my_bsearch(vector<int>& A, int key){
	int lo = 1, hi = A.size();
	while(lo <= hi){
		int mid = lo + (hi -lo)/2;
		if(A[mid] == key)
			return mid;
		else if(A[mid] < key){
			lo = mid+1;
		}
		else {
			hi = mid - 1;
		}

	}
	return -1;
}
//Using binary search
vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int> res;
	for(size_t i = 0; i < numbers.size();i++){
		int j = my_bsearch(numbers,target-numbers[i]);
		if(j != -1){
			res.push_back(i+1);
			res.push_back(j+1);
			break;
		}
	}
	return res;
}

//Using two pointers
vector<int> twoSum2(vector<int>& numbers, int target){
	vector<int> res;
	for(int i = 0, j  = numbers.size()-1; i < j;){
		int N = numbers[j] + numbers[i];
		if(N < target) i++;
		else if(N > target) j--;
		else{
			res.push_back(i+1);
			res.push_back(j+1);
			break;
		}
	}
	return res;
}

int main(){
	vector<int> v = {2, 7, 11, 15};
	vector<int> res = twoSum2(v,9);
	for(auto i : res)
		cout << i << ' ';
	return 0;
}
