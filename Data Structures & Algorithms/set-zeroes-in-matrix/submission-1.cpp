class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> mmm = matrix;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (mmm[i][j] == 0) {
                    dfs(i - 1, j, -1, 0, matrix); 
                    dfs(i, j - 1, 0, -1, matrix); 
                    dfs(i + 1, j, 1, 0, matrix);  
                    dfs(i, j + 1, 0, 1, matrix);  
                }
            }
        }
    }

private:
    void dfs(int i, int j, int dr, int dc, vector<vector<int>>& matrix) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()) {
            return;
        }
        
        matrix[i][j] = 0;

        dfs(i + dr, j + dc, dr, dc, matrix);
    }
};

