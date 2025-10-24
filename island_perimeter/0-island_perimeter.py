#!/usr/bin/python3
"""defines a function that return the island perimeter"""


def island_perimeter(grid):
    """return the island perimeter"""

    if (not grid):
        return 0

    count = 0

    len_row = len(grid)
    len_cell = len(grid[0])

    for i in range(len_row):
        for j in range(len_cell):
            if grid[i][j] == 1:
                if i == 0 or grid[i-1][j] == 0:
                    count += 1
                if i == len_row - 1 or grid[i+1][j] == 0:
                    count += 1
                if j == 0 or grid[i][j-1] == 0:
                    count += 1
                if j == len_cell - 1 or grid[i][j+1] == 0:
                    count += 1
    return count
