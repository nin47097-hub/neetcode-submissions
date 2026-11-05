#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {

        vector<int> A;
        A.push_back(1);
        for (int num : nums) {
            A.push_back(num);
        }
        A.push_back(1);
        
        int n = A.size();
        
   
        vector<vector<int>> memo(n, vector<int>(n, -1));


        return dfs(memo, 1, nums.size(), A);
    }

private:  
    int dfs(vector<vector<int>>& memo, int left, int right, const vector<int>& A){
 
        if (left > right) {
            return 0;
        }

        if (memo[left][right] != -1) {
            return memo[left][right];
        }

       
        int max_coins = 0;

        for (int i = left; i <= right; i++) {
          
            int current = A[i] * A[left - 1] * A[right + 1];

            int left_side = dfs(memo, left, i - 1, A);
        
            int right_side = dfs(memo, i + 1, right, A);

            int total_coins = current + left_side + right_side;

            max_coins = max(max_coins, total_coins);
        }
        
        return memo[left][right] = max_coins;
    }
};

