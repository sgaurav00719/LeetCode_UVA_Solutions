/*
 * LongestPalindromeSubstring.cpp
 *
 *  Created on: Feb 15, 2017
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

int expandAroundCenter(string s,int right,int left){
	int L = left, R = right;
	    while (L >= 0 && R < s.length() && s[L] == s[R]) {
	        L--;
	        R++;
	    }
	    return R - L - 1;
}

string longestPalindrome(string s) {
	int start = 0, end = 0;
	for (size_t i = 0; i < s.size(); i++) {
	        int len1 = expandAroundCenter(s, i, i);
	        int len2 = expandAroundCenter(s, i, i + 1);
	        int len = max(len1, len2);
	        if (len > end - start) {
	            start = i - (len - 1) / 2;
	            end = i + len / 2;
	        }
	    }
	    return s.substr(start, end + 1-start);
}


int main(){
	string res = longestPalindrome("babad");
	cout << res;
	return 0;
}


