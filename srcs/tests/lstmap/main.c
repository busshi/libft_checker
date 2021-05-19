#include "../../../../libft/libft.h"
#include <stdio.h>

t_list  *ft_lstnew(void *content)
{
        t_list  *list;

        if (!(list = (t_list *)malloc(sizeof(t_list))))
                return (NULL);
        list->content = content;
        list->next = NULL;
        return (list);
}

void	*ft_trans(void *content)
{
	t_list	*new;

	new = content;
	return (new);
}

void	ft_del(void *content)
{
	char	*str;

	str = (char *)content;
	printf("to_be_free : %s\n", str);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*be_free;

	while (*lst)
	{
		be_free = *lst;
		(*del)(be_free->content);
		*lst = (*lst)->next;
		free(be_free);
	}
	*lst = NULL;
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;
	
	if (alst && *alst)
	{
		temp = *alst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*alst = new;
}


void	print_list(t_list *list)
{
        while (list)
        {
                printf("%s -> ", (char *)list->content);
                list = list->next;
        }
        printf("NuLl\n");
}

void	check(void)
{
        t_list  *first;
        t_list  *second;
	t_list	*third;
	t_list	*fourth;
	t_list	*new;

        first = ft_lstnew("a");
        second = ft_lstnew("bb");
	third = ft_lstnew("ccc");
	fourth = ft_lstnew("dddd");
        ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, third);
	ft_lstadd_back(&first, fourth);
	print_list(first);
	new = ft_lstmap(first, &ft_trans, &ft_del);
	print_list(new);
	new = ft_lstmap(second, &ft_trans, &ft_del);
	print_list(new);
	new = ft_lstmap(third, &ft_trans, &ft_del);
	print_list(new);
	new = ft_lstmap(fourth, &ft_trans, &ft_del);
	print_list(new);
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check();
	return (0);
}
