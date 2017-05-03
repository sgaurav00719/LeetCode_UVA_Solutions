/*
 * UVa12455.cpp
 *
 *  Created on: Jan 21, 2017
 *      Author: iNviNciBLe
 *
 *      Some things grow if you put them together.
We have some metallic bars, theirs length known, and, if necessary, we want to solder some of them
in order to obtain another one being exactly a given length long. No bar can be cut up. Is it possible?
Input
The first line of the input contains an integer,t, 0 ≤ t ≤ 50, indicating the number of test cases. For
each test case, three lines appear, the first one contains a number n, 0 ≤ n ≤ 1000, representing the
length of the bar we want to obtain. The second line contains a number p, 1 ≤ p ≤ 20, representing the
number of bars we have. The third line of each test case contains p numbers, representing the length
of the p bars.
Output
For each test case the output should contain a single line, consists of the string ‘YES’ or the string ‘NO’,
depending on whether solution is possible or not.
Sample Input
4
25
4
10 12 5 7
925
10
45 15 120 500 235 58 6 12 175 70
120
5
25 25 25 25 25
0
2
13 567
Sample Output
NO
YES
NO
YES
 */

/*
 * Practice.cpp
 *
 *  Created on: Jan 15, 2017
 *      Author: iNviNciBLe
 */
/*
 * ik.yola
 *
 *
 *
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
typedef map<int, int> mii;
typedef map<st, int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define mx 0

int main() {
	read("input");
	int tc=0,x,N,sum;
	string res_string = "NO";
	scanf("%d", &tc);
	while ( tc-- ) {
		bool res = false;
		scanf("%d %d",&x, &N);
		int p[N];
		for (int i = 0; i < N; i++)
			scanf("%d",&p[i]);
		for (int i = 0; i < (1 << N); i++) {
			sum = 0;
			for (int j = 0; j < N; j++)
				if (i & (1 << j))
					sum += p[j];
			if (sum == x) {res = true; break;}
		}
		printf("%s\n", res ? "YES" : "NO");
	}
}





