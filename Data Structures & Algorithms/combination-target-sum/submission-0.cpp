class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> combo;
        vector<int> basket;
        
       
        dfs(nums, 0, basket, 0, target, combo);
        return combo;
    }

private:
    void dfs(vector<int>& nums, int index, vector<int>& basket, int sum1, int target, vector<vector<int>>& combo) {
        
        if (sum1 == target) {
            combo.push_back(basket);
            return;
        }
        
       
        if (sum1 > target || index == nums.size()) {
            return;
        }

        basket.push_back(nums[index]);
     
        dfs(nums, index, basket, sum1 + nums[index], target, combo);
        
   
        basket.pop_back();

       
        dfs(nums, index + 1, basket, sum1, target, combo);
    }
};
