#include "../../../../libft.h"
#include <stdio.h>
#include <string.h>

void	check(const char *s)
{
	printf("%s", ft_strdup(s));
}


int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("coucou ça va");
	else if (test == 2)
		check("coucou ça va bien ?");
	else if (test == 3)
		check("§/.?098ZPOIIIIIIJSNXMLQKM=)");
	else if (test == 4)
		check("");
	else if (test == 5)
		check(" ");
	else if (test == 6)
		check("abcdef\tghijklmnop\nqrst\vuvwxyz");
	else if (test == 7)
		check("\n\t\n\t");
	else if (test == 8)
		check("ABCDEFGH IJKLMNOP\n)&1234659");
	else if (test == 9)
		check("coucou\n\0");
	return (0);
}

