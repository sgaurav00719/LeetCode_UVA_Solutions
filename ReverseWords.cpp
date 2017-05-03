/*
 * ReverseWords.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: iNviNciBLe
 *
 *
 *       Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
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

using namespace std;

// function to reverse any part of string from i to j (just one word or entire string)
    void reverseword(string &s, int i, int j){
        while(i<j){
          char t=s[i];
          s[i++]=s[j];
          s[j--]=t;
        }
    }

    void reverseWords(string &s) {

        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;

        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ')
            {
            	s[j]=s[i];
            	j++;
            	i++;
            }
            reverseword(s,l,j-1);                // reverse word in place
            wordcount++;

        }

        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);                  // reverse whole string
    }

    int main(){
    	string str = " 1";
    	reverseWords(str);
    	cout << str;
    	return 0;
    }


