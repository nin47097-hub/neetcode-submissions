class MedianFinder {

private:
        std::priority_queue<int>median_heap_small;                                    
        std::priority_queue<int, std::vector<int>,std::greater<int>> median_heap_big; 
    
public:
    MedianFinder() {
        {}



        
    }
    
    void addNum(int num) {

        if (median_heap_small.empty() || num <= median_heap_small.top()) {
            median_heap_small.push(num); 
        } else {
            median_heap_big.push(num);
        }
        if (median_heap_small.size() > median_heap_big.size() + 1) {
            median_heap_big.push(median_heap_small.top());
            median_heap_small.pop();
        } 
    
        else if (median_heap_big.size() > median_heap_small.size()) {
            median_heap_small.push(median_heap_big.top());
            median_heap_big.pop();
        }
        
    }
    
    double findMedian() {
        if(median_heap_big.size() == median_heap_small.size()){
            return (median_heap_small.top()+median_heap_big.top())/2.0;
        }

        else if(median_heap_big.size() > median_heap_small.size()){
            return median_heap_big.top();
        }

        else{
            return median_heap_small.top();
        }




        
    }
};
