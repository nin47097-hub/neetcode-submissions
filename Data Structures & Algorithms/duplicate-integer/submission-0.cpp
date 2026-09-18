#include <vector>
#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> t;
        
        for(int i = 0; i < nums.size(); i++){
            if(t.count(nums[i])){
                return true;
            }
            t.insert(nums[i]);
        }
        
        return false;
    }
};
