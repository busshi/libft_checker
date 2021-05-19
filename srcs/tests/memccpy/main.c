#include "../../../../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void	check(void *dest, void *src, int c, int n)
{
	void	*memcp;

	memcp = dest;
	dest = ft_memccpy(dest, src, c, n);
	write(1, memcp, 26);
	free(memcp);
}

int		main(int ac, char **av)
{
	(void)ac;
	void	*mem;
	int	mem_size;
	int	test;

	alarm(3);
	mem_size = 26;
	if (!(mem = (void *)malloc(sizeof(void) * mem_size)))
		return (0);
	memset(mem, '@', mem_size);
	test = atoi(av[1]);
	if (test == 1)
		check(mem, "abcdefghijklmnopqrstuvwxyz", 'd', 26);
	else if (test == 2)
		check(mem, "abcdefghijklmnopqrstuvwxyz", 'z', 10);
        else if (test == 3)
		check(mem, "abcdefghij", 'i', 10);
        else if (test == 4)
                check(mem, "abcdefghijklmnop", 'i', 15);
        else if (test == 5)
                check(mem, "abcdef\t\n\0abcdef", '\0', 15);
	return (0);
}
