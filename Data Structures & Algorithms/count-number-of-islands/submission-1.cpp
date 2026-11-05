#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> memo(row, vector<int>(cols, -1));
        int count = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && memo[i][j] == -1) {
                    count++;
                    dfs(i, j, grid, memo);
                }
            }
        }
        return count;
    }

private:  
 
    void dfs(int i, int j, const vector<vector<char>>& grid, vector<vector<int>>& memo){
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }

        if (grid[i][j] == '0') {
            return;
        }

        if (memo[i][j] != -1) {
            return;
        }

      
        memo[i][j] = 1;

        dfs(i + 1, j, grid, memo);
        dfs(i, j + 1, grid, memo);
        dfs(i - 1, j, grid, memo);
        dfs(i, j - 1, grid, memo);
    }
};

