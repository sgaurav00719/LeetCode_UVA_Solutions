/*
 * UVa725_CP3.cpp
 *
 *  Created on: Jan 15, 2017
 *      Author: iNviNciBLe
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
int N;
int count = 0;
while (scanf("%d",&N),N){
	bool found = false;
	count++;
	if (count > 1)
	printf("\n");
	if(N == 0) exit(0);
	for(int fghij = 1234; fghij <= 98765/N; fghij++){
		int abcde = fghij * N;
		int tmp, used = (fghij < 10000 );
		tmp = abcde; while (tmp) {used |= 1 << (tmp % 10); tmp /= 10;}
		tmp = fghij; while (tmp) {used |= 1 << (tmp % 10); tmp /= 10;}
		if(used == (1 << 10) - 1){
			printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
			found = true;
		}
	}
	if (found != true)
		printf("There are no solutions for %d.\n",N);
}
	return 0;
}


