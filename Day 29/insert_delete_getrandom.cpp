<<<<<<< HEAD
//! leetcode question 380. Insert Delete GetRandom O(1)

//? link: https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-02-22

#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

class RandomizedSet {
public:
    unordered_set<int> set;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(set.find(val)==set.end()){
            v.push_back(val);
            set.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(set.find(val)!=set.end()){
            v.erase(find(v.begin(),v.end(),val));
            set.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    RandomizedSet obj;
    obj.insert(1);
    obj.remove(1);
    obj.insert(2);
    obj.remove(2);
    obj.insert(2);
    obj.getRandom();
    return 0;
=======
//! leetcode question 380. Insert Delete GetRandom O(1)

//? link: https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-02-22

#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

class RandomizedSet {
public:
    unordered_set<int> set;
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(set.find(val)==set.end()){
            v.push_back(val);
            set.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(set.find(val)!=set.end()){
            v.erase(find(v.begin(),v.end(),val));
            set.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    RandomizedSet obj;
    obj.insert(1);
    obj.remove(1);
    obj.insert(2);
    obj.remove(2);
    obj.insert(2);
    obj.getRandom();
    return 0;
>>>>>>> 6b6e97ed4446623c37b08a068b75fa893951403d
}