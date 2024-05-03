//! GeeksForGeeks QuestionSerialize and deserialize a binary tree [POTD 2-5-2024]

//? link: https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
}; 
class Solution {
public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)  {
        vector<int> res; // vector to store all node values of the tree
        if(root == NULL) // if root is NULL return empty vector
            return res;
        // level order traversal of the tree
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front != NULL) {
                res.push_back(front->data); // Store the value of the current node in the vector res
                q.push(front->left); // push left child to the queue
                q.push(front->right); // push right child to the queue
            }
            else{
                res.push_back(-1); // Mark NULL nodes with a special value, like -1
            }
        }
        return res;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A) {
        if(A.empty() || A[0] == -1) // if vector is empty means there are no nodes in tree or if there is no root node return null
            return NULL;
        
        Node* root = new Node(A[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;
        while(!q.empty() && i < A.size()) {
            Node* front = q.front();
            q.pop();
            
            // Left child
            if(i < A.size() && A[i] != -1) {
                front->left = new Node(A[i]);
                q.push(front->left);
            }
            i++;
            
            // Right child
            if(i < A.size() && A[i] != -1) {
                front->right = new Node(A[i]);
                q.push(front->right);
            }
            i++;
        }
        return root;
    }
};
void printInorder(Node* root) {
    if(root == nullptr)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main() {
    // Creating a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    // Serialize the binary tree
    vector<int> serialized = sol.serialize(root);

    // Print the serialized binary tree
    cout << "Serialized tree: ";
    for(int val : serialized) {
        cout << val << " ";
    }
    cout << endl;

    // Deserialize the serialized binary tree
    Node* deserialized_root = sol.deSerialize(serialized);

    // Print the inorder traversal of the deserialized binary tree
    cout << "Inorder traversal of deserialized tree: ";
    printInorder(deserialized_root);
    cout << endl;

    return 0;
}