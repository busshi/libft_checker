#include "../../../../libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void	check(void *dest, void *src, int n)
{
	dest = ft_memcpy(dest, src, n);
	write(1, dest, 26);
	free(dest);
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
		check(mem, "abcdefghijklmnopqrstuvwxyz", 26);
	else if (test == 2)
		check(mem, "abcdefghijklmnopqrstuvwxyz", 10);
        else if (test == 3)
		check(mem, "abcdefghij", 10);
        else if (test == 4)
                check(mem, "abcdefghijklmnop", 10);
        else if (test == 5)
                check(mem, "abcdef\t\n\0abcdef", 15);
	return (0);
}
