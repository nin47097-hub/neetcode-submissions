class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size();
        int k = nums2.size();
        int total_length = (l+k);
        int mid= (total_length/2)+1;
        int p1=0;
        int p2=0;
        int prev_val;
        int curr_val;

        for(int i =0; i< mid;i++){
            prev_val =curr_val;

            if(p1 < l && (p2 >= k || nums1[p1] <= nums2[p2])){
                curr_val = nums1[p1];
                p1++;
            }
            else{
                curr_val = nums2[p2];
                p2++;
            }

        }
        if(total_length%2!=0){
            return curr_val;
        }
        else{
            return(curr_val+prev_val)/2.0;
        }
    }


};
