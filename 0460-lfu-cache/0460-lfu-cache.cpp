class Node{

    public:
    
    int key;
    int val;
    int freq;
    Node* prev=nullptr;
    Node* next=nullptr;

    Node(int key,int val,int freq)
    {
       this->key=key;
       this->val=val;
       this->freq=freq;
    }

};
class DLL{
    
    public:

    Node* head;
    Node* tail;

    DLL()
    {
        head=new Node(-1,-1,0);
        tail=new Node(-1,-1,0);
        head->next=tail;

        tail->prev=head;
    }

    void addFront(Node* node)
    {
            Node* nextNode = head->next;

            head->next = node;
            node->prev = head;

            node->next = nextNode;
            nextNode->prev = node;
    }

    void remove(Node* node)
    {
            node->prev->next = node->next;
            node->next->prev = node->prev;
    }

    Node* LRU()
    {
        if(head->next==tail) return nullptr;

        Node* nw=tail->prev;

        remove(tail->prev);

        return nw;

    }

    bool isEmpty()
    {
        if(head->next==tail)
          return true;

        return false;
    }

};
class LFUCache {
public:
    int cap;
    unordered_map<int,Node*>keyMap;
    unordered_map<int,DLL*>freqMap;
    int minimumFreq=1;
    LFUCache(int capacity) {

        cap=capacity;
        
    }
    
    int get(int key) {
   
        if(!keyMap.count(key)) return -1;

        Node* nw = keyMap[key];

        int ans=nw->val;

        updateFreq(nw);

        return ans;
        
    }
    
    void put(int key, int value) {

        if(keyMap.count(key))
        {
            Node* nw=keyMap[key];

            nw->val=value;

            updateFreq(nw);

            return;
        }
        else
        {
            if(keyMap.size()==cap)
            {
                 DLL* rem=freqMap[minimumFreq];

                 Node* rr=rem->LRU();

                 keyMap.erase(rr->key);

                 delete(rr);
            }

            if(freqMap.find(1)==freqMap.end())
            {
                freqMap[1]=new DLL();
            }

            Node* nw=new Node(key,value,1);
             
            freqMap[1]->addFront(nw);

            keyMap[key]=nw;

            minimumFreq=1;

        }
        
    }

    void updateFreq(Node* n)
    {
         int freq=n->freq;

         freqMap[freq]->remove(n);

         if(freqMap[freq]->isEmpty())
         {
              freqMap.erase(freq);

              if(freq==minimumFreq) minimumFreq+=1;
         }

         n->freq++;

         if(!freqMap.count(freq+1))
         {
            freqMap[freq+1]=new DLL();
         }

         freqMap[freq+1]->addFront(n);

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */