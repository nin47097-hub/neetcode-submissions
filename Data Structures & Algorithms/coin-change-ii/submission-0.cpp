class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>memo(coins.size(), vector<int>(amount+1, -1));

        return dfs(amount, 0, memo, coins);


        
    }


private:  
    int dfs(int remamount, int index, vector<vector<int>>& memo, vector<int>& coins){
        if(remamount ==0){
            return 1;
        }

        if(remamount<=0 || index>=coins.size()){
            return 0;
        }
        if(memo[index][remamount] != -1){
            return memo[index][remamount];
        }

        int take  = dfs(remamount-coins[index], index, memo, coins );
        int skip = dfs(remamount, index+1, memo, coins);

        return memo[index][remamount] = take+ skip;

    }
};



