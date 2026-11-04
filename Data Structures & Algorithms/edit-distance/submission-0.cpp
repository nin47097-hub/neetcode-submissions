#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int rows = word1.size();
        int cols = word2.size();
        
        
        vector<vector<int>> memo(rows, vector<int>(cols, -1));
        return dfs(memo, 0, 0, word1, word2);
    }

private:  
    int dfs(vector<vector<int>>& memo, int index, int j, string& word1, string& word2) {
      
        if (index >= word1.size()) {
            return word2.size() - j;
        }

        if (j >= word2.size()) {
            return word1.size() - index;
        }

        
        if (memo[index][j] != -1) {
            return memo[index][j];
        }

      
        if (word1[index] == word2[j]) {
            return memo[index][j] = dfs(memo, index + 1, j + 1, word1, word2);
        }

        
        int insert  = dfs(memo, index, j + 1, word1, word2);      
        int delete1 = dfs(memo, index + 1, j, word1, word2);      
        int replace = dfs(memo, index + 1, j + 1, word1, word2);  

        return memo[index][j] = 1 + min({insert, replace, delete1});
    }
};

