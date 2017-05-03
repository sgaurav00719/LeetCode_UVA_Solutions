/*
 * FindSquares.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: iNviNciBLe
 */


// An Efficient Method to count squares between a and b
#include<bits/stdc++.h>
using namespace std;

// An efficient solution to count square between a
// and b
int countSquares(int a, int b)
{
    return (floor(sqrt(abs(b))) - ceil(sqrt(abs(a))) + 1);
}

// Driver code
int main()
{
    int a = -9, b = -25;
    cout << "Count of squares is "
         << countSquares(a, b);
    return 0;
}

