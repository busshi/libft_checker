#include "../../../../libft/libft.h"
#include <string.h>

void	check(char *str)
{
	ft_putendl(str);
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
		check("coucou\thello\n");
	else if (test == 5)
		check("");
	else if (test == 6)
		check("\v\t\n\r       \r\t\v");
	return (0);
}

