struct DoubleListNode{
    int key;
    int val;
    DoubleListNode* next;
    DoubleListNode* prev;
    DoubleListNode(int x, int y) : key(x), val(y) , next(nullptr) , prev(nullptr) {}
};

class LRUCache {
public:
    int cap;
    unordered_map<int,DoubleListNode*> cache;
    DoubleListNode*left;
    DoubleListNode* right;

    LRUCache(int capacity) {
        cap = capacity;
        left = new DoubleListNode(0,0);
        right = new DoubleListNode(0,0);
        left->next = right;
        right->prev = left;
    }
    
    void remove(DoubleListNode* node){
        DoubleListNode* prev = node->prev;
        DoubleListNode* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(DoubleListNode* node){
        DoubleListNode* prev = right->prev;
        DoubleListNode* nxt = right;
        prev->next = node;
        nxt->prev = node;
        node->next = nxt;
        node->prev = prev;
    }

    int get(int key) {
        if(cache.count(key)){
            DoubleListNode* res = cache[key];
            remove(res);
            insert(res);
            return res->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            remove(cache[key]);
        }
        cache[key] = new DoubleListNode(key,value);
        insert(cache[key]);
        if(cache.size()>cap){
            DoubleListNode* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};