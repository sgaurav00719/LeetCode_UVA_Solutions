/*
 * TrappingRainWater.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: iNviNciBLe
 */

#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
	int n = height.size(),res = 0,left = 0, right = n-1, maxleft = 0, maxright = 0;
	while(left <= right){
		if(height[left] <= height[right]){
			if(height[left] >= maxleft) maxleft =height[left];
			else res+=maxleft-height[left];
			left++;
		}else{
			if(height[right]>=maxright) maxright= height[right];
			else res+=maxright-height[right];
			right--;
		}
	}
	return res;
}

int main(){
	vector<int> in = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << trap(in);
	return 0;
}




