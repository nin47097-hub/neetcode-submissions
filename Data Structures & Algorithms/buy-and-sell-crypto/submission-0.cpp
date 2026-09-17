class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit =0;
        int buy = prices[0];

        for(int i =0; i<prices.size();i++){
            int price_diff = prices[i]-buy;
            max_profit=max(max_profit,price_diff);

            if(prices[i]<buy){
                buy = prices[i];

            }

        }
        return max_profit;



        
    }
};
