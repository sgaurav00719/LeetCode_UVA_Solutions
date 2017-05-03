/*
 * UniqueAndMostRecentURLs.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: iNviNciBLe
 */
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <unordered_map>

#define read(x) freopen(x,"r",stdin);

using namespace std;

list<string> URLs;    // doubly linked list   a.k.a. the visit order
unordered_map<string, list<string>::iterator> checkMap;     // hashtable

void visit(const string& url){
	auto it = checkMap.find(url);

	  if(it != checkMap.end())
	    URLs.erase(it->second);     // remove a previous instance of this URL from the visit order

	  checkMap[url] = URLs.insert(URLs.end(), url);     // insert URL at the latest of the visit order
}

void printVisitOrder() {
	  for(auto it = URLs.rbegin(); it != URLs.rend(); ++it)   // reverse iteration to go from latest to oldest
	    cout << *it << endl;
}

int main()
{
	read("input");
	string s;
	vector<string> url;
	while(cin >> s){
		visit(s);
	}
	printVisitOrder();
	return 0;
}



