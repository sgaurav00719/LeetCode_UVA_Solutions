/*
 * BinaryTreeLevelOrderTraversal.cpp
 *
 *  Created on: Jan 30, 2017
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

using namespace std;

// Node class
class Node {
public:
	int key;
	Node* left;
	Node* right;
public:
	Node() {
		key = -1;
		left = NULL;
		right = NULL;
	}
	;
	void setKey(int aKey) {
		key = aKey;
	}
	;
	void setLeft(Node* aLeft) {
		left = aLeft;
	}
	;
	void setRight(Node* aRight) {
		right = aRight;
	}
	;
	int Key() {
		return key;
	}
	;
	Node* Left() {
		return left;
	}
	;
	Node* Right() {
		return right;
	}
	;
};

// Tree class
class Tree {
	Node* root;
public:
	Tree();
	~Tree();
	Node* Root() {
		return root;
	}
	;
	void addNode(int key);
	void inOrder(Node* n);
	void preOrder(Node* n);
	void postOrder(Node* n);
	vector<vector<int>> levelOrder(Node* n);
	bool isPresent(Node* n, int val);
	int count(Node* n);
	int height(Node* n);
	Node* lowestCommonAncestor(Node* root, int p, int q);
	bool isBalanced(Node* root);
	int dfs(Node* root);
	int getMinimumDifference(Node* root);
private:
	void addNode(int key, Node* leaf);
	void freeNode(Node* leaf);
};

// Constructor
Tree::Tree() {
	root = NULL;
}

// Destructor
Tree::~Tree() {
	freeNode(root);
}

// Free the node
void Tree::freeNode(Node* leaf) {
	if (leaf != NULL) {
		freeNode(leaf->Left());
		freeNode(leaf->Right());
		delete leaf;
	}
}

// Add a node
void Tree::addNode(int key) {
	// No elements. Add the root
	if (root == NULL) {
		cout << "add root node ... " << key << endl;
		Node* n = new Node();
		n->setKey(key);
		root = n;
	} else {
		cout << "add other node ... " << key << endl;
		addNode(key, root);
	}
}

// Add a node (private)
void Tree::addNode(int key, Node* root) {
	if (key <= root->Key()) {
		if (root->Left() != NULL)
			addNode(key, root->Left());
		else {
			Node* n = new Node();
			n->setKey(key);
			root->setLeft(n);
		}
	} else {
		if (root->Right() != NULL)
			addNode(key, root->Right());
		else {
			Node* n = new Node();
			n->setKey(key);
			root->setRight(n);
		}
	}
}

// Print the tree in-order
// Traverse the left sub-tree, root, right sub-tree
void Tree::inOrder(Node* n) {
	if (n) {
		inOrder(n->Left());
		cout << n->Key() << " ";
		inOrder(n->Right());
	}
}

// Print the tree pre-order
// Traverse the root, left sub-tree, right sub-tree
void Tree::preOrder(Node* n) {
	if (n) {
		cout << n->Key() << " ";
		preOrder(n->Left());
		preOrder(n->Right());
	}
}

// Print the tree post-order
// Traverse left sub-tree, right sub-tree, root
void Tree::postOrder(Node* n) {
	if (n) {
		postOrder(n->Left());
		postOrder(n->Right());
		cout << n->Key() << " ";
	}
}

// Print the tree level-order
/*Explanation: The Basic idea is to push NULL on
 * to the queue when a level finishes. Null is used
 * to keep track of the current level and when it ends.
 * When we get a null value we reset the vector used for
 * storing the elements at current level and pushes NULL
 * again on to the queue. If we dont get NULL while traversing
 * through the tree we do three things : 1) push the current value
 * on to the vector. 2) Push left child if present on the queue. 3) Push right
 * child if present on the queue.
 * Time complexity: O(n) where n is number of nodes in the binary tree.
 * */

vector<vector<int>> Tree::levelOrder(Node* n) {
	vector<vector<int> > result;
	if (!n)
		return result;
	queue<Node*> q;
	q.push(n);
	q.push(NULL); // Push null to check if level is done or not
	vector<int> cur_vec;
	while (!q.empty()) {
		Node* t = q.front();
		q.pop();
		if (t == NULL) {
			result.push_back(cur_vec);
			cur_vec.resize(0);
			if (q.size() > 0) {
				q.push(NULL);
			}
		} else {
			cur_vec.push_back(t->Key());
			if (t->Left())
				q.push(t->Left());
			if (t->Right())
				q.push(t->Right());
		}
	}
	return result;
}

