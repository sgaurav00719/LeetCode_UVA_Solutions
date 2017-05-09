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
	int data;
	Tree* left;
	Tree* right;
	Tree() {
		data = 0;
		left = NULL;
		right = NULL;
	};
};

Tree* createNode(int val) {
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
		tobj = createNode(stoi(arr[start]));
		root = tobj;
	}

	if (root->left == NULL && root->right == NULL) {
		if (left < size){
			if(arr[left] == "#") root->left = createNode(0);
			else root->left = createNode(stoi(arr[left]));
		}
		if (right < size){
			if(arr[right] == "#") root->right = createNode(0);
			root->right = createNode(stoi(arr[right]));
		}
	}
	level_order_insert(root->left, arr, left, size);
	level_order_insert(root->right, arr, right, size);
	return root;
}

vector<vector<int>> levelOrder(Tree* n) {
	vector<vector<int> > result;
	if (!n)
		return result;
	queue<Tree*> q;
	q.push(n);
	q.push(NULL); // Push null to check if level is done or not
	vector<int> cur_vec;
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

pair<int, int> maxSumHelper(Tree *root)
{
    if (root==NULL)
    {
        pair<int, int> sum(0, 0);
        return sum;
    }
    pair<int, int> sum1 = maxSumHelper(root->left);
    pair<int, int> sum2 = maxSumHelper(root->right);
    pair<int, int> sum;

    // This node is included (Left and right children
    // are not included)
    sum.first = sum1.second + sum2.second + root->data;

    // This node is excluded (Either left or right
    // child is included)
    sum.second = max(sum1.first, sum1.second) +
                 max(sum2.first, sum2.second);

    return sum;
}

int maxSum(Tree *root)
{
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
}

int main() {
	vector<string> A = { "3", "4", "5", "1", "3", "#", "1"};
	Tree *tobj = nullptr;
	Tree * n = level_order_insert(tobj, A, 0, A.size());
	vector<vector<int>> res =  levelOrder(n);
	for(auto &i : res){
		for(auto &j: i){
			cout << j << " ";
		}
		cout << endl;
	}
	cout << "\n\n";
	cout << maxSum(n);
	return 0;
}

