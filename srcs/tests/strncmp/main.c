#include "../../../../libft/libft.h"
#include <stdio.h>
#include <string.h>

void	check(char const *s1, char const *s2, size_t n)
{
	printf("%d", ft_strncmp(s1, s2, n));
}


int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("a", "A", 1);
	else if (test == 2)
		check("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyy", 26);
	else if (test == 3)
		check("coucou\thello", "coucou hello", 10);
	else if (test == 4)
		check("", "", 2);
	else if (test == 5)
		check("", " ", 1);
	else if (test == 6)
		check(" ", "", 0);
	else if (test == 7)
		check("hello", "\n", 5);
	return (0);
}