/*Is present using level order traversal
 * This is better than recursive approach*/
bool Tree::isPresent(Node* root, int val) {
	if (!root)
		return false;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* t = q.front();
		q.pop();
		if (val == t->Key())
			return true;
		if (val < t->Key() && t->Left())
			q.push(t->Left());
		if (val > t->Key() && t->Right())
			q.push(t->Right());
	}
	return false;
}

/*
 * Function to count number of nodes
 */
int Tree::count(Node* root) {
	if (root == nullptr)
		return 0;
	return count(root->Left()) + count(root->Right()) + 1;
}

/** Function to get height of the tree
 */
int Tree::height(Node* root) {
	if (!root)
		return -1;
	return 1 + max(height(root->Left()), height(root->Right()));
}

/* Invert Binary Tree
 * */

/*Lowest Common Ancestor of a Binary Tree*/
Node* Tree::lowestCommonAncestor(Node* root, int p, int q) {
	if (!root || root->key == p || root->key == q)
		return root;
	Node* left = lowestCommonAncestor(root->left, p, q);
	Node* right = lowestCommonAncestor(root->right, p, q);
	if (left && right)
		return root;
	return left != nullptr ? left : right;
}

/**
 Balance binary tree
 *
 * Given a binary tree, determine if it is height-balanced.
 For this problem, a height-balanced binary tree is defined
 as a binary tree in which the depth of the two subtrees of every
 node never differ by more than 1.
 */

bool Tree::isBalanced(Node* root) {
	return dfs(root) != -1;
}

int Tree::dfs(Node* node) {
	if (!node)
		return 0;
	int leftH = dfs(node->left);
	if (leftH == -1)
		return -1;
	int rightH = dfs(node->right);
	if (rightH == -1)
		return -1;
	if (abs(rightH - leftH) > 1)
		return -1;
	return max(rightH, leftH) + 1;
}

/*Minimum Absolute Difference in BST
 *
 * Given a binary search tree with non-negative values,
 * find the minimum absolute difference between values of any two nodes.
 * */
int inOrderTraversalHelper(Node* root, int &val, int &minDiff){
	if(root->left != nullptr) inOrderTraversalHelper(root->left,val,minDiff);
	if(val >= 0) minDiff = min(minDiff,root->Key() - val);
	val = root->Key();
	if(root->right != nullptr) inOrderTraversalHelper(root->right,val,minDiff);
	return minDiff;
}

int Tree::getMinimumDifference(Node* root) {
	int val = -1, minDiff = INT_MAX;
	return inOrderTraversalHelper(root,val,minDiff);
}

// Test main program
int main() {
	Tree* tree = new Tree();
	tree->addNode(40);
	tree->addNode(20);
	tree->addNode(10);
	tree->addNode(30);
	tree->addNode(60);
	tree->addNode(50);
	tree->addNode(70);

	/*int h = tree->height(tree->Root());
	 cout << "\nHeight of tree: " << h;*/

	cout << "\nIn order traversal" << endl;
	tree->inOrder(tree->Root());
	cout << endl;

	cout << "Pre order traversal" << endl;
	tree->preOrder(tree->Root());
	cout << endl;

	cout << "Post order traversal" << endl;
	tree->postOrder(tree->Root());
	cout << endl;

	/* cout<< "Level order traversal" << endl;
	 vector<vector<int>> res = tree->levelOrder(tree->Root());
	 for(auto vec : res)
	 {
	 for(auto x : vec)
	 std::cout<< x << " ";
	 std::cout << std::endl;
	 }

	 cout << tree->isPresent(tree->Root(),70) << endl;

	 int num = tree->count(tree->Root());
	 cout << "\nNumber of nodes in the tree: " << num;*/

	Node * tmp = tree->lowestCommonAncestor(tree->Root(), 10, 30);
	cout << "Lowest Common Ancestor: " << tmp->key << endl;

	int minDiff = tree->getMinimumDifference(tree->Root());
	cout << "Minimum Absolute Difference in BST: " << minDiff << endl;

	delete tree;
	return 0;
}

