#include "../../../../libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void	check(void *mem, int c, int n, int mem_size)
{
	memset(mem, c, n);
	ft_bzero(mem, mem_size);
	write(1, mem, n);
	free(mem);
}

int		main(int ac, char **av)
{
	(void)ac;
	void	*mem;
	int	mem_size;
	int	agv;

	alarm(3);
	mem_size = 20;
	if (!(mem = (void *)malloc(sizeof(void) * mem_size)))
		return (0);
	agv = atoi(av[1]);
	if (agv == 1)
		check(mem, 'c', mem_size, 20);
	else if (agv == 2)
		check(mem, '\0', mem_size, 15);
        else if (agv == 3)
		check(mem, 'a', mem_size, 10);
        else if (agv == 4)
                check(mem, ' ', mem_size, 5);
        else if (agv == 5)
                check(mem, '\n', mem_size, 0);
	return (0);
}
