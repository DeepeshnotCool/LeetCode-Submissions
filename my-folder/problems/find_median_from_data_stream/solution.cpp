class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    bool flag = true;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        flag = !flag;
        if(!flag){
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else{
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (!flag) return minHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
