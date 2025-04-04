#!/usr/bin/python3
"""Module to determine if all boxes can be opened."""

def canUnlockAll(boxes):
    """Determine if all boxes can be opened."""
    newList = []
    compareList= []

    for i in range(1, len(boxes)):
        compareList.append(i)

    for row in boxes:
        for element in row[:1]:
            if element not in newList and element != 0:
                newList.append(element)
        newList.sort()

    if newList == compareList:
        return True
    else:
        return False
