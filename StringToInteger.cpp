/*
 * StringToInteger.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: iNviNciBLe
 */
#include <iostream>
#include <string>
#include <climits>

using namespace std;

int myAtoi(string str) {
int res = 0, i = 0, sign = 1;
while(str[i] == ' ') i++; //skipping spaces
//Condition to handle sign if present. By default sign is 1 i.e +;
if(str[i] == '+' || str[i] == '-'){
	sign = 1 - 2 * (str[i] == '-');
	i++;
}
//Condition to check overflow
while(str[i]>='0' && str[i] <= '9'){
	if(res > INT_MAX/10 || (res == INT_MAX/10 && str[i] - '0' > 7)){
		if (sign == 1) return INT_MAX;
		            else return INT_MIN;
	}
	//Calculating the result
	res  = 10 * res + (str[i++] - '0');
}
return res * sign;
}

int main(){
	string str = "-2147483647";
	int res =  myAtoi(str);
	cout << res;
	return 0;
}



