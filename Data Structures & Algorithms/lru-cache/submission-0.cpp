class LRUCache {
public:
    int  cap=0;
    unordered_map<int,pair<int,list<int>::iterator>>mp; 
    list<int>l;
    LRUCache(int capacity):cap(capacity) {}
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        // move key to back (most recently used)
        l.erase(mp[key].second);
        l.push_back(key);

        mp[key].second = --l.end();

        return mp[key].first;
    }
    
    void put(int key, int value) {
         if(mp.find(key)!=mp.end()){
            l.erase(mp[key].second);
            l.push_back(key);
            mp[key] = {value, --l.end()};
         }else{
               if(mp.size()==cap){
                int k=l.front(); 
                l.pop_front();
                mp.erase(k);  
               }
               l.push_back(key);
               mp[key]={value,--l.end()};
         }
    }
};
