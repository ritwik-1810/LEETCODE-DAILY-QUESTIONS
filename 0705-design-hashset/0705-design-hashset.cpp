class MyHashSet {
public:
    vector<list<int>>buckets;
    MyHashSet() {
        
        buckets = vector<list<int>>(10000);

    }
    
    void add(int key) {

         int hashKey=key%10000;

        for(auto &it:buckets[hashKey])
         {
             if(it==key)
             {
                 return;
             }
         }

         buckets[hashKey].push_back(key);

    }
    
    void remove(int key) {

        int hashKey=key%10000;

        for(auto it=buckets[hashKey].begin();it!=buckets[hashKey].end();++it)
        {
            if(*it==key)
            {
                buckets[hashKey].erase(it);
                break;
            }
        }

        
    }
    
    bool contains(int key) {

         int hashKey=key%10000;

         for(auto &it:buckets[hashKey])
         {
             if(it==key)
             {
                 return true;
             }
         }

         return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */