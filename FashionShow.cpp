/*
 * FashionShow.cpp
 *
 *  Created on: Apr 8, 2017
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


int N,M;
vector<char> model;
vector<pair<int,int>> pos;

bool place(int r, int c, vector<vector<char>>& grid){
	bool x_flag = false;
	for(int prev_r = 0; prev_r < N; prev_r++){
			if(grid[prev_r][c] != '0' && grid[prev_r][c] == '+' && x_flag == 0){
				x_flag = true;
				continue;
			}
	}
	return true;
}

int main(){
	int x,y;
	char c;
	read("input");
	int tc;
	cin >> tc;
	while(tc--){
		cin >> N >> M;
		for(int i = 0; i < M; i++){
			cin >> c >> x >> y;
			model.push_back(c);
			pos.push_back(make_pair(x-1,y-1)); //switch to zero based indexing
		}
		vector<vector<char>> grid(N,vector<char>(N,'0')); //2D grid

		for(int i = 0; i < M; i++){
			grid[pos[i].first][pos[i].second] = model[i];
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
}



