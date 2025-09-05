#!/usr/bin/python3

""" Rotate 2d matrix """


def rotate_2d_matrix(matrix):
    """
    Rotates a 2d matrix clockwise

    :param matrix: matrix to be rotated
    """
    length = len(matrix)

    for i in range(length):
        for j in range(i + 1, length):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    for row in matrix:
        row.reverse()
