class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> repe;
        while(n!=1){
            if(repe.count(n)){
                return false;
            }
            repe.insert(n);
            int sum =0;
            while(n>0){
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;    
            }
            n = sum;
        }
        return true;
    }
};
