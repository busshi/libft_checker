#include "../../../../libft.h"
#include <stdio.h>


void	check(char *str)
{
	printf("%d", ft_atoi(str));
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("qùpogfqd123,64");
	else if (test == 2)
		check("0");
	else if (test == 3)
		check("321346835");
	else if (test == 4)
		check("-1");
	else if (test == 5)
		check("1");
	else if (test == 6)
		check("++6453135");
	else if (test == 7)
		check("-+351651");
	else if (test == 8)
		check("-+");
	else if (test == 9)
		check("\n\t\r5");
	else if (test == 10)
		check("\v654321");
	else if (test == 11)
		check("\t 654321.213");
	else if (test == 12)
		check("qdsfqldmjkg321654");
	else if (test == 13)
		check("9999999999999999999999999999999999999");
	else if (test == 14)
		check("2147483647");
	else if (test == 15)
		check ("-2147483648");
	else if (test == 16)
		check("+987");
	else if (test == 17)
		check("+66+3");
	else if (test == 18)
		check("-12-3");
	else if (test == 19)
		check("0101");
	else if (test == 20)
		check("-9999999999999999999999999999999999999999999999999999999999999");
	return (0);
}

