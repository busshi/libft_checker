#include "../../../../libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char	to_lower(unsigned int i, char c)
{
	(void)i;
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

char	to_upper(unsigned int i, char c)
{
        (void)i;
        if (c >= 'a' && c <= 'z')
                c = c - 32;
        return (c);
}

char	to_at(unsigned int i, char c)
{
        (void)i;
        if (isspace(c))
                c = '@';
        return (c);
}

char    to_star(unsigned int i, char c)
{
        (void)i;
        if (isspace(c))
                c = '*';
        return (c);
}

char    to_dot(unsigned int i, char c)
{
        (void)i;
        if (isspace(c))
                c = '.';
        return (c);
}

void	check(char const *s, char (*f)(unsigned int, char))
{
	printf("%s", ft_strmapi(s, f));
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("aBcDeFgHiJkLmNoPqRsTuVwXyZ aBc 123456789", &to_lower);
	else if (test == 2)
		check("aBcDeFgHiJkLmNoPqRsTuVwXyZ aBc 123456789", &to_upper);
	else if (test == 3)
		check(")àç_&è_-é-mlj987", &to_upper);
	else if (test == 4)
		check("\n\r\t", &to_at);
	else if (test == 5)
		check("amlks\tmlksj\nqsmlks\rlmkjs", &to_at);
	else if (test == 6)
		check(" ", &to_at);
	else if (test == 7)
		check("\t01234\n56789\t0", &to_dot);
	else if (test == 8)
		check("\t01234\n56789\t0", &to_star);
	return (0);
}
