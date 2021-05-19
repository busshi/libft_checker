#include "../../../../libft/libft.h"
#include <stdio.h>

void	check(char const *s, char c)
{
	int	i;
	char	**res;

	i = 0;
	res = ft_split(s, c);
	while (res[i])
	{
		printf("%s\n", res[i]);
	//	free(res[i]);
		i++;
	}
	//free(res);
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("aBcDeFgHiJkLmNoPqRsTuVwXyZ aBc 123456789", ' ');
	else if (test == 2)
		check("aBcDeFgHiJkLmNoPqRsTuVwXyZ aBc 123456789", 'a');
	else if (test == 3)
		check(")àç_&è_-é-mlj987", '-');
	else if (test == 4)
		check("a\tb\nc\rd\te\nf", '\t');
	else if (test == 5)
		check("amlks\nmlksj\nqsmlks\nlmkjs", '\n');
	else if (test == 6)
		check("                       ", ' ');
	else if (test == 7)
		check("\t01234\n56789\t0", 'A');
	else if (test == 8)
		check("\t01234\n56789\t0", '0');
	return (0);
}
