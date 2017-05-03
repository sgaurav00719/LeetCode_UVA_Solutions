/*
 * RotateArray.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: iNviNciBLe
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
	int* a = &nums[0]; // This how you convert vector to an array.
	size_t n = 7;
		for(;k %= n; n -= k, a += k){
			for(int i =0; i < k; i++){
				swap(a[i],a[n-k+i]);
			}
		}
    }

int main(){
	vector<int> v = {1,2,3,4,5,6,7};
	rotate(v,3);
	for(int i = 0; i < 7; i++){
		cout <<v[i]<<' ';
	}
	return 0;
}





