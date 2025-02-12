// Link: https://leetcode.com/problems/insert-delete-getrandom-o1/description/

class RandomizedSet {
public:
    unordered_map<int, int> indexHash;
    vector<int> vec;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(indexHash.find(val) != indexHash.end()){
            return false;
        }

        vec.push_back(val);
        indexHash[val] = vec.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(indexHash.find(val) == indexHash.end()){
            return false;
        }

        int curIndex = indexHash[val];
        vec[curIndex] = vec.back();
        indexHash[vec.back()] = curIndex;

        indexHash.erase(val);
        vec.pop_back();

        return true;
    }
    
    int getRandom() {
        int size = vec.size();
        int randIdx = rand() % size;
        return vec[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


