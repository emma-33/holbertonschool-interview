#!/usr/bin/python3
""" Counts occurrences of words in hot subreddit titles"""

import json
import requests


def count_words(subreddit, word_list, result=None, after=None):
    """Counts occurrences of words in hot subreddit titles.
    Args:
        subreddit (str): The name of the subreddit.
        word_list (list): A list of words to count in titles.
        result (dict, optional): A dictionary to hold word counts.
        after (str, optional): Pagination token for the next set of results.
    """
    base_url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    if after is None:
        subreddit_url = base_url
    else:
        subreddit_url = f'{base_url}?after={after}'

    request = requests.get(
        subreddit_url,
        headers={'User-Agent': 'Mozilla/5.0'},
        allow_redirects=False
    )

    if request.status_code != 200:
        return None

    data = request.json()["data"]
    children = data["children"]

    for child in children:
        for word in word_list:
            lowered_word = word.lower()
            lowered_title = child["data"]["title"].lower()
            title_count = lowered_title.split().count(lowered_word)

            if lowered_word in lowered_title:
                if result is None:
                    result = {}
                if lowered_word in result:
                    result[lowered_word] += title_count
                else:
                    result[lowered_word] = title_count

    after = data["after"]
    if result is None:
        for word in word_list:
            result[word] = 0

    if after is None:
        word_list = [[k, v] for k, v in result.items()]
        word_list = sorted(word_list, key=lambda x: x[0])

        for word in word_list:
            if word[1] > 0:
                print(f"{word[0]}: {word[1]}")
        return None
    else:
        return count_words(subreddit, word_list, result, after)
