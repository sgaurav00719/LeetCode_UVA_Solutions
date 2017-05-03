/*
 * TwoSum3.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: iNviNciBLe
 */



#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <exception>

using namespace std;

class TwoSum{

private :
	unordered_map<int,int> map;
public:
	/** Initialize your data structure here. */
	TwoSum() {

	}

	/** Add the number to an internal data structure.. */
	void add(int number) {
		//Key = num, value = freq
		int count = map.find(number) != map.end()? map[number] :0;
		map[number] = count+1;
	}

	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int value) {
		for(auto i:map){
			int num = i.first;
			int y = value - num;
			if(y == num){
				if(i.second >= 2) return true;
			} else if(map.find(y) !=map.end()){
				return true;
			}
		}
		return false;
	}

	void print(){
		for(auto i: map)
			cout << i.first << ' ' << i.second << endl;
	}

};
int main(){
	TwoSum obj;
	obj.add(1);
	obj.add(2);
	cout << obj.find(3);
	return 0;
}
