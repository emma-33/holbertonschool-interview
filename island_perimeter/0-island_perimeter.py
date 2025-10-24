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
                if grid[i-1][j] == 0 or i == 0:
                    count += 1
                if grid[i+1][j] == 0 or i == len_row - 1:
                    count += 1
                if grid[i][j-1] == 0 or j == 0:
                    count += 1
                if grid[i][j+1] == 0 or j == len_cell - 1:
                    count += 1
    return count
