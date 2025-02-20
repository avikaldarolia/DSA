class LFUCache {
    public:
        int n;
        map<int, list<int>> mp;
        unordered_map<int, pair<int, pair<int, list<int>::iterator>> > hash;
        LFUCache(int capacity) {
            n = capacity;
        }
    
        void updateFrequency(int key){
            auto it = hash[key].second.second;
            int groupId = hash[key].second.first;
            int nextGroup = groupId + 1;
            mp[groupId].erase(it);
            mp[nextGroup].push_front(key);
            hash[key].second = {nextGroup, mp[nextGroup].begin()};
    
            if(mp[groupId].empty()){
                mp.erase(groupId);
            }
        }
        
        int get(int key) {
            if(!hash.contains(key)){
                return -1;
            }
            // Get the key and update the counter. make the key Recently Used as well.
            updateFrequency(key);
    
            return hash[key].first;
        }
        
        void put(int key, int value) {
            if(hash.contains(key)){
                hash[key].first = value;
                updateFrequency(key);
                return;
            }
            else{
                if(n == 0){
    
                }
            }
            
            if(n != 0){
                mp[1].push_front(key);
                hash[key] = {value, {1, mp[1].begin()}};
                n--;
            }
            else{
                auto it = mp.begin();
                int keyToBeRemoved = mp[it->first].back();
                mp[it->first].pop_back();
                hash.erase(keyToBeRemoved);
                if(it->second.empty()){
                    mp.erase(it->first);
                }
    
                mp[1].push_front(key);
                hash[key] = {value, {1, mp[1].begin()}};
            }
        }
    };
    
    /**
     * Your LFUCache object will be instantiated and called as such:
     * LFUCache* obj = new LFUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */