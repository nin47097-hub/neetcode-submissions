from collections import deque

class Solution(object):
    def orangesRotting(self, grid):

        s = deque()
        fresh = 0
        minut = 0

        directions = [
            (1, 0),
            (-1, 0),
            (0, 1),
            (0, -1)
        ]

        rows = len(grid)
        cols = len(grid[0])

        for i in range(rows):
            for j in range(cols):

                if grid[i][j] == 2:
                    s.append((i, j))

                elif grid[i][j] == 1:
                    fresh += 1

        while s and fresh > 0:

            minut += 1
            siz = len(s)

            for _ in range(siz):

                r, c = s.popleft()

                for x, y in directions:

                    nr = r + x
                    nc = c + y

                    if (
                        0 <= nr < rows and
                        0 <= nc < cols and
                        grid[nr][nc] == 1
                    ):

                        grid[nr][nc] = 2
                        fresh -= 1
                        s.append((nr, nc))

        return minut if fresh == 0 else -1