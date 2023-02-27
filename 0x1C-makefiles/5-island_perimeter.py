#!/usr/bin/python3
"""A function that returns the perimeter of the island described in grid"""


def island_perimeter(grid):
    """Return:
            the perimeter of the island described in grid
    """
    row_num = len(grid)
    col_num = len(grid[0])
    island_cell = 0
    neighbour_cell = 0

    for i in range(row_num):
        for j in range(col_num):
            if grid[i][j] == 1:
                island_cell += 1
                if i + 1 < row_num and grid[i + 1][j] == 1:
                    neighbour_cell += 1
                if j + 1 < col_num and grid[i][j + 1] == 1:
                    neighbour_cell += 1

    return island_cell * 4 - neighbour_cell * 2
