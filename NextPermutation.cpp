/*
 * NextPermutation.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: iNviNciBLe
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<class It>
bool nextPermutation(It begin, It last) {
	if (begin == last)
		return false;
	It i = last;
	if (begin == --i)
		return false;
	while (true) {
		It i1, i2;
		i1 = i;
		/*If we start from the end and iterate to see if any value
		 * is less then the current(i1) then there are still more permutations left
		 * keeping value at zeroth position as it is. */
		if (*--i < *i1) {
			i2 = last;
			//Find the large value to swap
			while (!(*i < *--i2))
				;
			iter_swap(i, i2);
			reverse(i1, last);
			return true;
		}
		if (i == begin) {
			reverse(begin, last);
			return false;
		}
	}

}

int main() {
	vector<int> vec = {1,2,3};
	nextPermutation(vec.begin(),vec.end());
	for(auto i : vec){
		cout << i << ' ';
	}
}

