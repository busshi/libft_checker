#include "../../../../libft/libft.h"
#include <stdio.h>
#include <string.h>

void	check(char const *s1, char const *s2)
{
	printf("%d", ft_strcmp(s1, s2));
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("a", "A");
	else if (test == 2)
		check("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyy");
	else if (test == 3)
		check("coucou\thello", "coucou hello");
	else if (test == 4)
		check("", "");
	else if (test == 5)
		check("", " ");
	else if (test == 6)
		check(" ", "");
	else if (test == 7)
		check("hello", "\n");
	return (0);
}

