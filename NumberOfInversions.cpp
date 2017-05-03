/*
 * NumberOfInversions.cpp
 *
 *  Created on: Jan 29, 2017
 *      Author: iNviNciBLe
 */




/*
 * C++ Program to Count Inversion in an Array
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

template <typename T>
long long mergeSortAndCountInversions(T* arr, int size)
{
  int m;

	if (size <= 1)
		return 0;

	m = size / 2;

	long long invCountA = 0, invCountB = 0, invCountC = 0;
	invCountA = mergeSortAndCountInversions(arr, m);
	invCountB = mergeSortAndCountInversions(arr + m, size - m);

	T* arrPartA = new T[m];
	T* arrPartB = new T[size - m];

	memcpy(arrPartA, arr, sizeof(T) * m);
	memcpy(arrPartB, arr + m, sizeof(T) * (size - m));

	int i = 0, j = 0, k = 0;

	while (k < size)
	{
		if (arrPartA[i] < arrPartB[j])
		{
			arr[k] = arrPartA[i];
			i++;

			invCountC += j;
		}
		else
		{
			arr[k] = arrPartB[j];
			j++;

			invCountC += 1;
		}

		k++;

		if (i >= m || j >= (size - m))
			break;
	}

	invCountC -= j;

	while (i < m)
	{
		arr[k] = arrPartA[i];
		k++;
		i++;

		invCountC += j;
	}
	while (j < (size - m))
	{
		arr[k] = arrPartB[j];
		k++;
		j++;
	}

	delete []arrPartA;
	delete []arrPartB;

	return (invCountA + invCountB + invCountC);
}

/*
 * Main
 */
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int arr[100000];

		for (int i = 0; i < 100000; ++i)
		{
			scanf("%d", &arr[i]);
		}
		long long invCount = mergeSortAndCountInversions(arr, sizeof(arr) / sizeof(arr[0]));

			printf("Inversion count: %lld\n", invCount);
    return 0;
}
