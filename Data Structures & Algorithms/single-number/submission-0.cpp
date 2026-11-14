class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;
        for(int i =0; i<nums.size(); i++){
            result ^=nums[i];
        }

        if(result!=0){
            return result;
        }
        
    }
};
