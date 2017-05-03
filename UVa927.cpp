/*
 * UVa927.cpp
 *
 *  Created on: Mar 26, 2017
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
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int i;
		scanf("%d",&i); ++i;
		vi c;
		while(i--){
			int ci;
			scanf("%d",&ci);
			c.push_back(ci);
		}
		int d,k;
		scanf("%d",&d);
		scanf("%d",&k);
		i64 size = 0;
		for(int n = 1; n <= k ; n++){
			size += n*d;
			if(size>=k){
				i64 an = 0;
				for(size_t j = 0; j < c.size();j++)
					an += ((i64)c[j])*((i64)pow((float)n,(float)j));
				cout << an << endl;
				break;
			}
		}
	}
}

