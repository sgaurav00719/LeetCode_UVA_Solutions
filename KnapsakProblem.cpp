/*
 * KnapsakProblem.cpp
 *
 *  Created on: Feb 18, 2017
 *      Author: iNviNciBLe
 */


// A Dynamic Programming based solution for 0-1 Knapsack problem

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

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, vector<int>& wt, vector<int>& val, int n)
{
   int i, j;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= W; j++)
       {
           if (i==0 || j==0)
               K[i][j] = 0;
           else if (wt[i-1] <= j)
                 K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]);
           else
                 K[i][j] = K[i-1][j];
       }
   }

   return K[n][W];
}

int main()
{
    vector<int> val = {60, 100, 120};
    vector <int> wt = {1, 2, 3};
    int  W = 5;
    int n = val.size();
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}

