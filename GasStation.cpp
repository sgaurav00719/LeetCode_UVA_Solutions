/*
 * GasStation.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: iNviNciBLe
 *
 *      There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int left = 0, start = 0, remaining = 0;
	for(size_t i = 0; i < gas.size(); i++){
		left += gas[i] - cost[i];
		if(left < 0){
			start = i + 1;
			remaining += left; //-ve meaning still need to travel this distance
			left = 0;
		}
	}
	return (remaining+left)<0?-1:start;
}

int main(){
	vector<int> gas = {1,1,2,1,3};
	vector<int> cost = {1,5,1,1,1};
	cout << canCompleteCircuit(gas,cost);
	return 0;
}




