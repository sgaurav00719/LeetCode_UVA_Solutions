/*
 * Fib.cpp
 *
 *  Created on: Feb 18, 2017
 *      Author: iNviNciBLe
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <climits>
using namespace std;

//using top down dynamic programming also known as memoization.

long long Fib(long long i){
	static long long knownFib[INT_MAX];
	if(knownFib[i] != 0) return knownFib[i];
	long long t = i;
	if(i < 0) return 0;
	if(i > 1) t = Fib(i-1) + Fib(i-2);
	return knownFib[i] = t;
}

int main(){
	cout << Fib(12LL);
	return 0;
}




