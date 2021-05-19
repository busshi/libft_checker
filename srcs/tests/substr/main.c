#include "../../../../libft/libft.h"
#include <stdio.h>
#include <string.h>

void	check(char *s, unsigned int start, size_t len)
{
	printf("%s", ft_substr(s, start, len));
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("abcdefghijklmnopqrstuvwxyz", 10, 26);
	else if (test == 2)
		check("0123456789ABCDEF", 0, 5);
	else if (test == 3)
		check(" " , 0, 1);
	else if (test == 4)
		check("", 1, 10);
	else if (test == 5)
		check("abcd\refgh\nijklmnop", 5, 18);
	else if (test == 6)
		check("abcd\refgh\nijklmnop", 10, 30);
	else if (test == 7)
		check("\t01234\t56789\t", 0, 20);
	return (0);
}
