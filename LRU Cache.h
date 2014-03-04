class LRUCache{
public:
    struct Node{
        int key;
        int val;
        Node *prev;
        Node *next;
        Node():key(-1),val(-1),prev(NULL),next(NULL){}
        Node(int k, int v):key(k), val(v), prev(NULL), next(NULL){}
    };
    
    map<int, Node*> mmap; // key to node
    int capacity;
    Node *head;
    Node *tail;
    int size;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int get(int key) {
        if(mmap.find(key) == mmap.end())
            return -1;
        Node *node = mmap[key];
        //del node from list
        node->prev->next = node->next;
        node->next->prev = node->prev;
        //add node next to head
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
        node->prev = head;
        return node->val;
    }
    
    void set(int key, int value) {
        Node *node = NULL;
        if(mmap.find(key) != mmap.end()){
            //already exists
            node = mmap[key];
            node->val = value;
            //del node from list
            node->prev->next = node->next;
            node->next->prev = node->prev;
        } else {
            //new node
            node = new Node(key, value);
            mmap[key] = node;
            if(this->size < this->capacity){
                this->size++;
            } else {
                //delete tail->prev
                if(this->tail->prev != this->head){
                    Node *tmp = tail->prev;
                    tail->prev = tmp->prev;
                    tmp->prev->next = tail;
                    mmap.erase(tmp->key);// !!!!! del from map, original fault,didn't del
                    delete tmp;
                }
            }
        }
        //add node next to head
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
        node->prev = head;
    }
};