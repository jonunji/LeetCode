class LRUCache {
public:
    
    int size;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
        
    LRUCache(int capacity) : size(capacity) {}
    
    int get(int key) 
    {
        if (cache.count(key) == 0) 
            return -1;
        
        updateLRU(key);
        
        return cache[key]->second;
    }
    
    void put(int key, int value) 
    {
        if (cache.size() == size && cache.count(key) == 0)
            evcit();
        
        updateLRU(key);
        lru.front().second = value;
    }
    
    void updateLRU(int key)
    {
        int val = 0;
        
        if (cache.count(key))
        {
            val = cache[key]->second;
            lru.erase(cache[key]);
        }
        
        lru.push_front({key, val});
        cache[key] = lru.begin();
    }
    
    void evcit()
    {
        cache.erase(lru.back().first);
        lru.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */