/*
 * Implement_StrStr.cpp
 *
 *  Created on: Feb 27, 2017
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
#include <unordered_map>
#include <functional>

using namespace std;

int strStr(string haystack, string needle) {
	int m = haystack.length(), n = needle.length();
	        if (!n) return 0;
	        for (int i = 0; i < m - n + 1; i++) {
	            int j = 0;
	            for (; j < n; j++)
	                if (haystack[i + j] != needle[j])
	                    break;
	            if (j == n) return i;
	        }
	        return -1;
}

int main(){
	cout << strStr("gaurav_sharma","ar");
	return 0;
}

