//! leetcode question 2816. Double a Number Represented as a Linked List

//? link: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

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
    ListNode* doubleIt(ListNode* head) {
        string res = "";
        ListNode* curr = head;

        // Convert the linked list digits into a string
        while (curr != NULL) {
            res += to_string(curr->val);
            curr = curr->next;
        }

        // Double the number represented by the string
        string s = doubleString(res);

        // Update the linked list with the digits of the doubled number
        ListNode* newhead = NULL;
        ListNode* tail = NULL;

        // We iterate through the characters of the string s using a for loop. At each iteration, 
        // we extract a character representing a digit of the doubled number.
        for (int i = 0; i < s.size(); ++i) {
            char digit = s[i];

            // We create a new ListNode with the digit value (digit - '0') and add it to the linked list.
            ListNode* new_node = new ListNode(digit - '0');
            
            if (newhead == NULL) { // If newHead is nullptr, we set both newHead and tail to this new node.
                newhead = new_node;
                tail = new_node;
            } 
            else { // Otherwise, we append the new node to the end of the linked list and update tail to point to the new node
                tail->next = new_node;
                tail = new_node;
            }
        }
        return newhead;
    }    
    
private:
    // Inside doubleString, we iterate through the characters of the input string num from right to left using a for loop. 
    // At each iteration, we convert the character representing a digit to an integer, double it, and update the result accordingly, 
    // taking care of any carryovers.
    
    string doubleString(string num) {
        string result;
        int carry = 0;
        for (int i = num.size() - 1; i >= 0; --i) {
            int digit = (num[i] - '0') * 2 + carry;
            carry = digit / 10;
            result = to_string(digit % 10) + result;
        }
        if (carry > 0) {
            result = to_string(carry) + result;
        }
        return result;
    }
};
