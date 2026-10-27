class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -2); 
        return dfs(coins, amount, memo);
    }

private: 
    int dfs(vector<int>& coins, int rem, vector<int>& memo){
      
        if (rem < 0) {
            return -1;
        }
        if (rem == 0) {
            return 0;
        }
        if (memo[rem] != -2) {
            return memo[rem];
        }

        int minc = INT_MAX;
        int result;

        
        for (int coin : coins) {
           
            result = dfs(coins, rem - coin, memo);
           
            if (result >= 0 && result < minc) {
                minc = result + 1;
            }
        }

       
        if (minc == INT_MAX) {
            memo[rem] = -1;
        } else {
            memo[rem] = minc;
        }
        
        return memo[rem];
    }
};
