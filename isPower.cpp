/*
 * isPower.cpp
 *
 *  Created on: Feb 5, 2017
 *      Author: iNviNciBLe
 *
 *      Complexity: O(Log to base x)y
 */
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isPower(int x, int y){
	if(x == 1)
		return (y == 1);
	long long pow = 1;
	while(pow < y)
		pow *= x;
	return (pow == y);
}

int main(){
	cout << isPower(10,1);
	return 0;
}

