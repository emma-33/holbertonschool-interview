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

    if total <= 0:
        return 0
    if not coins:
        return -1

    result = [total + 1] * (total + 1)
    result[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount:
                result[amount] = min(result[amount], result[amount - coin] + 1)

    if result[total] <= total:
        return result[total]
    else:
        return -1
