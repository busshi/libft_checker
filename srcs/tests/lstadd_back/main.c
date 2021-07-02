#include "../../../../libft.h"
#include <stdio.h>



void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
		new->next = *alst;
	*alst = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	check(void *content, void *to_add_front, void *to_add_back)
{
	t_list	*list;
	t_list	*front_added;
	t_list	*back_added;

	list = ft_lstnew(content);
	front_added = ft_lstnew(to_add_front);
	ft_lstadd_front(&list, front_added);
	back_added = ft_lstnew(to_add_back);
	ft_lstadd_back(&list, back_added);
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
		check("list", "front_added", "back_added");
	else if (test == 2)
		check("2", "1", "3");
	else if (test == 3)
		check("list", NULL, "back_added");
	else if (test == 4)
		check("list", "front_added", NULL);
	else if (test == 5)
		check("list", NULL, NULL);
	else if (test == 6)
		check(NULL, NULL, NULL);
	return (0);
}
