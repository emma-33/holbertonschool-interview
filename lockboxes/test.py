#!/usr/bin/python3
"""Module to determine if all boxes can be opened."""


def canUnlockAll(boxes):
    """Determine if all boxes can be opened."""
    newList = [0]
    compareList = [0]

    for i in compareList:
        compareList.append(i)

    for row in compareList:
        for element in boxes[row]:
            if element not in newList and element != 0 and element < len(boxes):
                newList.append(element)

        newList.sort()

    if newList == compareList:
        return True
    else:
        return False
