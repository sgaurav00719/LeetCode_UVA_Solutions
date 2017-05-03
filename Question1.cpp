/*
 * Question1.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: iNviNciBLe
 */

#include <bits/stdc++.h>
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


#define rep(i,n) for(auto i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int, int> mii;
typedef map<st, int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define mx 0


int longestPalindromeSubseq(int n,string s) {
        int res = 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            int len = 0;
            for (int j = i - 1; j >= 0; j--) {
                int tmp = dp[j];
                if (s[j] == s[i]) {
                    dp[j] = len + 2;
                }
                len = max(len, tmp);
            }
        }
        for (auto i : dp)
            res = max(res, i);
        return res;
    }

int main(){
	int n;
	string str;
	cin >> n;
	cin >> str;
	int res = longestPalindromeSubseq(n,str);
	cout << res << endl;
	return 0;
}
