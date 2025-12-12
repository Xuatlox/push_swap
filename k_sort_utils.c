/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:14:35 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/12 16:30:52 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **from, t_list **to, const char is_b, char **res)
{
	t_list	*tmp;

	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
	if (is_b)
		stradd(res, "pb\n");
	else
		stradd(res, "pa\n");
}

void	reverse_rotate(t_list **lst, char **res)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	stradd(res, "rrb\n");
}

void	rotate(t_list **lst, const char is_b, char **res)
{
	t_list	*tmp;

	if (!(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lstlast(tmp)->next = *lst;
	*lst = tmp;
	if (is_b)
		stradd(res, "rb\n");
	else
		stradd(res, "ra\n");
}
