#include "../../../../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void	check(void *dest, void *src, int n)
{
	dest = ft_memmove(dest, src, n);
	write(1, dest, 26);
}

int		main(int ac, char **av)
{
	(void)ac;
	char	src[] = "coucou ça va ? bienvenue... ";
	char	*dest;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	dest = src + 1;
	if (test == 1)
		check(dest, "abcdefghijklmnopqrstuvwxyz", 26);
	else if (test == 2)
		check(dest, "abcdefghi\tjklmnopq", 10);
        else if (test == 3)
		check(dest, src, 10);
        else if (test == 4)
                check(src, dest, 10);
        else if (test == 5)
                check(src, dest, 0);
	return (0);
}
