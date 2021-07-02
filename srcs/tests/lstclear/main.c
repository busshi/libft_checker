#include "../../../../libft.h"
#include <stdio.h>

size_t	done;

void	ft_del(void *content)
{
	char	*str;

	str = (char *)content;
	printf("%s\n", str);
	done++;
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst)
		new->next = *alst;;
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

void	check()
{
        t_list  *list;
        t_list  *second;
	t_list	*third;
	t_list	*first;

        list = ft_lstnew("dddd");
        second = ft_lstnew("bb");
	third = ft_lstnew("ccc");
	first = ft_lstnew("a");
        ft_lstadd_front(&list, third);
	ft_lstadd_front(&list, second);
	ft_lstadd_front(&list, first);
	print_list(list);
	ft_lstclear(&first, &ft_del);
	printf("Free done : %ld\n", done);
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	done = 0;
	test = atoi(av[1]);
	if (test == 1)
		check();
	return (0);
}
