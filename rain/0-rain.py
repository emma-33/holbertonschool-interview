#!/usr/bin/python3


"""
0-rain
"""


def rain(walls):
    """
    Calculate the amount of rainwater that can be trapped
    after raining given a list of wall heights.

    :param walls: List of integers representing wall heights
    :return: Integer representing the total amount of trapped rainwater
    """
    if not walls:
        return 0

    result = 0

    for i in range(1, len(walls) - 1):
        left_max = walls[i]
        right_max = walls[i]

        for j in range(i):
            left_max = max(left_max, walls[j])

        for j in range(i + 1, len(walls)):
            right_max = max(right_max, walls[j])

        result += min(left_max, right_max) - walls[i]

    return result
