#include "../../../../libft/libft.h"
#include <stdio.h>
#include <string.h>

void	check(char *dest, char *src, int size)
{
	printf("%ld\n%s\n", ft_strlcat(dest, src, size), dest);
	free(dest);
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;
	char	*dest;

	alarm(3);
	test = atoi(av[1]);
	if (!(dest = (char *)malloc(sizeof(char) * 30)))
		return (0);
	memset(dest, '\0', 30);
	memset(dest, '@', 10);
	if (test == 1)
		check(dest, "abcdefghijklmnopqrstuvwxyz", 100);
	else if (test == 2)
		check(dest, "Z", 12);
	else if (test == 3)
		check(dest, "Z", 5);
	else if (test == 4)
		check(dest, "0123456789", 20);
	else if (test == 5)
		check(dest, "abcd\refgh\nijklmnop", 18);
	else if (test == 6)
		check(dest, "abcd\refgh\nijklmnop", 30);
	else if (test == 7)
		check(dest, "\t0123456789", 20);
	return (0);
}
