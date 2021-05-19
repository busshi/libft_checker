#include "../../../../libft/libft.h"
#include <stdio.h>
#include <string.h>

void	check(char *dest, const char *src, int size)
{
	printf("%s\n", ft_strncat(dest, src, size));
	free(dest);
}

int		main(int ac, char **av)
{
	(void)ac;
	char	*dest;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (!(dest = (char *)malloc(sizeof(*dest) * 60)))
		return (0);
	memset(dest, '\0', 60);
	memset(dest, '@', 30);
	if (test == 1)
		check(dest, "abcdefghijklmnopqrstuvwxyz", 26);
	else if (test == 2)
		check(dest, "", 26);
	else if (test == 3)
		check(dest, "0123456789", 5);
	else if (test == 4)
		check(dest, "0123456789", 20);
	else if (test == 5)
		check(dest, "abcd\refgh\nijklmnop", 18);
	else if (test == 6)
		check(dest, "abcd\refgh\nijklmnop", 20);
	else if (test == 7)
		check(dest, "0123456789", 0);
	return (0);
}
