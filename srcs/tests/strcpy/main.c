#include "../../../../libft/libft.h"
#include <stdio.h>
#include <string.h>

void	check(char *dest, const char *src)
{
	printf("%s", ft_strcpy(dest, src));
	free(dest);
}

int		main(int ac, char **av)
{
	(void)ac;
	char	*dest;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (!(dest = (char *)malloc(sizeof(*dest) * 27)))
		return (0);
	memset(dest, '\0', 27);
	memset(dest, '@', 26);
	if (test == 1)
		check(dest, "abcdefghijklmnopqrstuvwxyz");
	else if (test == 2)
		check(dest, "");
	else if (test == 3)
		check(dest, "0123456789");
	else if (test == 4)
		check(dest, "\n\t\v    \n");
	else if (test == 5)
		check(dest, "abcd\refgh\nijklmnop");
	else if (test == 6)
		check(dest, "abcd\refgh\nijklmnopqrstuvwxyz\n     ");
	return (0);
}
