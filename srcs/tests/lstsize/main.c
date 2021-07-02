#include "../../../../libft.h"
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
	int	size;

        list = ft_lstnew(content);
	size = ft_lstsize(list);
	printf("%d\n", size);
	print_list(list);
}

void    check2(void *content, void *to_add)
{
        t_list  *list;
        t_list  *added;
        int     size;

        list = ft_lstnew(content);
        added = ft_lstnew(to_add);
        ft_lstadd_back(&list, added);
        size = ft_lstsize(list);
        printf("%d\n", size);
        print_list(list);
}

void    check3(void *content, void *to_add_front, void *to_add_back)
{
        t_list  *list;
        t_list  *front_added;
        t_list  *back_added;
        int     size;

        list = ft_lstnew(content);
        front_added = ft_lstnew(to_add_front);
        ft_lstadd_front(&list, front_added);
        back_added = ft_lstnew(to_add_back);
        ft_lstadd_back(&list, back_added);
        size = ft_lstsize(list);
        printf("%d\n", size);
        print_list(list);
}

void    check4(void *one, void *two, void *three, void *four)
{
        t_list  *list;
        t_list  *added_2;
        t_list  *added_3;
	t_list	*added_4;
        int     size;

        list = ft_lstnew(one);
        added_2 = ft_lstnew(two);
        ft_lstadd_back(&list, added_2);
	added_3 = ft_lstnew(three);
	ft_lstadd_back(&list, added_3);
	added_4 = ft_lstnew(four);
	ft_lstadd_back(&list, added_4);
        size = ft_lstsize(list);
        printf("%d\n", size);
	print_list(list);
}

int	main(int ac, char **av)
{
	(void)ac;
	int	test;

	alarm(3);
	test = atoi(av[1]);
	if (test == 1)
		check1("list");
	else if (test == 2)
		check2("first element", "second element");
	else if (test == 3)
		check3("list", "front_added", "back_added");
	else if (test == 4)
		check4("1", "2", "3", "4");
	else if (test == 5)
		check3(NULL, NULL, NULL);
	else if (test == 6)
		check4(NULL, NULL, NULL, NULL);
	else if (test == 7)
		printf("%d\n", ft_lstsize(NULL));
	return (0);
}
