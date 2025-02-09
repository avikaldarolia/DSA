// Link: https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    int n;
    unordered_map<int, pair<list<int>::iterator, int> > mp;
    list<int> vec;
    LRUCache(int capacity) {
        n = capacity;
    }

    void update(int key){
        vec.erase(mp[key].first);
        vec.push_front(key);
        mp[key].first = vec.begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        update(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            vec.push_front(key);
            mp[key] = {vec.begin(), value};
            n--;
        }
        else{
            mp[key].second = value;
        }

        update(key);

        if(n < 0){
            int removeKey = vec.back();
            vec.pop_back();
            mp.erase(removeKey);
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,vecue);
 */
