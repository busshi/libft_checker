#include "../../../../libft/libft.h"

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		ft_putnbr_fd(1234567890, 1);
	else if (test == 2)
		ft_putnbr_fd(-1, 1);
	else if (test == 3)
		ft_putnbr_fd(1, 1);
	else if (test == 4)
		ft_putnbr_fd(1234567890, 2);
	else if (test == 5)
		ft_putnbr_fd(-2147483648, 1);
	else if (test == 6)
		ft_putnbr_fd(2147483647, 1);
	else if (test == 7)
		ft_putnbr_fd(0101, 1);
	else if (test == 8)
		ft_putnbr_fd(0202, 1);
	return (0);
}

