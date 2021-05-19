#include "../../../../libft/libft.h"
#include <stdio.h>

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


void    check1(void *content)
{
        t_list  *list;
	t_list	*last;

        list = ft_lstnew(content);
	last = ft_lstlast(list);
	printf("%s\n", (char *)last->content);
}

void    check2(void *one, void *two)
{
        t_list  *list;
        t_list  *last;
	t_list	*second;

        list = ft_lstnew(one);
	second = ft_lstnew(two);
	ft_lstadd_back(&list, second);
        last = ft_lstlast(list);
        printf("%s\n", (char *)last->content);
}

void    check3(void *one, void *two, void *three)
{
        t_list  *list;
        t_list  *last;
        t_list  *second;
	t_list	*third;

        list = ft_lstnew(one);
        second = ft_lstnew(two);
	third = ft_lstnew(three);
        ft_lstadd_back(&list, second);
	ft_lstadd_back(&list, third);
        last = ft_lstlast(list);
        printf("%s\n", (char *)last->content);
}

void    check4(void *one, void *two, void *three, void *four)
{
        t_list  *list;
        t_list  *last;
        t_list  *second;
	t_list	*third;
	t_list	*fourth;

        list = ft_lstnew(one);
        second = ft_lstnew(two);
	third = ft_lstnew(three);
	fourth = ft_lstnew(four);
        ft_lstadd_back(&list, second);
	ft_lstadd_back(&list, third);
	ft_lstadd_back(&list, fourth);
        last = ft_lstlast(list);
        printf("%s\n", (char *)last->content);
}


int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check1("last");
	else if (test == 2)
		check2("first element", "lastest element");
	else if (test == 3)
		check3("first", "second", "third");
	else if (test == 4)
		check4("1", "2", "3", "4");
	else if (test == 5)
		check3("first", NULL, "second");
	else if (test == 6)
		check4(NULL, NULL, NULL, "fourth");
	return (0);
}
