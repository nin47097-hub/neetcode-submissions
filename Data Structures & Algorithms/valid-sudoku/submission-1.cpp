class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> columns[9];
        unordered_set<char> squares[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
               
                if (board[i][j] == '.') {
                    continue;
                }

                char val = board[i][j];
                int square_idx = (i / 3) * 3 + (j / 3);

         
                if (rows[i].count(val) || 
                    columns[j].count(val) || 
                    squares[square_idx].count(val)) {
                    return false;
                }

     
                rows[i].insert(val);
                columns[j].insert(val);
                squares[square_idx].insert(val);
            }
        }
        

        return true;
        

        
    }
};
