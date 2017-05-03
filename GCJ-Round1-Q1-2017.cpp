/*
 * GCJ-Round1-Q1-2017.cpp
 *
 *  Created on: Apr 14, 2017
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
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <fstream>

using namespace std;

#include <bits/stdc++.h>
#define rep(i,n) for(size_t i=0; i<(n); i++)
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


int main(){
	read("A-large-practice.in");
	rite("A-large1.out");
	int tc,count = 0;
	cin >> tc;
	while(tc--){
		count++;
		printf("Case #%d: ", count);
		long long D,N;
		long double S,timeMax = LDBL_MIN;
		cin>>D>>N;
		for(auto i = 0; i < N;i++){
			long double k,s;
			long double timeTmp;
			cin >> k >> s;
			timeTmp = (D-k)/s;
			timeMax = max(timeMax, timeTmp);
		}
		S = D/timeMax;
		printf("%.6Lf\n",S);
	}
}


