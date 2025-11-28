#!/usr/bin/python3
"""
Maria and Ben are playing a game. Given a set of consecutive integers
starting from 1 up to and including n, they take turns choosing a prime number
in the set and removing that number and its multiples from the set.
The player that cannot make a move loses the game.
"""


def isPrime(n):
    """ checks if given num is prime """
    if n <= 1:
        return(False)
    else:
        is_prime = True
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                is_prime = False
                break
        return(is_prime)


def deleteNums(n, nums):
    """ delete numbers """
    for i in range(len(nums)):
        if nums[i] % n == 0:
            nums[i] = 0


def isWinner(x, nums):
    """
    Determines the winner of the prime game
    x : number of rounds
    nums : array of numbers
    Return : name of winner or None if no winner found
    """
    nums.sort()
    Maria = 0
    Ben = 0
    for round in range(x):
        nums2 = list(range(1, nums[round] + 1))
        turn = 0
        while True:
            change = False
            for i, n in enumerate(nums2):
                if n > 1 and isPrime(n):
                    deleteNums(n, nums2)
                    change = True
                    turn += 1
                    break
            if change is False:
                break
        if turn % 2 != 0:
            Maria += 1
        else:
            Ben += 1
    return None if Maria == Ben else ("Maria" if Maria > Ben else "Ben")
