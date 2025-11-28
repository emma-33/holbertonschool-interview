#!/usr/bin/python3
"""
Maria and Ben are playing a game. Given a set of consecutive integers
starting from 1 up to and including n, they take turns choosing a prime number
in the set and removing that number and its multiples from the set.
The player that cannot make a move loses the game.
"""


def prime(n):
    """ creates a list of prime nums """
    if n <= 1:
        return []

    prime_nums = [True] * (n + 1)
    prime_nums[0] = prime_nums[1] = False

    for i in range(2, int(n**0.5) + 1):
        if prime_nums[i]:
            for j in range(i * i, n + 1, i):
                prime_nums[j] = False
    return prime_nums


def isWinner(x, nums):
    """
    Determines the winner of the prime game
    x : number of rounds
    nums : array of numbers
    Return : name of winner or None if no winner found
    """
    if x < 1 or not nums:
        return None

    Maria = 0
    Ben = 0

    max_num = max(nums)
    prime_nums = prime(max_num)

    prime_count = [0] * (max_num + 1)
    count = 0

    for i in range(2, max_num + 1):
        if prime_nums[i]:
            count += 1
        prime_count[i] = count

    for n in nums:
        if prime_count[n] % 2 != 0:
            Maria += 1
        else:
            Ben += 1

    return None if Maria == Ben else ("Maria" if Maria > Ben else "Ben")
