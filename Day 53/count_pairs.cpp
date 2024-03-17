//! GEEKSFORGEEKS question Count Pairs whose sum is equal to X (PROBLEM OF THE DAY 17-3-2024)

//? link: https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1

#include<iostream>
#include<set>
using namespace std;
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution{
  public:
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        set<int> s;
        while(head1!=NULL){
            s.insert(head1->data);
            head1=head1->next;
        }
        int count=0;
        while(head2!=NULL){
            int value=x-head2->data;
            if(s.find(value)!=s.end()){
                count++;
            }
            head2=head2->next;
        }
        return count;
    }
};
int main(){
    struct Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    struct Node* head2 = new Node(6);
    head2->next->next->next->next->next->next = new Node(7);
    head2->next->next->next->next->next->next->next = new Node(8);
    head2->next->next->next->next->next->next->next->next = new Node(9);
    head2->next->next->next->next->next->next->next->next->next = new Node(10);
    Solution obj;
    cout<<obj.countPairs(head1,head2,10)<<endl;
    return 0;
}