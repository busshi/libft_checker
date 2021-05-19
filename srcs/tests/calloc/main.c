#include "../../../../libft/libft.h"
#include <stdio.h>
#include <string.h>

void	check(size_t n, size_t size)
{
	char	*str;

	str = (char *)ft_calloc(n, size);
	if (!str)
		write(1, "NULL", 4);
	else
		write(1, str, n);
	free(str);	
}


int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check(10, sizeof(char));
	else if (test == 2)
		check(10, sizeof(int));
	else if (test == 3)
		check(30, sizeof(char));
	else if (test == 4)
		check(30, sizeof(int));
	return (0);
}

