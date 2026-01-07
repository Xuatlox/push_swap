/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:26:06 by ansimonn          #+#    #+#             */
/*   Updated: 2026/01/07 12:03:53 by ansimonn         ###   ########.fr       */
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

char	is_sorted(t_list *lst)
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
	t_list	*b;

	if (is_sorted(*a))
	{
		ft_lstclear(a);
		return ;
	}
	simplify(a);
	fill_b(a, &b);
	refill_a(a, &b);
	ft_lstclear(a);
	ft_lstclear(&b);
}

void	small_sort(t_list **a)
{
	t_list	*b;

	b = NULL;
	if (ft_lstsize(*a) == 2 && (*a)->content > (*a)->next->content)
		rotate(a, IS_A_STACK);
	if (is_sorted(*a))
	{
		ft_lstclear(a);
		return ;
	}
	simplify(a);
	while ((*a)->next->next->next)
		push(a, &b, IS_B_STACK);
	simple_sort(a, &b, 3);
	ft_lstclear(a);
	ft_lstclear(&b);
}
