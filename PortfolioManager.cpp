/*
 * PortfolioManager.cpp
 *
 *  Created on: May 7, 2017
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
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <fstream>

using namespace std;

#include <bits/stdc++.h>
#define rep(i,n) for(size_t i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int, int> mii;
typedef map<st, int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct Tree {
	string data;
	Tree* left;
	Tree* right;
	Tree() {
		data = "";
		left = NULL;
		right = NULL;
	};
};

Tree* createNode(string val) {
	Tree *p = new Tree;
	p->data = val;
	p->left = NULL;
	p->right = NULL;
	return p;
}

Tree* level_order_insert(Tree* root, vector<string>& arr, int start, int size) {
	Tree *tobj;
	int left = 2 * start + 1;
	int right = 2 * start + 2;

	if (left > size || right > size)
		return nullptr;

	if (root == NULL) {
		tobj = createNode(arr[start]);
		root = tobj;
	}

	if (root->left == NULL && root->right == NULL) {
		if (left < size)
			root->left = createNode(arr[left]);
		if (right < size)
			root->right = createNode(arr[right]);
	}
	level_order_insert(root->left, arr, left, size);
	level_order_insert(root->right, arr, right, size);
	return root;
}

vector<vector<string>> levelOrder(Tree* n) {
	vector<vector<string> > result;
	if (!n)
		return result;
	queue<Tree*> q;
	q.push(n);
	q.push(NULL); // Push null to check if level is done or not
	vector<string> cur_vec;
	while (!q.empty()) {
		Tree* t = q.front();
		q.pop();
		if (t == NULL) {
			result.push_back(cur_vec);
			cur_vec.resize(0);
			if (q.size() > 0) {
				q.push(NULL);
			}
		} else {
			cur_vec.push_back(t->data);
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
		}
	}
	return result;
}

/*int main() {
	vector<string> A = { "1", "2", "3", "#", "#", "4", "#", "#", "5" };
	Tree *tobj = nullptr;
	Tree * n = level_order_insert(tobj, A, 0, A.size());
	vector<vector<string>> res =  levelOrder(n);
	for(auto &i : res){
		for(auto &j: i){
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}*/

