class LRUCache {
public:
    unordered_map<int,int>mp;
    unordered_map<int,int>pp;
    int size,prev;
    LRUCache(int capacity) {

      size=capacity;
      prev=0;
        
    }
    
    int get(int key) {

        if(mp.find(key)!=mp.end())
        {
          prev++;

          pp[key]=prev;

          return mp[key];
        }

        return -1;
    }
    
    void put(int key, int value) {

       
        mp[key]=value;

        prev++;

        pp[key]=prev;

         if(mp.size()>size)
        {
            int val=INT_MAX;

            int kk;

            for(auto v:pp)
            {
                if(val>v.second)
                {
                    val=v.second;

                    kk=v.first;
                }
            }

            mp.erase(kk);

            pp.erase(kk);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */