/*
 * Voting.cpp
 *
 *  Created on: May 7, 2017
 *      Author: iNviNciBLe
 */
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

bool sortbysec(const pair<int,string> &a,
              const pair<int,string> &b)
{
	if(a.first == b.first){
		return(a.second > b.second);
	}
    return (a.first > b.first);
}

string selectionWinner(vector<string> &v){

	unordered_map<string,long> m;
	vector<pair<int,string>> vpis;
	for(size_t i = 0; i < v.size(); i++){
		m[v[i]]++;
	}
	for(auto i : m){
		vpis.push_back(make_pair(i.second,i.first));
	}
	sort(vpis.begin(),vpis.end(),sortbysec);
	return vpis[0].second;

}

/*int main(){
	read("test");
	rite("testO");
	int N;
	cin >> N;
	vector<string> v(N);
	for(auto i = 0; i < N ; i++){
		cin >> v[i];
	}
	string res = selectionWinner(v);
cout << res;
	return 0;
}*/



