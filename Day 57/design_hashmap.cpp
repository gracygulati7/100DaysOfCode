//! leetcode question 706. Design HashMap

//? link: https://leetcode.com/problems/design-hashmap/

#include<bits/stdc++.h>
using namespace std;
class MyHashMap {
private:
    vector<pair<int,int>> data;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i=0;i<data.size();i++){
            if(data[i].first==key){
                data[i].second=value;
                return;
            }
        }
        data.push_back({key,value});
    }
    
    int get(int key) {
        for(int i=0;i<data.size();i++){
            if(data[i].first==key){
                return data[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i=0;i<data.size();i++){
            if(data[i].first==key){
                data.erase(data.begin()+i);
                return;
            }
        }
    }
};

int main() {
    MyHashMap myHashMap;
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);

    // Get values from the map
    cout << "Value for key 1: " << myHashMap.get(1) << endl; // should return 1
    cout << "Value for key 3: " << myHashMap.get(3) << endl; // should return -1

    // Update an existing value
    myHashMap.put(2, 1);

    // Get the updated value
    cout << "Value for key 2: " << myHashMap.get(2) << endl; // should return 1

    // Remove a key-value pair
    myHashMap.remove(2);

    // Check if the key-value pair is removed
    cout << "Value for key 2: " << myHashMap.get(2) << endl; // should return -1
    return 0;
}