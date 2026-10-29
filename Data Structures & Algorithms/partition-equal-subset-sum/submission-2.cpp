class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum1 = 0;
        int n = nums.size();

        for(int i : nums){
            sum1 += i;
        }

        if(sum1 % 2 != 0){
            return false;
        }

        int target = sum1 / 2;
       
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));

        return dfs(nums, 0, target, memo);
    }

    
    bool dfs(vector<int>& nums, int i, int target, vector<vector<int>>& memo){
        if(i == nums.size()){
            return target == 0;
        }

        if(target < 0){
            return false;
        }
        
        if(memo[i][target] != -1) {
            return memo[i][target];
        }

        memo[i][target] = dfs(nums, i + 1, target, memo) || dfs(nums, i + 1, target - nums[i], memo);
        
        return memo[i][target];
    }
};

