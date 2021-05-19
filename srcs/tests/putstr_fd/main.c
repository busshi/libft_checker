#include "../../../../libft/libft.h"

void	check(char *str, int fd)
{
	ft_putstr_fd(str, fd);
}


int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("qùlkfjqùdklgvqùlkvùm;qmùlvvqm", 1);
	else if (test == 2)
		check("PIUSHD°8927\npoezfkùz\teoijfmoazef", 1);
	else if (test == 3)
		check("coucou\thello", 1);
	else if (test == 4)
		check("coucou\thello", 2);
	else if (test == 5)
		check("", 1);
	else if (test == 6)
		check("", 2);
	return (0);
}

