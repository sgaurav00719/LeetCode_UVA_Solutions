/*
 * HashFunctionForStrings.cpp
 *
 *  Created on: Feb 19, 2017
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
//M is the size of table
int hashForStringKeys(const char * v, int M){
	int h = 0, a =127; //Using 127 instead of 128
	for(;*v != 0; v++)
		h = (a*h + *v) % M;
	return h;
}

int universalHashForStringKeys(const char * v, int M){
	int h, a =31415, b = 27183; //a,b are seed values
	for(h = 0;*v != 0; v++, a =a*b%(M-1))
		h = (a*h + *v) % M;
	return (h < 0) ? (h+M) : h;
}

int main(){
	string s = "wow";
	const char *c = s.c_str();
	int res = hashForStringKeys(c,96);
	int res1 = universalHashForStringKeys(c,96);
 	cout << res << " " <<res1;
	return 0;
}


