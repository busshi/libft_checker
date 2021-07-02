#include "../../../../libft.h"


void	check(int start, int end)
{
	while (start <= end)
	{
		ft_putchar((char)start);
		start++;
	}
}


int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check(0, 127);
	else if (test == 2)
		check('0', '~');
	else if (test == 3)
		check('\n', '\t');
	return (0);
}

