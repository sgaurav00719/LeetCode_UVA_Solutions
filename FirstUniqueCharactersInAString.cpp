/*
 * FirstUniqueCharactersInAString.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: iNviNciBLe
 *
 *      Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

 */
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
	unordered_map<char,int> m;
	for(auto &c : s)
		m[c]++;

	// show content:
	 /* for (std::unordered_map<char,int>::iterator it=m.begin(); it!=m.end(); ++it)
	    std::cout << it->first << " => " << it->second << '\n';*/

	for(size_t i = 0; i < s.size(); i++) {
		if(m[s[i]] == 1) return i;
	}
	return -1;
}

int main(){
	string s = "eaeabcdb";
	int res = firstUniqChar(s);
	cout << res;
}


