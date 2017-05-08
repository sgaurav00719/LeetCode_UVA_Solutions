/*
 * LongestIncreasingSubsequence.cpp
 *
 *  Created on: May 2, 2017
 *      Author: iNviNciBLe
 */

/*
Our strategy determined by the following conditions,
1. If A[i] is smallest among all end
   candidates of active lists, we will start
   new active list of length 1.
2. If A[i] is largest among all end candidates of
  active lists, we will clone the largest active
  list, and extend it by A[i].
3. If A[i] is in between, we will find a list with
  largest end element that is smaller than A[i].
  Clone and extend this list by A[i]. We will discard all
  other lists of same length as that of this modified list.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;
//O(nlogn) complexity
int lengthOfLIS(vector<int>& nums){
	vector<int> res;
	for(size_t i  = 0; i <nums.size(); i++){
		//lower_bound: Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val(here nums[i]).
		auto it = lower_bound(res.begin(), res.end(), nums[i]);
		if(it==res.end()) res.push_back(nums[i]);
		else *it = nums[i];
	}
	return res.size();
}

//Construction Of Longest Inc. Sub.


int main(){
	vector<int> v = { 2, 5, 3, 7, 11, 8, 10, 13, 6};
	cout << lengthOfLIS(v);
	return 0;
}




