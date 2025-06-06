#!/usr/bin/python3
"""
Determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    next_bytes = 0

    for num in data:
        byte = num & 0xFF

        if next_bytes == 0:
            if byte < 128:
                continue
            elif byte < 192:
                return False
            elif byte < 224:
                next_bytes = 1
            elif byte < 240:
                next_bytes = 2
            elif byte < 248:
                next_bytes = 3
            else:
                return False
        else:
            if byte < 128 or byte >= 192:
                return False
            next_bytes -= 1

    if next_bytes == 0:
        return True
    else:
        return False
