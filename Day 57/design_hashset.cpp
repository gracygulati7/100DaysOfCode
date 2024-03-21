//! leetcode question 705. Design HashSet 

//? link: https://leetcode.com/problems/design-hashset/description/

#include<bits/stdc++.h>
using namespace std;
class MyHashSet {
private:
    unordered_set<int> s;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        s.erase(key);
    }
    
    bool contains(int key) {
        return s.find(key)!=s.end();
    }
};

int main() {
    MyHashSet myHashSet;
    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    cout << myHashSet.contains(1) << endl; // return True
    cout << myHashSet.contains(3) << endl; // return False, (not found)
    myHashSet.add(2);      // set = [1, 2]
    cout << myHashSet.contains(2) << endl; // return True
    myHashSet.remove(2);   // set = [1]
    cout << myHashSet.contains(2) << endl; // return False, (already removed)
    return 0;
}