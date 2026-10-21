class Node
{   
    public:

    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key,int val)
    {
        this->key=key;
        this->val=val;
        prev=nullptr;
        next=nullptr;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }

    void remove(Node* nw)
    {
         nw->prev->next=nw->next;

         nw->next->prev=nw->prev;

         nw->next=nullptr;

         nw->prev=nullptr;
    }

    void addNode(Node* nw)
    {
         nw->next=head->next;

         head->next->prev=nw;

         head->next = nw;

         nw->prev=head;

    }
    int get(int key) {

        if(!mp.count(key)) return -1;

        Node* nw=mp[key];

        remove(nw);

        addNode(nw);

        return nw->val;
        
    }
    
    void put(int key, int value) {

        if(mp.count(key))
        {
           Node *nw=mp[key];

           nw->val=value;

           remove(nw);

           addNode(nw);
        }
        else
        {
             if((int)mp.size()>=cap)
             {
                mp.erase(tail->prev->key);

                remove(tail->prev);

                Node* nw=new Node(key,value);

                addNode(nw);

                mp[key]=nw;
             }
             else
             {
                Node* nw=new Node(key,value);

                addNode(nw);

                mp[key]=nw;

             }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */