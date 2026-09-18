#include<algorithm>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if(n ==0){
            return 0;
        }
      
        int current =1;
        int maximum = 1;
        sort(nums.begin(),nums.end());
        for(int i =1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            if ((nums[i]-nums[i-1])==1){
                current+=1;
            }

            else{
                maximum = max(maximum,current);
                current=1;
            }

        }
        return {
            max(maximum,current)
        };
        
    }
};
