#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_struct.h"

#define DICTIONARY "numbers.dict"

int	is_nbr_valid(char *str)
{
	int i = 0;
	while (str[i])
	{
		if(!(str[i] >= '0' && str[i] <='9'))
			return 1;
	}
	return 0;
}

int	count_lines(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if(str[i] == '\n')
			count++;
		i++;	
	}
	return count;
}

int	strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

t_number	*parse_dict(char *str)
{
	int	i;
	int	lines;
	int size;
	int	t_number_indexl;
	t_number *res;

	lines = count_lines(str) + 1;
	res = malloc(sizeof(t_number) * (lines));
	if (!res)
		return (NULL);
	size = 0;
	t_number_indexl = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			size++;
		
	}
	return (res);
}
