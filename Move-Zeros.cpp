/*
 * Move-Zeros.cpp
 *
 *  Created on: Dec 31, 2016
 *      Author: iNviNciBLe
 */
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums);
};

void Solution::moveZeroes(vector<int>& nums) {
		for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
			if (nums[cur] != 0) {
				swap(nums[lastNonZeroFoundAt++], nums[cur]);
			}
		}
	}

int main() {
	Solution s;
	int myints[] = { 0, 2, 0, 77, 29 };
	vector<int> v(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << "The contents before are:";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	s.moveZeroes(v);

	std::cout << "The contents after are:";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	return 0;
}

