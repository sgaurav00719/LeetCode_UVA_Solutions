/*
 * DecodeWays.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: iNviNciBLe
 *
 *      A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

int numDecodings(string s){
	if(s.empty()) return 0;

		int strLen = s.size();
		vector<int> dp(strLen+1,0);
		dp[strLen] = 1;
		dp[strLen - 1] = s[strLen-1] != '0' ? 1 : 0;
		for(int i = strLen -2; i >= 0; i--){
			if(s[i] == '0')
			{
				continue;
			}
			else dp[i] = (stoi(s.substr(i,2)) <= 26) ? dp[i+1]+dp[i+2]: dp[i+1];
		}
		return dp[0];
}

int main(){
	int res = numDecodings("15");
	cout << res << endl;
	return 0;
}


