class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int right = nums.size()-1;
        while(l<=right){
            int m = (l+right)/2;

            if(nums[m]>target){
                right = m-1;
            }
            else if(nums[m]<target){
                l = m+1;
            }
            else{
                return m;
            }

        }

        return -1;
        
    }
};
