/*
 * AdvanceCppPractice.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: iNviNciBLe
 */

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
#include <fstream>

using namespace std;

class Dog{
private:
	int age;
	string name;
public:
	Dog(){
		age = 0;
		name = "dummy";
	}
	void setAge(const int &a){
		age = a;
	}
	void setName(const string &n){
		name = n;
	}
	const int& getAge(){
		return this->age;
	}
	const string& getName(){
		return this->name;
	}
};

int main(){
	Dog g;
	int a = 15;
	string n = "jivu";
	g.setAge(a);
	g.setName(n);
	cout << g.getAge()<< " " << g.getName();
	return 0;
}


