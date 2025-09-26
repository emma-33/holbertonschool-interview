#!/usr/bin/python3
"""
    A script that determines the fewest number of coins needed to meet a given
    amount "total", given a pile of coins of different values.
"""


def makeChange(coins, total):
    """
        Determines the fewest number of coins needed to meet a given amount
        total.

        Args:
            coins (list): a list of coins of different values.
            total (int): the target amount.

        Returns:
            fewest number of coins needed to meet total.
            If total is 0 or less, return 0.
            If total cannot be met by any number of coins you have, return -1.
    """
    coins.sort(reverse=True)
    result = 0

    if total <= 0:
        return 0

    for coin in coins:
        if total % coin <= total:
            result += total // coin
            total = total % coin

    if total == 0:
        return result
    else:
        return -1
