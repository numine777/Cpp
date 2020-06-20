#include <bits/stdc++.h>

using namespace std;

class LRUCache {
    int size_;
    unordered_map<int, int> ma;
    deque<int> lst;
public:
    LRUCache(int capacity) : size_(capacity) {
        ma.clear();
        lst.clear();
    }
    
    int get(int key) {
        //not found
        if (ma.find(key) == ma.end()){
            return -1;
        }
        //found
        else {
            deque<int>::iterator it = lst.begin();
            while (*it != key) {
                it++;
            }
            lst.erase(it);
            lst.push_front(key);
            return ma[key];
        }
    }
    
    void put(int key, int value) {
        //found
        if (ma.find(key)!= ma.end()) {
            deque<int>::iterator it = lst.begin();
            while (*it != key) {
                it++;
            }
            lst.erase(it);
            lst.push_front(key);
            ma[key] = value;
        }
        //not found
        else {
            //cache full
            if (size_ == lst.size()) {
                int back = lst.back();
                lst.pop_back();
                ma.erase(back);
            }
            lst.push_front(key);
            ma[key] = value;
        }
    }
};
