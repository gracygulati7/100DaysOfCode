#include <iostream>
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (curr != nullptr) {
            curr = curr->next;
            count++;
        }
        curr = head;
        ListNode* kthFromBegin = nullptr;
        for (int i = 1; i <= count; i++) {
            if (i == k) {
                kthFromBegin = curr;
                break;
            }
            curr = curr->next;
        }
        curr = head;
        ListNode* kthFromEnd = nullptr;
        for (int i = 1; i <= count - k + 1; i++) {
            if (i == count - k + 1) {
                kthFromEnd = curr;
                break;
            }
            curr = curr->next;
        }
        int temp = kthFromBegin->val;
        kthFromBegin->val = kthFromEnd->val;
        kthFromEnd->val = temp;
        return head;
    }
};