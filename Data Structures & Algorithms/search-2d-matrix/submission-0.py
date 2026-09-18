class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        matrix_col = len(matrix[0])
        matrix_r = len(matrix)
        r =matrix_r-1
        c = 0

        while r>=0  and c<matrix_col:
            if matrix[r][c]< target:
                c+=1

            elif matrix[r][c]> target:
                r-=1


            elif matrix[r][c]== target:
                return True


        return False
        