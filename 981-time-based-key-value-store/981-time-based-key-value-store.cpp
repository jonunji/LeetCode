class TimeMap {
public:
    
    unordered_map<string, map<int, string>> m;
    
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;    
    }
    
    string get(string key, int timestamp) 
    {
        auto keyIt = m.find(key);
        if (keyIt == m.end()) return "";
        
        auto timeIt = m[key].upper_bound(timestamp);
        return timeIt == m[key].begin() ? "" : prev(timeIt)->second;        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */