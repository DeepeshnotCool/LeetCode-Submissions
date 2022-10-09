class MyCircularQueue {
public:
    vector<int> cQueue;
    int size;
    
    MyCircularQueue(int k) {
        size = k;
    }
    
    bool enQueue(int value) {
        if(cQueue.size() < size)
            cQueue.push_back(value);
        else
            return false;
        return true;
    }
    
    bool deQueue() {
        if(cQueue.size() != 0)
            cQueue.erase(cQueue.begin());
        else
            return false;
        return true;
    }
    
    int Front() {
        if(cQueue.size() != 0)
            return cQueue[0];
        else
            return -1;
    }
    
    int Rear() {
        if(cQueue.size() != 0)
            return cQueue[cQueue.size() - 1];
        else
            return -1;
    }
    
    bool isEmpty() {
        return cQueue.size() == 0;
    }
    
    bool isFull() {
        return cQueue.size() == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */