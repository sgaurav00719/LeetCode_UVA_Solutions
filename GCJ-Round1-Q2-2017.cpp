/*
 * GCJ-Round1-Q2-2017.cpp
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
	read("test");
	rite("testO");
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		string c;
		for(int i = 0; i < 6; i++){
			int tmp = 0;
			switch(i){
			case 0: {
				cin >> tmp;
				for(int i = 0 ; i < tmp; i++){
					c.push_back('R');
				}
			}break;
			case 1:{
				cin >> tmp;
				for(int i = 0 ; i < tmp; i++){
					c.push_back('O');
				}

			}break;
			case 2:{
				cin >> tmp;
				for(int i = 0 ; i < tmp; i++){
					c.push_back('Y');
				}

			}break;
			case 3:{
				cin >> tmp;
				for(int i = 0 ; i < tmp; i++){
					c.push_back('G');
				}
			}break;
			case 4:{
				cin >> tmp;
				for(int i = 0 ; i < tmp; i++){
					c.push_back('B');
				}
			}break;
			case 5:{
				cin >> tmp;
				for(int i = 0 ; i < tmp; i++){
					c.push_back('V');
				}
			}break;
			}
		}
		do{
			cout << c << endl;
		}while(next_permutation(c.begin(),c.end()));
	}
	return 0;
}


