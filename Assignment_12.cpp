#include <bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/*
<aside>
Question 1**

Given a singly linked list, delete **middle** of the linked list. For example, if given linked list is 1->2->**3**->4->5 then linked list should be modified to 1->2->4->5.If there are **even** nodes, then there would be **two middle** nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.If the input linked list is NULL or has 1 node, then it should return NULL

</aside>
*/

ListNode* deleteMiddle(ListNode* head) {
     if(head==NULL || head->next==NULL)   
         return NULL;
        
        ListNode *prev=NULL,*slow=head,*fast=head;
        
        while(fast!=NULL and fast->next!=NULL ){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        delete slow;
        return head;
}

/*
<aside>
💡 **Question 2**

Given a linked list of **N** nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

</aside>
*/
bool hasCycle(ListNode *head) {
	
        if(head == NULL)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        
            if(fast == slow)
                return true;
        }
        
		
        return false;
}

/*
<aside>
💡 **Question 3**

Given a linked list consisting of **L** nodes and given a number **N**. The task is to find the **N**th node from the end of the linked list.

</aside>
*/
 ListNode*Reverse(ListNode*&head){
     ListNode*curr=head;
     ListNode*prev=NULL;
     while(curr!=NULL){
         ListNode*forw=curr->next;
         curr->next=prev;
         prev=curr;
         curr=forw;
     }
     return prev;
 }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
      ListNode*temp1=Reverse(head);
      ListNode*temp=temp1;
      if(n==1){
        ListNode*del=temp1;
        temp1=temp1->next;
        delete del;
      }
      else{

      for(int i=0;i<n-2;i++){
          temp=temp->next;
      }
      ListNode*flag=temp->next;
      temp->next=flag->next;
      delete flag;
      }
      ListNode*ret=Reverse(temp1);
        return ret; 
        
}


/*
<aside>
💡 **Question 4**

Given a singly linked list of characters, write a function that returns true if the given list is a palindrome, else fals

</aside>
*/

bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL && fast->next == NULL){
            slow = slow->next;
        }
        ListNode *prev = NULL;
        ListNode *temp = NULL;
        while(slow != NULL && slow->next != NULL){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        if(slow != NULL){
            slow->next = prev;
        }
        fast = head;
        while(slow && fast){
            if(slow->val != fast->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
}


/*
<aside>
💡 **Question 5**

Given a linked list of **N** nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position X(1-based index). If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

</aside>
*/
void hashAndRemove(ListNode * head) {
  unordered_map < ListNode * , int > node_map;
  ListNode * last = NULL;
  while (head != NULL) {
    if (node_map.find(head) == node_map.end()) {
      node_map[head]++;
      last = head;
      head = head -> next;
    } else {
      last -> next = NULL;
      break;
    }
  }
}

/*
<aside>
💡 **Question 6**

Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same till end of the linked list.

Difficulty Level: Rookie

</aside>
*/
#include <bits/stdc++.h>
using namespace std;
  
// A linked list node 
class Node 
{ 
    public:
    int data; 
    Node *next; 
}; 
  

void skipMdeleteN(Node *head, int M, int N) 
{ 
    Node *curr = head, *t; 
    int count; 
    while (curr) 
    { 
      
        for (count = 1; count < M && 
                curr!= NULL; count++) 
            curr = curr->next; 
  
        if (curr == NULL) 
            return; 

        for (count = 1; count<=N && t!= NULL; count++) 
        { 
            Node *temp = t; 
            t = t->next; 
            free(temp); 
        } 
        curr->next = t;  
        curr = t; 
    } 
} 


/*
<aside>
💡 **Question 7**

Given two linked lists, insert nodes of second list into first list at alternate positions of first list.
For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6, the first list should become 5->12->7->10->17->2->13->4->11->6 and second list should become empty. The nodes of second list should only be inserted when there are positions available. For example, if the first list is 1->2->3 and second list is 4->5->6->7->8, then first list should become 1->4->2->5->3->6 and second list to 7->8.

Use of extra space is not allowed (Not allowed to create additional nodes), i.e., insertion must be done in-place. Expected time complexity is O(n) where n is number of nodes in first list.

</aside>
*/

#include <bits/stdc++.h>
using namespace std;
struct LLNode
{
    int data;
    struct LLNode* next;
};

void Merge(struct LLNode *A, struct LLNode **B)
{
     struct LLNode *current_inA = A, *current_inB = *B;
     struct LLNode *next_inA, *next_inB;
   
     while (current_inA != NULL && current_inB != NULL)
     {
         next_inA = current_inA->next;
         next_inB = current_inB->next;
         current_inB->next = next_inA;  
         current_inA->next = current_inB;  
         current_inA = next_inA;
         current_inB = next_inB;
    }
    *B = current_inB;
}

/*
<aside>
💡 **Question 8**

Given a singly linked list, find if the linked list is [circular](https://www.geeksforgeeks.org/circular-linked-list/amp/) or not.

> A linked list is called circular if it is not NULL-terminated and all nodes are connected in the form of a cycle. Below is an example of a circular linked list.
> 
</aside>
*/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
};

bool isCircular(struct Node *head)
{
    if (head == NULL)
       return true;
    struct Node *node = head->next;
    while (node != NULL && node != head)
       node = node->next;
    return (node == head);
}
