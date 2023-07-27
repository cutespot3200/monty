#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);

/**
 * get_int - gets a character pointer to new string containing int
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int lent = 0;
	long num_2 = 0;
	char *ret;

	temp = _abs(num);
	lent = get_numbase_len(temp, 10);

	if (num < 0 || num_2 < 0)
		lent++; /* negative sign */
	ret = malloc(lent + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, lent);
	if (num < 0 || num_2 < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - determines  the absolute value of an integer
 * @i: int to get absolute value of
 *
 * Return: the unsigned int abs rep of i
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - displays len of buffer needed for an unsigned int
 * @num: the num to get len needed for
 * @base: the base of num representation used by buffer
 *
 * Return: int containing len of buffer needed (doesn't contain null bt)
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - this fills buffer with correct num up to base 36
 * @num: the  num to convert to string given base
 * @base: the base of num used in conversion, only works up to base 36
 * @buff: the buffer to fill with result of conversion
 * @buff_size: the size of buffer in bytes
 *
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int remi, a = buff_size - 1;

	buff[buff_size] = '\0';
	while (a >= 0)
	{
		remi = num % base;
		if (remi > 9)
			buff[a] = remi + 87;
		else
			buff[a] = remi + '0';
		num /= base;
		a--;
	}
}
