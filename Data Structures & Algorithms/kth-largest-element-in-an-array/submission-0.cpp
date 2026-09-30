class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;

        for (int num : nums){
            minheap.push(num);
            if(minheap.size()>k){
                minheap.pop();
            }

        }
        return minheap.top();
        
    }
};
