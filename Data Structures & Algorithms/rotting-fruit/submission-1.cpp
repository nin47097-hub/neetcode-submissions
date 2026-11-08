class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;
          
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    fresh++;
                }
                if(grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }

        while(!q.empty() && fresh > 0){
            int length = q.size();

            for(int i = 0; i < length; i++){
                auto [r, c] = q.front();
                q.pop();

                if(r - 1 >= 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    fresh--;
                    q.push({r - 1, c});
                }

                if(r + 1 < grid.size() && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    fresh--;
                    q.push({r + 1, c});
                }

                if(c - 1 >= 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    fresh--;
                    q.push({r, c - 1});
                }

                if(c + 1 < grid[0].size() && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    fresh--;
                    q.push({r, c + 1});
                }
            }
            time++;
        }

        if(fresh == 0){
            return time;
        } else {
            return -1;
        }
    }
};

