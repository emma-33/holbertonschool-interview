#ifndef SUBSTRING_H
#define SUBSTRING_H

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int is_valid(const char *s, int start, const char **words, int nb_words,
int word_len, int *expected, int *current);

#endif /*SUBSTRING_H*/
