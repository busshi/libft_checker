#include "../../../../libft/libft.h"
#include <stdio.h>
#include <string.h>

void	check(const char *haystack, const char *needle)
{
	printf("%s", ft_strstr(haystack, needle));
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("abcdefghijklmnopqrstuvwxyz", "z");
	else if (test == 2)
		check("abcdefghijklmnopqrstuvwxyz", "a");
	else if (test == 3)
		check("hello", "");
	else if (test == 4)
		check("hel\tlo", "l\tl");
	else if (test == 5)
		check("abcd\refgh\nijklmnop", "\r");
	else if (test == 6)
		check("abcd\refgh\nijklmnop", "\n");
	else if (test == 7)
		check("0123456789012356789", "12356");
	else if (test == 8)
		check("coucou ça va ?", "va");
	else if (test == 9)
		check("coucou ça va", "va");
	return (0);
}
