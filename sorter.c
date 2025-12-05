/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:26:06 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/05 17:31:21 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simplify(t_list **lst)
{
	t_list	*i;
	int		tmp;

	i = *lst;
	while (i)
	{
		tmp = i->content;
		i->content = 0;
		*lst = i->next;
		while (*lst)
		{
			if ((*lst)->content < tmp)
				++(i->content);
			*lst = (*lst)->next;
		}
		i = i->next;
	}
}

void	sort(t_list *a)
{
	t_list	*b;

	b = NULL;
	simplify(&a);
}
