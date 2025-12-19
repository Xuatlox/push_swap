/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:14:35 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/19 17:30:27 by ansimonn         ###   ########.fr       */
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

static void	swap(t_list **lst, const char is_b, char **res)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = *lst;
	*lst = tmp;
	if (is_b)
		stradd(res, "sb\n");
	else
		stradd(res, "sa\n");
}

void	reverse_rotate(t_list **lst, const char is_b, char **res)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	if (is_b)
		stradd(res, "rrb\n");
	else
		stradd(res, "rra\n");
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

void	iterative_sort(t_list **a, t_list **b, char **res)
{
	if (!((*a)->content > (*a)->next->content
			&& (*a)->next->content < (*a)->next->next->content
			&& (*a)->content > (*a)->next->next->content)
		&& !((*a)->content < (*a)->next->content
			&& (*a)->next->content > (*a)->next->next->content
			&& (*a)->content > (*a)->next->next->content))
		swap(a, 0, res);
	if ((*a)->content > (*a)->next->content)
		rotate(a, 0, res);
	else if ((*a)->content > (*a)->next->next->content)
		reverse_rotate(a, 0, res);
}
