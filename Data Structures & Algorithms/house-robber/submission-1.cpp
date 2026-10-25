class Solution {
    int helper(vector<int>& memo, vector<int>& nums, int i){
        if (i >= nums.size()) {
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        // choices
        int skip = helper(memo, nums, i + 1);
        int rob = nums[i] + helper(memo, nums, i + 2);
        
        return memo[i] = max(rob, skip); 
    }
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return helper(memo, nums, 0);
    }
};

