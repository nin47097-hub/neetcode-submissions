class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int right = *max_element(piles.begin(),piles.end());
        while(l <=right){
            int k =  ((l+ right)/2);

            long long time =0;
            for(int p: piles){
                time += ceil(static_cast<double>(p) / k);
            }
            if(time <= h){
                right = k-1;
            }

            else{
                l= k+1;
            }
        }
        return l;




        
    }
};
