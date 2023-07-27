#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - Divides words of a string
 *
 * @str: Divides strings into words
 * @delims: To delimit words
 *
 * Return: 2D array of pointers to every word
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, a = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (a < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[a] = malloc((wordLen + 1) * sizeof(char));
		if (words[a] == NULL)
		{
			while (a >= 0)
			{
				a--;
				free(words[a]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[a][n] = *(str + n);
			n++;
		}
		words[a][n] = '\0'; /* set end of str */
		str = get_next_word(str, delims);
		a++;
	}
	words[a] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 * is_delim - Confirms if stream has delimitor char
 *
 * @ch: The character in stream
 *
 * @delims: Pointer to null the terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delims)
{
	int a = 0;

	while (delims[a])
	{
		if (delims[a] == ch)
			return (1);
		a++;
	}
	return (0);
}

/**
 * get_word_length - This gets the word length of words in a string
 *
 * @str: A string to get the word length from current word
 * @delims: Delimitors to delimit words of string
 *
 * Return: The word length of a current word
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[a], delims))
			break;
		a++;
	}
	return (wLen);
}

/**
 * get_word_count - This gets the word count of a string
 *
 * @str: A string to get word count from
 * @delims: Delimitors to delimit words of string
 *
 * Return: Word count of the string
 */

int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		a++;
	}
	return (wc);
}

/**
 * get_next_word - This gets the next word in a string
 *
 * @str: A string to get the next word from
 * @delims: Delimitors to delimit words of string
 *
 * Return: A pointer to first char of next word
 */

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			pending = 1;
		else if (pending)
			break;
		a++;
	}
	return (str + a);
}
