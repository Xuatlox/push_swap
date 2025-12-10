/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:26:06 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/10 16:29:07 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simplify(t_list **lst)
{
	t_list	*i;
	t_list	*j;
	t_list	*tmp;
	t_list	*res;

	res = ft_lstnew(0);
	tmp = res;
	i = *lst;
	while (i)
	{
		j = *lst;
		while (j)
		{
			if (j->content < i->content)
				++(tmp->content);
			j = j->next;
		}
		i = i->next;
		if (i)
			ft_lstadd_back(&tmp, ft_lstnew(0));
		tmp = tmp->next;
	}
	ft_lstclear(lst);
	*lst = res;
}

static char	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort(t_list **a)
{
	char	*res;
	t_list	*b;

	if (is_sorted(*a))
		return ;
	simplify(a);
	fill_b(a, &b, &res);
	refill_a(a, &b, &res);
	ft_lstclear(a);
	ft_lstclear(&b);
	write(1, res, ft_strlen(res));
	free(res);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	t_list	*lst = NULL;
	int		i;

	if (ac < 2)
		return (0);
	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(&lst, ft_lstnew(atoi(av[i])));
		++i;
	}
	sort(&lst);
}
