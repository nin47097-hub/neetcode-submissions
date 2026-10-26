class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return dfs(memo, 0, s);
    }

private: 
    int dfs(vector<int>& memo, int i, const string& s) {
        if (i == s.size()) {
            return 1;
        }

        if (memo[i] != -1) {
            return memo[i];
        }
        
        if (s[i] == '0') {
            return 0;
        }

        int ways = dfs(memo, i + 1, s);

        if (i + 1 < s.size()) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                ways += dfs(memo, i + 2, s);
            }
        }

        return memo[i] = ways;
    }
};

