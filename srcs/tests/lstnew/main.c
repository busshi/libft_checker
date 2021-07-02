#include "../../../../libft.h"
#include <stdio.h>

void	check(void *content)
{
	t_list	*list;
	
	list = ft_lstnew(content);
	while (list)
	{
		printf("%s -> ", (char *)list->content);
		list = list->next;
	}
	printf("NuLl\n");
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("abcdefghijklmnopqrstuvwxyz abc");
	else if (test == 2)
		check("0123456789");
	else if (test == 3)
		check("");
	else if (test == 4)
		check(" ");
	else if (test == 5)
		check("abcd\refgh\nijklmnop");
	else if (test == 6)
		check("abcd\refgh\nijklmnop");
	else if (test == 7)
		check("\t01234\n56789\t0");
	else if (test == 8)
		check("\t01234\n56789\t0");
	else if (test == 9)
		check("abcdef");
	else if (test == 10)
		check("               \n\t ");
	return (0);
}
