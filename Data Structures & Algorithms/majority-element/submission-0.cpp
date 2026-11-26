class Solution {
public:
    int majorityElement(vector<int>& nums) {

        unordered_map<int, int>counts;


        for(int i =0;i< nums.size(); i++){
            if(counts.count(nums[i])){
                counts[nums[i]]++;



            }else{
                counts[nums[i]] = 1;

            }
            

        }
        int maxCount =0;
        int maxElement = nums[0];

        for (auto& pair : counts) {

            if (pair.second > maxCount) {
                maxCount = pair.second;
                maxElement = pair.first;
            }
        }

        return maxElement;
        
    }
};