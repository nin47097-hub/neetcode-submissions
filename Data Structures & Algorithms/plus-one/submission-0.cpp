class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        recon(digits);
        return digits;


        
    }

private:
    void recon(vector<int>& digits) {
 
        if (digits.empty()) {
            digits.push_back(1);
            return;
        }

        
        if (digits.back() < 9) {
            digits.back() += 1;
            return;
        } 

        else {
            digits.pop_back();
            recon(digits);
            digits.push_back(0);
        }
    }
};
