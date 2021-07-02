#include "../../../../libft.h"
#include <stdio.h>
#include <ctype.h>


void	check(int start, int end)
{
	int	c;

	while (start <= end)
	{
		c = ft_tolower(start);
		write(1, &c, 1);
		start++;
	}
}


int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int	test;
	
	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check('0', '9');
	else if (test == 2)
		check('a', 'z');
	else if (test == 3)
		check('Z', 'Z');
	else if (test == 4)
		check(0, 47);
	else if (test == 5)
		check(58, 64);
	else if (test == 6)
		check(91, 127);
	return (0);
}

