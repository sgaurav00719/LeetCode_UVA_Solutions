/*
 * FindNthNodeFromEndOfList.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: iNviNciBLe
 */

#include <iostream>

using namespace std;

struct ListNode{
	int data;
	ListNode *next;
	ListNode (int x) : data(x), next(nullptr) {}
};

void insertAtHead(ListNode *&head, int data){
	ListNode *newNode = new ListNode(data);
	newNode->next = head;
	head = newNode;
}

void printList(ListNode *head){
	while(head){
		cout << head->data << "->";
		head = head->next;
	}
	cout << "nullptr" << endl;
}

void printNthNodeFromEnd(ListNode *& head,int n){
	ListNode *main = head,*ref = head;
	int count = 0;
	if(head != nullptr){
		while(count < n){
			if(ref == nullptr){
				cout << n << " is greater than the no. of nodes in the list" << endl;
				return;
			}
		ref = ref->next;
		count++;
		}
		while(ref != nullptr){
			main = main->next;
			ref = ref->next;
		}
		cout << "Node no. "<< n << " from last is " << main->data << endl;
	}
}

void reverseList(ListNode *&head){
	ListNode *curr = head, *prev = nullptr, *tmp = nullptr;
	while(curr != nullptr){
		tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	head = prev;
}

void reverseListRecursive(ListNode *& head){
	if(head == nullptr) return;
	ListNode *rest = head->next;
	if(rest == nullptr)return;
	reverseListRecursive(rest);
	head->next->next = head;
	head->next = nullptr;
	head = rest;
}

bool hasCycle(ListNode *head){
	if(head == nullptr) return false;
	ListNode *slow = head, *fast = head;
	while(fast && slow && fast -> next){
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)
			return true;
	}
	return false;
}

int main(){
	ListNode *list = nullptr;
	insertAtHead(list, 3);
	insertAtHead(list, 2);
	insertAtHead(list, 1);
	printList(list);
	printNthNodeFromEnd(list,1);
	reverseList(list);
	printList(list);
	printNthNodeFromEnd(list,1);
	return 0;
}




