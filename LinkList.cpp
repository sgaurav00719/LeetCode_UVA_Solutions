#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

/*Node Declaration*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode (int x) : val(x), next(nullptr) {}
};

/**
 * [insert - insert a new node at head of the list]
 * @param head [head of the list]
 * @param data [new node's data]
 */
void insertAtHead( ListNode* &head, int val ) {
  ListNode * newNode = new ListNode(val);
  newNode->next = head;
  head = newNode;
}

/* Reversing a link list iterative.
 * */
ListNode* reverse(ListNode*& head){
	ListNode *curr = head,*prev = NULL,*tmp;
	while(curr){
		tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	head = prev;
	return head;
}

/* Reversing a link list recursive.
 * */
ListNode* reverseRecursive(ListNode*& head) {
  if (!head) return NULL;
  ListNode* rest = head->next;
  if (!rest) return NULL;
  reverseRecursive(rest);
  head->next->next = head;
  head->next = NULL;
  head = rest;
  return head;
}



/**
 * [printList - print the list]
 * @param head [head of the list]
 */
void printList( ListNode * head ) {
  while ( head ) {
    std::cout << head->val << "-->";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}

/*Adding LinkList Question 1*/
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2){
if(l1 == nullptr && l2 == nullptr) return nullptr;
ListNode* current1 = l1 ,*current2 = l2;
vector<int> v1,v2;
	while(current1){
		v1.push_back(current1->val);
		current1 = current1 -> next;
	}

	 while(current2){
                v2.push_back(current2->val);
                current2 = current2 -> next;
        }

	int sum = 0, carry = 0, placeValue = 0,n1 = v1.size() - 1,n2 = v2.size() -1;
	 ListNode *head = new ListNode(0), *p = head;
	for(int i = 0, j = 0; i <= n1 || j <= n2 || carry > 0;){
		sum = carry;
		if(i <= n1)
			sum += v1[i++];
		if(j <= n2)
			sum += v2[j++];
		carry = sum/10;
		placeValue = sum%10;
		p = p->next = new ListNode(placeValue);
	}
return head->next;
}

/*Adding LinkList Question 2*/

ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2){
ListNode* current1 = l1 ,*current2 = l2;
vector<int> v1,v2;
	while(current1){
		v1.push_back(current1->val);
		current1 = current1 -> next;
	}

	 while(current2){
                v2.push_back(current2->val);
                current2 = current2 -> next;
        }

	int sum = 0, carry = 0, placeValue,n1 = v1.size() - 1,n2 = v2.size() -1;
	 ListNode *head = nullptr, *p = nullptr;
	for(int i = n1, j = n2; i >= 0 || j >= 0 || carry > 0; i--,j--){
		sum = carry;
		if(i >= 0)
			sum += v1[i];
		if(j >= 0)
			sum += v2[j];
		carry = sum/10;
		placeValue = sum%10;
		p = new ListNode(placeValue);
		p -> next = head;
		head = p;
	}
return p;
}

/* Program to remove duplicates in an unsorted array */

ListNode* removeDups(ListNode* head){
	ListNode *ptr1, *ptr2, *dup;
	 ptr1 = head;

	  /* Pick elements one by one */
	  while(ptr1 != NULL && ptr1->next != NULL)
	  {
	     ptr2 = ptr1;

	     /* Compare the picked element with rest of the elements */
	     while(ptr2->next != NULL)
	     {
	       /* If duplicate then delete it */
	       if(ptr1->val == ptr2->next->val)
	       {
	          /* sequence of steps is important here */
	          dup = ptr2->next;
	          ptr2->next = ptr2->next->next;
	          free(dup);
	       }
	       else /* This is tricky */
	       {
	          ptr2 = ptr2->next;
	       }
	     }
	     ptr1 = ptr1->next;
	  }
	  return head;
}

/*Program to detect cycles in a linked list*/

bool hasCycle(ListNode *head){
	if(head == nullptr) return false;
	ListNode*fast = head,*slow = head;
	while(fast && slow && fast -> next){
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow)
			return true;
	}
	return false;
}

//Merging sorted two Linked List
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
  ListNode * list1 = nullptr;
  insertAtHead(list1, 3);
  insertAtHead(list1, 2);
  insertAtHead(list1, 1);
  std::cout << "List1:  ";
  printList(list1);

  //making list2 for number 295
  ListNode * list2 = nullptr;
  insertAtHead(list2, 10);
  insertAtHead(list2, 7);
  insertAtHead(list2, 0);
  std::cout << "List2:  ";
  printList(list2);

ListNode * list3 = addTwoNumbers2(list1, list2);
  std::cout << "Iterative Solution: \n";
  std::cout << "List3:  ";
  printList(list3);

 ListNode * reverseList = reverse(list1);
 printList(reverseList);
 ListNode * reverseListRecursive = reverseRecursive(list1);;
 printList(reverseListRecursive);

 ListNode * list4 = nullptr;
 insertAtHead(list4,1);
 insertAtHead(list4,2);
 insertAtHead(list4,3);
 insertAtHead(list4,2);
 insertAtHead(list4,1);
 cout<<"\nElements in list4 ";
 printList(list4);
removeDups(list4);
 cout << "\nElements after deleting duplicates in the list4 are: ";
 printList(list4);
 cout<<"\nDoes list has a cycle? ";
 list4->next->next->next = list4; //Create a loop for testing
 cout << hasCycle(list4);
 cout << "\nMerging Two List (List 1 and List 2): ";
 ListNode* list5 = mergeTwoLists(list1,list2);
 printList(list5);
return 0;
}
