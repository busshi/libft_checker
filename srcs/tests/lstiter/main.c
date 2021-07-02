#include "../../../../libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_size(void *content)
{
	size_t	size;

	size = ft_strlen((char *)content);
	printf("%ld\n", size);
}

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

void	print_list(t_list *list)
{
        while (list)
        {
                printf("%s -> ", (char *)list->content);
                list = list->next;
        }
        printf("NuLl\n");
}


void    check(void *one, void *two, void *three, void *four)
{
        t_list  *list;
        t_list  *added_1;
        t_list  *added_2;
	t_list	*added_3;

        list = ft_lstnew(four);
        added_3 = ft_lstnew(three);
        ft_lstadd_front(&list, added_3);
	added_2 = ft_lstnew(two);
	ft_lstadd_front(&list, added_2);
	added_1 = ft_lstnew(one);
	ft_lstadd_front(&list, added_1);
	print_list(list);
	ft_lstiter(list, &ft_size);
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check("1", "2", "3", "4");
	else if (test == 2)
		check("qslmkdfjqld", "", " ", "°98UPOMIjmlkj)ç_uoi)");
	else if (test == 3)
		check("", "", "", "");
	else if (test == 4)
		check("abcdefghijklmnopqrstuwxyz", "pihjlkhvhkgvpoupoacqsd3165498=)àçé)à&éç_)ç_qsdfqsd!:;,!:;,", "                                                   ", "\t        \n\r\t\v");
	return (0);
}
