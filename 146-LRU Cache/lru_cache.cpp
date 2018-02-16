class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> dict;
    list<int> cache;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(dict.find(key) == dict.end()) return -1;
        //found this key
        int toReturn = dict[key].first;
        cache.erase(dict[key].second);// remove old record
        cache.push_front(key);// add new record in cache
        dict[key] = make_pair(toReturn, cache.begin());// update dict
        return toReturn;
    }
    
    void put(int key, int value) {
        if(dict.find(key) == dict.end()) {
            // new record
            cache.push_front(key);
            dict[key] = make_pair(value, cache.begin());
            if(cache.size() > capacity) {
                //remove least recently used elements
                int toRemove = cache.back();
                dict.erase(toRemove);
                cache.pop_back();
            }
        } else {
            // update record
            get(key);
            dict[key] = make_pair(value, cache.begin());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
