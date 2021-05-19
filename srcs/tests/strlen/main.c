#include "../../../../libft/libft.h"
#include <stdio.h>
#include <string.h>


void	check(char *str)
{
	printf("%ld", ft_strlen(str));
}


int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("ùqslfkjqsfdqdsùmqokgùqsmlfdkqs");
	else if (test == 2)
		check("");
	else if (test == 3)
		check("\0");
	else if (test == 4)
		check("fqmdlfidj\t\nfqefdfq123");
	else if (test == 5)
		check("0");
	else if (test == 6)
		check("  \f\t   ");
	return (0);
}

