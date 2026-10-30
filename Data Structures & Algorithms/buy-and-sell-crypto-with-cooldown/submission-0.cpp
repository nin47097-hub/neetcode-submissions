class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return dfs(0, 1, memo, prices);
    }

private:  
    int dfs(int i, int buy, vector<vector<int>>& memo, vector<int>& prices) {
        if (i >= prices.size()) {
            return 0;
        }

        if (memo[i][buy] != -1) {
            return memo[i][buy];
        }

        if (buy == 0) {
            int sell = prices[i] + dfs(i + 2, 1, memo, prices);
            int skip = dfs(i + 1, 0, memo, prices);
            memo[i][buy] = max(sell, skip);
        }
        else if (buy == 1) {
            int skip = dfs(i + 1, 1, memo, prices);             
            int buyStock = -prices[i] + dfs(i + 1, 0, memo, prices);
            memo[i][buy] = max(buyStock, skip);
        }

        return memo[i][buy];
    }
};

