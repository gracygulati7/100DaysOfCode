//! leetcode question 2. Add Two Numbers

//? link: https://leetcode.com/problems/add-two-numbers/description/

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(0);
        ListNode* tail=dummy; int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int digit1=(l1!=NULL)? l1->val:0;
            int digit2=(l2!=NULL)? l2->val:0;
            int sum=digit1+digit2+carry;
            int digit=sum%10;
            carry=sum/10;
            ListNode* newnode= new ListNode(digit);
            tail->next=newnode;
            tail=tail->next;
            l1=(l1!=NULL)?l1->next:NULL;
            l2=(l2!=NULL)?l2->next:NULL;
        }
        ListNode* res=dummy->next;
        delete(dummy);
        return res;
    }
};
int main(){
    Solution s;
    ListNode* l1=new ListNode(2);
    l1->next=new ListNode(4);
    l1->next->next=new ListNode(3);
    ListNode* l2=new ListNode(5);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(4);
    ListNode* res=s.addTwoNumbers(l1,l2);
    while(res!=NULL){
        cout<<res->val<<" ";
        res=res->next;
    }
    cout<<endl;
    return 0;
}


//* LOGIC:
/*
1. Create a placeholder node called dummy with a value of 0. This node will hold the resulting linked list.
2. Initialize a pointer called tail and set it to dummy. This pointer will keep track of the last node in the result list.
3. Initialize a variable called carry to 0. This variable will store the carry value during addition.
4. Start a loop that continues until there are no more digits in both input lists (l1 and l2) and there is no remaining carry value.
5. Inside the loop:
a) Check if there is a digit in the current node of l1. If it exists, assign its value to a variable called digit1. Otherwise, set digit1 to 0.
b) Check if there is a digit in the current node of l2. If it exists, assign its value to a variable called digit2. Otherwise, set digit2 to 0.
c) Add the current digits from l1 and l2, along with the carry value from the previous iteration, and store the sum in a variable called sum.
d) Calculate the unit digit of sum by taking the modulus (%) of sum by 10. This digit will be placed in a new node for the result.
e) Update the carry variable by dividing sum by 10 and taking the integer division (/) part. This gives us the carry for the next iteration.
f) Create a new node with the calculated digit as its value.
g) Attach the new node to the tail node of the result list.
h) Move the tail pointer to the newly added node.
i) Move to the next nodes in both l1 and l2, if they exist. If either list is exhausted, set the corresponding pointer to nullptr.
6. After the loop, obtain the actual result list by skipping the dummy node.
7. Delete the dummy node.
8. Return the resulting list.
*/