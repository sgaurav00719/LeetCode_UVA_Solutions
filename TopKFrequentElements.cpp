/*Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
Show Company Tags
Show Tags
Show Similar Problems
 *
 * */
#include <bits/stdc++.h>
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

using namespace std;

/*Solution 1: Using a min heap. O(nlogk)*/
vector<int> topKFrequent1(vector<int>& nums, int k) {
	unordered_map<int,int> map;
	for(auto i : nums)
		map[i]++;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(auto & i : map){
		pq.push(i.second);
		while(pq.size( ) > (size_t)k) pq.pop();
	}
	vector<int> res;
	for(auto & i : map) {
		if(i.second >= pq.top()) res.push_back(i.first);
	}
	return res;

}

/*Bucket sort. O(n)*/
vector<int> topKFrequent2(vector<int>& nums, int k) {
	unordered_map<int,int> map;
	for(auto i : nums)
		map[i]++;
	vector<vector<int>> buckets(nums.size()+1);
	for(auto & i: map)
		buckets[i.second].push_back(i.first);
	reverse(begin(buckets), end(buckets));
	vector<int> res;
	for(size_t i = 0; i < buckets.size() && res.size() < k; i++){
		for(size_t j = 0; j < buckets[i].size();j++) {
			res.push_back(buckets[i][j]);
		}
	}

	return res;
}

int main(){
	vector<int> nums = {1,2,3,1,3,2,4,2};
	vector<int> res = topKFrequent2(nums,2);
	for(auto i: res)
		cout << i << ' ';

	return 0;
}
