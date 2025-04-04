#!/usr/bin/python3
"""Module to determine if all boxes can be opened."""


def canUnlockAll(boxes):
    """Determine if all boxes can be opened."""
    newList = [0]
    compareList = [0]

    for i in range(1, len(boxes)):
        compareList.append(i)

    for row in boxes:
        for element in row:
            if element not in newList and element != 0:
                newList.append(element)
                break
            elif element in newList:
                continue

        newList.sort()


    if newList == compareList:
        return True
    else:
        return False
