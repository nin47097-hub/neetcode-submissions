from collections import defaultdict
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = defaultdict(set)
        column = defaultdict(set)
        square = defaultdict(set)

        for i in range(9):
            for j in range(9):
                

                if board[i][j] ==".":
                    continue
                square_coordinate = (i//3,j//3)

                if (board[i][j] in row[i] or board[i][j] in column[j] or board[i][j] in square[square_coordinate]):
                    return False

                

                row[i].add(board[i][j])
                column[j].add(board[i][j])
                square[square_coordinate].add(board[i][j])

        return True

        