/*
 Given a non-empty string s and a dictionary wordDict containing a
 list of non-empty words, determine if s can be segmented into a space-separated sequence of one
 or more dictionary words. You may assume the dictionary does not contain duplicate words.
For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

Idea:

We use a boolean vector dp[]. dp[i] is set to true if a valid word
(word sequence) ends there. The optimization is to look from current position
i back and only substring and do dictionary look up in case
the preceding position j with dp[j] == true is found.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
	int n = s.size();
	unordered_set<string> dict(wordDict.begin(),wordDict.end());
	vector<bool> memo(n+1,false);
	if(wordDict.empty()) return false;
	memo[0] = true;
	for(int i = 1; i <= n; i++){
		for(int j = i - 1; j>=0;j--){
			string word = s.substr(j,i-j);
			if(memo[j] && dict.find(word)!=dict.end()){
				memo[i] = true;
				break; //next i
			}
		}
	}
	return memo[n];
}
int main(){
	vector<string> dict = {"leet","code"};
	cout << wordBreak("leetcode",dict);
	return 0;
}
