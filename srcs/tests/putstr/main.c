#include "../../../../libft.h"

void	check(char *str)
{
	ft_putstr(str);
}


int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("qùlkfjqùdklgvqùlkvùm;qmùlvvqm");
	else if (test == 2)
		check("PIUSHD°8927\npoezfkùz\teoijfmoazef");
	else if (test == 3)
		check("coucou\thello");
	else if (test == 4)
		check("\n                \t\t\n\n\r\t\v");
	else if (test == 5)
		check("");
	else if (test == 6)
		check(" ");
	return (0);
}

