/*
 * UVa11742.cpp
 *
 *  Created on: Jan 15, 2017
 *      Author: iNviNciBLe
 *
 *      Input
Each test case begins with two integers n and m with 0 < n ≤ 8 and 0 ≤ m ≤ 20 where n is the size of
the group. For simplicity, assume the teenagers are numbered from 0 to n − 1. Then of m lines follow,
each describing a constraint, where a line consists of three integers a, b, c satisfying 0 ≤ a, b < n and
0 < |c| < n. If c is positive then teenagers a and b must sit at most c seats apart. If c is negative, then
a and b must sit at least −c seats apart. The end of input is signaled by a line consisting of n = m = 0.
Output
The output for each test case is a single line containing the number of possible seating arrangements
for the group that satisfy all of the social constraints.
Sample Input
3 1
0 1 -2
3 0
0 0
Sample Output
2
6
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

using namespace std;

#include <bits/stdc++.h>
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
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define mx 0

int n, m,a[21],b[21],c[21],p[10];

bool constraint(){
	rep(i,m){
			if(c[i] > 0 && abs(p[a[i]] - p[b[i]]) > c[i])
				return false;
			if(c[i] < 0 && abs(p[a[i]] - p[b[i]]) < -c[i])
				return false;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
freopen("test.inp", "r", stdin);
freopen("test.out", "w", stdout);
#endif
	while(scanf("%d %d",&n,&m) && (n+m)){
		rep(i,m)
				scanf("%d %d %d",&a[i],&b[i],&c[i]);
		rep(i,n)
			p[i] = i;
		int res = 0;
		do{
			if(constraint())
				res++;
		}while(next_permutation(p, p + n));
		printf("%d\n", res);
	}
    return 0;
}


