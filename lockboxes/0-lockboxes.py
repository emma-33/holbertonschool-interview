#!/usr/bin/python3
"""Module to determine if all boxes can be opened."""


def canUnlockAll(boxes):
    """Determine if all boxes can be opened."""
    compareList = [0]

    for row in compareList:
        for element in boxes[row]:
            if (element not in compareList and element != 0 and
               element < len(boxes)):
                compareList.append(element)

    if len(compareList) != len(boxes):
        return False
    return True
