/*
 * SegmentSort.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: iNviNciBLe
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

string segmentSort(string s){
	string res = "",tmp = "";
	char current;
	for(size_t i = 0; i < s.length()+1;i++){
		if(i == 0)
			current = s[0];
		else
			current = s[--i];
		if(isdigit(current)){
			while(i < s.length() && isdigit(s[i])){
				tmp += s[i++];
			}
			sort(tmp.begin(),tmp.end());
			res.append(tmp);
			tmp="";
		}
		else if(current == ' '){
			tmp += s[i++];
		}
		else{
			while(i < s.length() && isalpha(s[i])){
				tmp += s[i++];
			}
			sort(tmp.begin(),tmp.end());
			res.append(tmp);
			tmp="";
		}
	}
	return res;
}
int main(){
	string res = segmentSort("321ba321dc1zy8");
	cout << res;
	return 0;
}


