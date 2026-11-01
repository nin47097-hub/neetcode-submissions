#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> memo;
        return dfs(0, target, nums, memo);
    }
private:  
    int dfs(int index, int amount, vector<int>& nums, map<pair<int, int>, int>& memo) {

        if (index == nums.size()) {
            return amount == 0 ? 1 : 0;
        }

        if (memo.find({index, amount}) != memo.end()) {
            return memo[{index, amount}];
        }

        
        int add = dfs(index + 1, amount + nums[index], nums, memo);
        
     
        int subtract = dfs(index + 1, amount - nums[index], nums, memo);

       
        return memo[{index, amount}] = add + subtract;
    }
};

