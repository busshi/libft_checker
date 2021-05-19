#include "../../../../libft/libft.h"
#include <stdio.h>

void	check(const char *haystack, const char *needle, size_t len)
{
	printf("%s", ft_strnstr(haystack, needle, len));
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("abcdefghijklmnopqrstuvwxyz", "z", 26);
	else if (test == 2)
		check("abcdefghijklmnopqrstuvwxyz", "z", 25);
	else if (test == 3)
		check("hello", "", 10);
	else if (test == 4)
		check("hel\tlo", "l\tl", 5);
	else if (test == 5)
		check("abcd\refgh\nijklmnop", "\r", 18);
	else if (test == 6)
		check("abcd\refgh\nijklmnop", "\n", 20);
	else if (test == 7)
		check("0123456789012356789", "12356", 20);
	else if (test == 8)
		check("coucou ça va ?", "va", 20);
	else if (test == 9)
		check("coucou ça va", "va", 20);
	return (0);
}
