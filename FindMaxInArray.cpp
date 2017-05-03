/*
 * FindMaxInArray.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: iNviNciBLe
 */
#include <bits/stdc++.h>
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

template <typename T>
int findMaxIterative(vector<T>& v){
	T t = v[0];
	for(size_t i = 1; i < v.size(); i++)
		if(v[i] > t) t = v[i];
	return t;
}

template <typename T>
int findMaxDivideConquer(vector<T>&a, int l , int r){
	if(l == r) return a[l];
	int m = l + (r-l)/2;
	T u = findMaxDivideConquer(a,l,m);
	T v = findMaxDivideConquer(a,m+1,r);
	if(u > v) return u;
	else return v;
}
int main(){
	vector<int> v = {1100,2,30,4,5,6,90,101,7,1000};
	cout << "Iterative Solution " << (findMaxIterative(v)) << endl;
	cout << "Divide and Concure Solution:" << (findMaxDivideConquer(v,0,v.size()-1)) << endl;
	return 0;
}



