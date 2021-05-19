#include "../../../../libft/libft.h"
#include <stdio.h>

void	ft_del(void *content)
{
	char	*str;

	str = (char *)content;
	printf("to_be_free : %s\n", str);
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

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
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

        first = ft_lstnew("1");
        second = ft_lstnew("2");
	third = ft_lstnew("3");
	fourth = ft_lstnew("4");
        ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, third);
	ft_lstadd_back(&first, fourth);
	print_list(first);
	ft_lstdelone(first, &ft_del);
	ft_lstdelone(third, &ft_del);
	ft_lstdelone(fourth, &ft_del);
	ft_lstdelone(second, &ft_del);
	printf("4 Free Done\n");
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
