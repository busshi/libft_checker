#include "../../../../libft.h"
#include <stdio.h>
#include <string.h>

void	check(char const *s1, char const *set)
{
	printf("%s", ft_strtrim(s1, set));
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("abcdefghijklmnopqrstuvwxyz abc", "c");
	else if (test == 2)
		check("0123456789", "456");
	else if (test == 3)
		check("" , "");
	else if (test == 4)
		check(" ", " ");
	else if (test == 5)
		check("abcd\refgh\nijklmnop", "\r");
	else if (test == 6)
		check("abcd\refgh\nijklmnop", "\n");
	else if (test == 7)
		check("\t01234\n56789\t0", "\t\n");
	else if (test == 8)
		check("\t01234\n56789\t0", "\n\t");
	else if (test == 9)
		check("abcdef" , "fghijkl");
	else if (test == 10)
		check("               ", "\n\t ");
	return (0);
}
