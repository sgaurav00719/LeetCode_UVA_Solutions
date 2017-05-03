/*
 * version-test.cpp
 *
 *  Created on: Dec 31, 2016
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
#include <bitset>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0;
    for (int k = 0;k < n;k++) {
        while (i < m && B[i] < A[k])
            i++;
        if (A[k] == B[i])
            return A[k];
    }
    return -1;
}

int main(){
vector<int> v1 = {2,1};
vector<int> v2 = {3,3};
cout << solution(v1,v2);
	return 0;
}

