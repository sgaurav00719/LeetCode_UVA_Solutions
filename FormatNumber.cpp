/*
 * FormatNumber.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: iNviNciBLe
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

//1234
//1,234

// 104450 -> 104,450
// 123123123 -> 123,123,123

// 1000000 -> 10,00,000
// 00010100

string formatNum(int num) {
	int total_processed = 0;
	string ret(" ");
	while(num > 0){
		if (total_processed != 0 && total_processed %3 == 0)
					ret += ",";
				ret += (char) (num %10 + '0');
				total_processed ++;
				num /= 10;
	}
	reverse (ret.begin(), ret.end());
	return ret;
}

int main() {
    string res;
    int _num;
    cin >> _num;

    res = formatNum(_num);
    cout << res;

    return 0;
}




