/*
 * driver.cpp
 *
 *  Created on: Jan 21, 2017
 *      Author: iNviNciBLe
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
#include <array>


#include "SortingFunctions.h"

using namespace std;

int main(){
	array<int,5> arr = {2,5,4,1,3};
	int length = arr.size();
	printf("Array before sorting:\n");
	for(int i = 0; i < length; i++) printf("%d ", arr[i]);
	insertion_sort(arr,length);
	printf("\n Array after sorting:\n");
	for(int i = 0; i < length; i++) printf("%d ",arr[i]);
	return 0;
}


