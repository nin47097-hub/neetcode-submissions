class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int>arrr(num1.size()+ num2.size(), 0);
        int m = num1.size();
        int n = num2.size();
        if(num1=="0" || num2=="0"){
            return "0";
        }
        for(int i = m-1; i>=0;i--){
            for(int j =  n-1;j>=0; j--){
                arrr[i+j+1] += (num1[i]-'0')* (num2[j]-'0');
                arrr[i+j] += arrr[i+j+1]/10;
                arrr[i+j+1] %=10;
            }
        }
        int idx = 0;
        string seed ="";
        while(idx < arrr.size() && arrr[idx]==0){
            idx++;
        }
        while(idx < arrr.size()){

            seed += to_string(arrr[idx]);
            idx++;
        }
        return seed;
    }
};
