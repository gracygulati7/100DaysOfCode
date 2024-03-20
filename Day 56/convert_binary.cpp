//! leetcode question 1290. Convert Binary Number in a Linked List to Integer

//? link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/

#include <bits/stdc++.h>
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
    int getDecimalValue(ListNode* head) {
        string s;
        while(head!=NULL){
            s+=to_string(head->val);
            head=head->next;
        }
        int res=0, power=1;
        for(int i=s.length()-1;i>=0;i--){
            res+=power*(stoi(s.substr(i,1))); //  this line calculates the decimal value of the binary representation. 
            // It converts the current character of the string s to an integer using stoi() (string to integer) function 
            // and multiplies it by power. This result is then added to the res.
            power*=2; // After processing each digit of the binary representation, power is multiplied by 2 to prepare for the next digit.
        }
        return res;
    }
};
int main(){
    Solution s;
    ListNode* head=new ListNode(1);
    head->next=new ListNode(0);
    head->next->next=new ListNode(1);
    cout<<s.getDecimalValue(head)<<endl;
    return 0;
}

//* LOGIC:
/*
To form the Decimal Number, we just need to multiply the binary digits at each node of Linked List with an appropriate power of 2 ... 
And this Power of 2 basically increases as we move in the backward direction !! like from last node to first node
It's very basic to observe that we don't know by what power of 2 we will be multipying the first Node of the List if we try to iterate 
in the forward direction , so we would just convert the the Linked list into a string and then traverse over it in the backward direction... 
Multiplying each index by increasing pow(2) and keep adding the result to form the desired Decimal answer...
*/