#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int row = heights.size();
        int column = heights[0].size();

       
        vector<vector<bool>> pacific(row, vector<bool>(column, false));
        vector<vector<bool>> atlantic(row, vector<bool>(column, false));

        
        for (int i = 0; i < row; ++i) {
            dfs(i, 0, pacific, heights, -1, row, column);
        }
        for (int j = 0; j < column; ++j) {
            dfs(0, j, pacific, heights, -1, row, column);
        }

    
        for (int i = 0; i < row; ++i) {
            dfs(i, column - 1, atlantic, heights, -1, row, column);
        }
        for (int j = 0; j < column; ++j) {
            dfs(row - 1, j, atlantic, heights, -1, row, column);
        }

        
        vector<vector<int>> result;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& heights, int prevHeight, int row, int column) {
        
        if (i < 0 || j < 0 || i >= row || j >= column) {
            return;
        }

        
        if (visited[i][j]) {
            return;
        }

        
        if (heights[i][j] < prevHeight) {
            return;
        }


        visited[i][j] = true;

        dfs(i + 1, j, visited, heights, heights[i][j], row, column);
        dfs(i - 1, j, visited, heights, heights[i][j], row, column);
        dfs(i, j + 1, visited, heights, heights[i][j], row, column);
        dfs(i, j - 1, visited, heights, heights[i][j], row, column);
    }
};

