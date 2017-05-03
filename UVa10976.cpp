/*
 * UVa10976.cpp
 *
 *  Created on: Mar 27, 2017
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
	read("input");
	int k;
	while(scanf("%d",&k) == 1){
		vector<pii> sol;
		for(int y = k+1;y<=2*k;++y){
			if((k*y)%(y-k) == 0)
				sol.push_back(make_pair((k*y)/(y-k),y));
		}
		cout << sol.size() << endl;
		for (size_t i = 0; i < sol.size(); ++i)
		            cout << "1/"
		                 << k
		                 << " = 1/"
		                 << sol[i].first
		                 << " + 1/"
		                 << sol[i].second
		                 << endl;
	}
	return 0;
}



