#include "../../../../libft.h"
#include <stdio.h>
#include <string.h>

void	check(char const *s1, char const *s2)
{
	printf("%s", ft_strjoin(s1, s2));
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("abcdefghijklmnopqrstuvwxyz", "0123456789");
	else if (test == 2)
		check("0123456789", "abcdefghijkl");
	else if (test == 3)
		check("" , "");
	else if (test == 4)
		check(" ", " ");
	else if (test == 5)
		check("abcd\refgh\nijklmnop", "\t\t\t123");
	else if (test == 6)
		check("abcd\refgh\nijklmnop", "\n");
	else if (test == 7)
		check("\t01234\t56789\t0", "\0abcdef");
	return (0);
}
