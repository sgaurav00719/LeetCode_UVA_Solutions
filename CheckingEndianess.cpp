/*
 * CheckingEndianess.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: iNviNciBLe
 */

#include <iostream>
#include <cstdio>

using namespace std;
/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n)
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2x", start[i]);
    printf("\n");
}

int main(){
	unsigned int i = 0x01234567;
	char *c = (char*)&i;
	if (*c)
	       printf("Little endian\n");
	   else
	       printf("Big endian\n");
	show_mem_rep(c,sizeof i);
	return 0;
}


