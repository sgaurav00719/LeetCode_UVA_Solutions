/*
 * MergeSort.cpp
 *
 *  Created on: Jan 15, 2017
 *      Author: iNviNciBLe
 */
#include<cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

template <class Item>
void mergeAB(Item a[], Item b[], Item c[], int N, int M){
	for(int i = 0, j =0, k = 0; k < N+M; k++){
		if(i == N) {c[k] = b[j++];continue;}
		if(j == M) {c[k] = a[i++];continue;}
		c[k] = (a[i]<b[j]) ? a[i++]  : b[j++];
	}
}

/*Merge two sorted linked lists and return it as a new list. */

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode head(0);
		ListNode* c = &head;
		while((l1 != NULL && l2 != NULL)){
			if(l1->val < l2->val)
			{
				c->next = l1; l1 = l1->next;
			}
			else
			{
				c->next = l2; l2 = l2->next;
			}
			c = c -> next;
		}
			c -> next = (l1 == NULL) ? l2 : l1;
		return head.next;
    }

int main(){
	return 0;
}
