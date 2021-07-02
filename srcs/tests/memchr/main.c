#include "../../../../libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void	check(void *mem, int c, size_t n)
{
	const char	*temp;

	temp = ft_memchr(mem, c, n);
	if (!temp)
		write(1, "NULL", 4);
	else
		write(1, mem, strlen(mem));
}

int		main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("abcdefghijklmnopqrstuvwxyz", 'z', 26);
	else if (test == 2)
		check("abcabcabcabc", 'c', 1);
        else if (test == 3)
		check("abcabcabcabcd", 'd', 4);
        else if (test == 4)
                check("abcabcabcabcd", 'd', 13);
        else if (test == 5)
                check("abcabcabcabc", 'z', 12);
	return (0);
}
