class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> output;
        dfs(0,nums, temp, output);
        return output;   
    }
private: 
    void dfs(int index,   vector<int>& nums, vector<int>& temp, vector<vector<int>>& output){
        if(index== nums.size()){
            output.push_back(temp);
            return ;
        }
        temp.push_back(nums[index]);
        dfs(index+1, nums, temp, output);
        temp.pop_back();
        while(index+1 < nums.size() && nums[index]== nums[index+1]){
            index++;
        }
        dfs(index+1, nums, temp, output);
    }
};
