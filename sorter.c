/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:26:06 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/12 16:30:37 by ansimonn         ###   ########.fr       */
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

static void	display(char *res)
{
	while (*res)
	{
		write(1, res, 1);
		res++;
	}
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
	display(res);
	free(res);
}
