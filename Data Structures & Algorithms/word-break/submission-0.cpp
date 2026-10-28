class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std:: unordered_set<std::string> wordset(wordDict.begin(), wordDict.end());

        int n = s.size();
        std::vector<bool> dp(n+1, false);
        dp[0] = true;


        for(int i =0; i<= n;i++){
            for(int j =0; j<i;j++){
                if(dp[j]&& wordset.count(s.substr(j,i-j))){
                    dp[i]=true;



                }
                


                
            }
        }
        return dp[n];


        
       

        
    }
};
