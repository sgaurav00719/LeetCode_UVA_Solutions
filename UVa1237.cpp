/*
 * UVa1237.cpp
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

int main() {
	read("input");
	int tc;
	typedef struct data {
		string M;
		int L;
		int H;
	} data;
	scanf("%d", &tc);
	bool first = true;
	while (tc--) {
		if (!first)
			cout << '\n';
		else
			first = false;
		int d;
		scanf("%d", &d);
		vector<data> vd(d);
		for (int i = 0; i < d; i++) {
			cin >> vd[i].M >> vd[i].L >> vd[i].H;
		}
		int p;
		vi vp;
		scanf("%d", &p);
		for (int i = 0; i < p; i++) {
			int pi;
			scanf("%d", &pi);
			vp.push_back(pi);
		}
		//Logic
		for (auto i : vp) {
			vs found;
			for (auto j : vd) {
				if (i >= j.L && i <= j.H)
					found.push_back(j.M);
				if (found.size() > 1) {
					break;
				}
			}
			(found.size() == 1) ?
					cout << found[0] << endl : cout << "UNDETERMINED" << endl;
		}
	}
	return 0;
}

