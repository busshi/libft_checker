#include "../../../../libft.h"
#include <stdio.h>
#include <string.h>


void	check(char *dest, char *src)
{
	printf("%s", ft_strcat(dest, src));
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
		check(dest, "abcdefghijklmnopqrstuvwxyz");
	else if (test == 2)
		check(dest, "Z");
	else if (test == 3)
		check(dest, "");
	else if (test == 4)
		check(dest, "0123456789");
	else if (test == 5)
		check(dest, "abcd\refgh\nijklmnop");
	else if (test == 6)
		check(dest, "abcd\refgh\nijklmnop");
	else if (test == 7)
		check(dest, "\t0123456789");
	return (0);
}
