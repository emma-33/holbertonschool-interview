#include "substring.h"
#include <stdlib.h>
#include <string.h>

/**
 * find_substring - finds all the possible substrings containing
 * a list of words, within a given string
 * 
 * @s: string to scan
 * @words: array of words all substrings must be a
 * concatenation arrangement of nb_words
 * @nb_words: number of elements in the array words
 * @n: address at which to store the number of elements in the returned array
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, j, k;
    int *result = NULL;
    int word_len, string_len, sub_len;
    int count = 0;

    int expected[nb_words], current[nb_words];
    
    word_len = strlen(words[0]);
    sub_len = nb_words * word_len;
    string_len = strlen(s);
    
    
	if (!s || !words || !(*words) || !nb_words || !n)
    return (NULL);
    
    if (string_len < sub_len)
    return (NULL);
    
    result = malloc(sizeof(int) * string_len);

    memset(expected, 0, sizeof(int) * nb_words);

    for (i = 0; i < nb_words; i++)
    {
        for (j = 0; j < nb_words; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
                expected[i]++;
        }
    }

    for (i = 0; i <= string_len - sub_len ; i++)
    {
        memset(current, 0, sizeof(int) * nb_words);
        
        for(j = 0; j < nb_words; j++)
        {
            const char *chunk = s + i + j * word_len;
            int found = -1;

            for (k = 0; k < nb_words; k++)
            {
                if (strncmp(chunk, words[k], word_len) == 0)
                {
                    found = k;
                    break;
                }
                
            }
            if (found == -1)
                break;

            current[found]++;
            if (current[found] > expected[found])
                break;
        }
        if (j == nb_words)
            result[count++] = i;
    }

    if (count == 0)
    {
        free(result);
        return NULL;
    }
    *n = count;
	return (result);
}
