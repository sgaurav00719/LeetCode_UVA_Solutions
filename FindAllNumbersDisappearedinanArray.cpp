/*
 * FindAllNumbersDisappearedinanArray.cpp
 *
 *  Created on: Apr 10, 2017
 *      Author: iNviNciBLe
 *
 *
 *      Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

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

/*The basic idea is that we iterate through the input array and mark elements
 * as negative using nums[nums[i] -1] = -nums[nums[i]-1].
 * In this way all the numbers that we have seen will be marked as negative.
 * In the second iteration, if a value is not marked as negative,
 * it implies we have never seen that index before, so just add it to the return list.
 * */

vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> res;
	for(size_t i  = 0; i < nums.size(); i++){
		int v = abs(nums[i]) - 1;
		if(nums[v] > 0){
			nums[v] = - nums[v];
		}
	}
	for(size_t i = 0; i < nums.size(); i++)
		if(nums[i] > 0)
			res.push_back(i+1);
	return res;
}

int main(){

	vector <int> v = {1,3,3};
	vector<int> res = findDisappearedNumbers(v);
	for(auto i: res)
		cout << i << " ";
}



