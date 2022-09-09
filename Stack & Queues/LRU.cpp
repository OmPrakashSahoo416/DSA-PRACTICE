class node{
        public:
            int key;
            int val;
            node* prev;
            node* next;

            node(int k, int v){
                key = k;
                val = v;
            }
    };
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    unordered_map<int,node*>mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    void addnode(node* root){
        node* temp = head -> next;
        root -> next = temp;
        root -> prev = head;
        head -> next = root;
        tail -> prev = root;
    }
    void deletenode(node* root){
        node* pre = root -> prev;
        node* nxt = root -> next;
        pre -> next = nxt;
        nxt -> prev = pre;
    }
    
    
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node* res = mp[key];
            int ans = res -> val;
            mp.erase(key);
            deletenode(res);//delete from its current pos.
            addnode(res); //reassign
            mp[key] = head -> next; // Since it is inserted at head next(most recent thats why.)
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            node* res = mp[key];
            mp.erase(key); //deleting the key from map.
            deletenode(res);//Deleting the existing node
        }
        if(mp.size() == cap){
            mp.erase(tail -> prev -> key);
            deletenode(tail -> prev);
        }
        addnode(new node(key, value));
        mp[key] = head -> next;
    }