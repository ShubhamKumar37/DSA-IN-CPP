class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minheap.push(num);

        if(minheap.size() > maxheap.size())
        {
            int mintop = minheap.top();
            minheap.pop();
            maxheap.push(mintop);
        }
        else
        {
            if(minheap.top() < maxheap.top())
            {
                int mintop = minheap.top();
                int maxtop = maxheap.top();
                minheap.pop();
                maxheap.pop();

                maxheap.push(mintop);
                minheap.push(maxtop);
            }
        }
    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size()) return ((minheap.top() + maxheap.top()) / 2.0);
        return maxheap.top();
    }
};

/**
 * @brief 
 * 295. Find Median from Data Stream
 * 
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */