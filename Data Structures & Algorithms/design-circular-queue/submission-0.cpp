struct dblListNode {
    int val;            
    dblListNode* next;     
    dblListNode* prev;    
    dblListNode() : val(0), next(nullptr), prev(nullptr) {}
    dblListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    dblListNode(int x, dblListNode* next , dblListNode* prev) : val(x), next(next) , prev(prev) {}
};

class MyCircularQueue {
public:
    int space;
    dblListNode* left;
    dblListNode* right;
    MyCircularQueue(int k) {
        space = k;
        left = new dblListNode(0,nullptr,nullptr);
        right = new dblListNode(0,nullptr,left);
        left->next = right;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        dblListNode* curr = new dblListNode(value,right,right->prev);
        right->prev->next = curr;
        right->prev = curr;
        space-=1;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        left->next = left->next->next;
        left->next->prev = left;
        space+=1;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return left->next->val;
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return right->prev->val;
    }
    
    bool isEmpty() {
        return left->next == right;
    }
    
    bool isFull() {
        return space == 0;
    }
};