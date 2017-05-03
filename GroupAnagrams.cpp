/*
 * GroupAnagrams.cpp
 *
 *  Created on: Feb 16, 2017
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

vector<vector<string>> groupAnagrams(vector<string>& strs){
	unordered_map<string,multiset<string>> map;
	for(string s : strs){
		string t = s;
		sort(t.begin(),t.end());
		map[t].insert(s);
	}
	vector<vector<string>> anagrams;
	for(auto m : map){
		vector<string> anagram(m.second.begin(), m.second.end());
		anagrams.push_back(anagram);
	}
	return anagrams;
}
int main(){
	vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> res = groupAnagrams(s);

	//printing 2d array
	for ( const auto &row : res )
	{
	   for ( const auto &s : row ) std::cout << s << ' ';
	   std::cout << std::endl;
	}
	return 0;
}


