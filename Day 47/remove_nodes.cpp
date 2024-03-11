//!  Remove Nodes From Linked List (LeetCode 2487)

//? link: https://leetcode.com/problems/remove-nodes-from-linked-list/description/

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
// it reverses the linked list in place & returns the new head of the reversed list.
ListNode *reverse(ListNode *head) {
  ListNode *curr = head;
  ListNode *prev = NULL;
  while (curr) {
    ListNode *nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
  }
  return prev;
}
ListNode *removeNodes(ListNode *head) {
  head = reverse(head); // Reverse the linked list.
  ListNode *prev = NULL;
  ListNode *curr = head;
  int maxi = head->val;

  while (curr != NULL) {
    maxi = max(maxi, curr->val);
    if (maxi > curr->val) { // If the maximum value encountered so far > value of the current node, 
    // remove the current node by updating the next pointer of the previous node.
      prev->next = curr->next;
    } 
    else { //  If the maximum value is not greater, update the prev pointer to the current node.
      prev = curr;
    }
    curr = curr->next;
  }
  head = reverse(head);
  return head;
}

int main() {
  ListNode *head = new ListNode(5);
  head->next = new ListNode(2);
  head->next->next = new ListNode(13);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(8);
  head = removeNodes(head);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}