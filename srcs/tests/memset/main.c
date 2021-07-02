#include "../../../../libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void	check(void *mem, int c, int n, int mem_size)
{
	ft_memset(mem, c, n);
	write(1, mem, mem_size);
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
	memset(mem, '@', mem_size);
	agv = atoi(av[1]);
	if (agv == 1)
		check(mem, 'c', 3, mem_size);
	else if (agv == 2)
		check(mem, '\0', 1, mem_size);
        else if (agv == 3)
		check(mem, 'a', 5, mem_size);
        else if (agv == 4)
                check(mem, ' ', 10, mem_size);
        else if (agv == 5)
                check(mem, '\n', 19, mem_size);
	return (0);
}
