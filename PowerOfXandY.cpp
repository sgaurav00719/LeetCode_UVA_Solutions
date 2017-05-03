/*
 * PowerOfXandY.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: iNviNciBLe
 */

#include <cstdio>
#include <iostream>

using namespace std;

/*the question here is how we can reduce the complexity...
 * if we compute the x^y by normal method the complexity is O(y)... to reduce the complexity we can
 * use binary weighted power computation method in which complexity is O(logy)..
 * */

double myPow(double x, int n) {
	double ans = 1;
	    	unsigned long long p;
	    	if (n < 0) {
	    		p = -n;
	    		x = 1 / x;
	    	} else {
	    		p = n;
	    	}
			while (p) {
				if (p & 1)
					ans *= x;
				x *= x;
				p >>= 1;
			}
			return ans;
}

int main(){
	double x = 27;
	int y = -3;

	    cout << myPow(x, y);

	    return 0;
	return 0;
}



