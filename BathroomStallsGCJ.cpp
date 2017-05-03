/*
 * BathroomStallsGCJ.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: Ik.Yola
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

void place (){
	cout << "set function";
}

int main() {
	read("test");
	int tc;
	cin >> tc;
	while(tc--){
		i64 N,K;
		cin >> N >> K;
		vi stalls(N+2,0);
		stalls[0] = 1;
		stalls[N+1] = 1;
		for(int i = 0; i < N+2 ; i++){
			cout << stalls[i] << " ";
		}
		place();
	}
	return 0;
}


