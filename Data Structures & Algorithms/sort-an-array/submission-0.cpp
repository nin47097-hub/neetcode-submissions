class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
   
        for (int pass = 0; pass < n - 1; pass++) {
            bubble(nums, 0, n - 1 - pass);
        }
        return nums;
    }

private:
    void bubble(vector<int>& nums, int i, int end) {
        
        if (i >= end) return;

        
        if (nums[i] > nums[i + 1]) {
            swap(nums[i], nums[i + 1]);
        }

        
        bubble(nums, i + 1, end);
    }
};
