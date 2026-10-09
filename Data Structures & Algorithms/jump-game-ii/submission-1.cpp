class Solution {
public:
    int jump(vector<int>& nums) {
        int max_d = 0;
        int jumps =0;
        int end =0;
        if (nums.size() <= 1) return 0;

        for(int i =0; i< nums.size(); i++){
            max_d = max(max_d, nums[i]+ i);

            if(max_d>=nums.size()-1){
                jumps++;
                return jumps;
                return true;
            }
            if(i == end){
                jumps++;
                end =max_d;
            }
        }
        return jumps;
        
    }
};
