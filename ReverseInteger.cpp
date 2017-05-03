/*
 * ReverseInteger.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: iNviNciBLe
 */


#include <iostream>

using namespace std;

int reverse(int x) {
	int result = 0;
	while(x != 0){
		int back = x % 10;
		int intermideat = result * 10 + back;
		if((intermideat - back)/10 != result) return 0; // Check condition for overflow.
		result = intermideat;
		x /= 10;
	}
	return result;
}


int main(){
	cout << reverse(1234);
}

