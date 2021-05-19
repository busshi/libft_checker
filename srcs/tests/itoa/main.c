#include "../../../../libft/libft.h"
#include <stdio.h>

void	check(int n)
{
	printf("%s", ft_itoa(n));
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check(123456789);
	else if (test == 2)
		check(0);
	else if (test == 3)
		check(-1);
	else if (test == 4)
		check(1);
	else if (test == 5)
		check(2147483647);
	else if (test == 6)
		check(-2147483648);
	else if (test == 7)
		check(-2147483648L);
	else if (test == 8)
		check(0101);
	else if (test == 9)
		check(0202);
	return (0);
}
