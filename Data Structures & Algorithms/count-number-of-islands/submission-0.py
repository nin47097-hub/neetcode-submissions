class Solution(object):
    def numIslands(self, grid):

        visited = set()
        island = 0

        row = len(grid)
        column = len(grid[0])

        def dfs(i, j):

     
            if i < 0 or j < 0 or i >= row or j >= column:
                return

            if grid[i][j] == "0":
                return


            if (i, j) in visited:
                return


            visited.add((i, j))

            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        for i in range(row):
            for j in range(column):

                if grid[i][j] == "1" and (i, j) not in visited:
                    island += 1
                    dfs(i, j)

        return island
        