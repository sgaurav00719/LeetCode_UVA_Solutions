/*
 * MaximumSubArrayProblem.cpp
 *
 *  Created on: Feb 7, 2017
 *      Author: iNviNciBLe
 *
 *      Question:
 *      Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

		For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
		the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		int max_ending_here = nums[0], max_so_far = nums[0];
		for(size_t i = 1; i < nums.size(); i++){
			max_ending_here = max(nums[i],max_ending_here + nums[i]);
			max_so_far = max (max_ending_here,max_so_far);
		}
		return max_so_far;
    }




int main(){
	vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
	int res = maxSubArray(v);
	cout << res;
	return 0;
}
