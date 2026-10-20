#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
       
        vector<int> memo(n + 1, -1);
        return dfs(n, memo);
    }

private:  
    int dfs(int current, vector<int>& memo){
 
        if(current <= 3){
            return current;
        }

        if(memo[current] != -1){
            return memo[current];
        }

        memo[current] = dfs(current - 1, memo) + dfs(current - 2, memo);
        return memo[current];
    }
};
