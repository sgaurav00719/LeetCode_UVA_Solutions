/*
 * ValidPalindrome.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: iNviNciBLe
 *
 *
 *
 *      Question:
Given a string, determine if it is a palindrome, considering only alphanumeric characters
and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Example Questions Candidate Might Ask:
Q: What about an empty string? Is it a valid palindrome?
A: For the purpose of this problem, we define empty string as valid palindrome.
Solution:
O(n) runtime, O(1) space:

The idea is simple, have two pointers – one at the head while the other one at the tail.
Move them towards each other until they meet while skipping non-alphanumeric
characters.
Consider the case where given string contains only non-alphanumeric characters. This is
a valid palindrome because the empty string is also a valid palindrome.
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

using namespace std;

bool isPalindrome(string s){
	int i = 0 ,j = s.size()-1;
	while(i<j){
		while( i<j && !isalnum(s[i]) ) i++;
		while( i<j && !isalnum(s[j]) ) j--;
		if(tolower(s[i]) != tolower(s[j])) return false;
		i++;
		j--;
	}
	return true;
}

int main(){
	cout << isPalindrome("aa,,,,,,,,,,,,,,,,,,ba");
	return 0;
}


