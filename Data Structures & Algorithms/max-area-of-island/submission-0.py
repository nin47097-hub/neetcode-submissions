class Solution(object):
    def maxAreaOfIsland(self, grid):

        visited = set()

        rows = len(grid)
        cols = len(grid[0])

        def dfs(r, c):

            if r < 0 or c < 0 or r >= rows or c >= cols:
                return 0

            if grid[r][c] == 0:
                return 0

            if (r, c) in visited:
                return 0

            visited.add((r, c))

            area = 1

            area += dfs(r + 1, c)
            area += dfs(r - 1, c)
            area += dfs(r, c + 1)
            area += dfs(r, c - 1)

            return area

        maxArea = 0

        for r in range(rows):
            for c in range(cols):

                if grid[r][c] == 1 and (r, c) not in visited:
                    area = dfs(r, c)
                    maxArea = max(maxArea, area)

        return maxArea