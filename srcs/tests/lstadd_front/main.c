#include "../../../../libft/libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	check(void *content, void *to_add)
{
	t_list	*list;
	t_list	*added;

	list = ft_lstnew(content);
	added = ft_lstnew(to_add);
	ft_lstadd_front(&list, added);
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
		check("list", "front_added");
	else if (test == 2)
		check("list", "");
	else if (test == 3)
		check("list", NULL);
	else if (test == 4)
		check(NULL, NULL);
	return (0);
}
