/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:26:06 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/08 15:51:29 by ansimonn         ###   ########.fr       */
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

void	sort(t_list **a)
{
	t_list	*b;

	b = NULL;
	simplify(a);
}
