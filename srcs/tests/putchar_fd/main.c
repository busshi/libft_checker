#include "../../../../libft/libft.h"


void	check(int start, int end, int fd)
{
	while (start <= end)
	{
		ft_putchar_fd((char)start, fd);
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
		check(0, 127, 1);
	else if (test == 2)
		check('0', '~', 1);
	else if (test == 3)
		check(0, 127, 2);
	else if (test == 4)
		check('0', '~', 2);
	else if (test == 5)
		check('\n', '\t', 1);
	else if (test == 6)
		check('\n', '\t', 2);
	return (0);
}

