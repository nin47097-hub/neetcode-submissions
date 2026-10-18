class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output; 
        vector<int> temp;

    
        sort(candidates.begin(), candidates.end());

   
        dfs(0, 0, target, candidates, temp, output);
        return output;
    }

private:
    void dfs(int index, int sum, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& output){
        if (sum == target){
            output.push_back(temp);
            return;
        }
        
        if (sum > target || index == candidates.size()){
            return;
        }

        temp.push_back(candidates[index]);
       
        dfs(index + 1, sum + candidates[index], target, candidates, temp, output);
  
        temp.pop_back(); 

   
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]){
            index++;
        }
        
        dfs(index + 1, sum, target, candidates, temp, output);
    }
};

