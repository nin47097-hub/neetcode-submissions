class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> temp;
        
      
        vector<bool> used(nums.size(), false); 
        
        
        dfs(nums, temp, used, output);
        
        return output;
    }

private:
    void dfs(vector<int>& nums, vector<int>& temp, vector<bool>& used, vector<vector<int>>& output) {
        
        if (temp.size() == nums.size()) {
            output.push_back(temp);
            return;
        }

      
        for (int i = 0; i < nums.size(); i++) {
            
          
            if (!used[i]) {
                
             
                temp.push_back(nums[i]); 
                used[i] = true;          
                
                
                dfs(nums, temp, used, output); 
                
             
                used[i] = false;         
                temp.pop_back();         
            }
        }
    }
};
