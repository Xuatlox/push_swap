/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:14:35 by ansimonn          #+#    #+#             */
/*   Updated: 2026/01/07 12:03:53 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **from, t_list **to, const char is_b)
{
	t_list	*tmp;

	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
	if (is_b)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}

void	swap(t_list **lst, const char is_b)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = *lst;
	*lst = tmp;
	if (is_b)
		write(1, "sb\n", 3);
	else
		write(1, "sa\n", 3);
}

void	reverse_rotate(t_list **lst, const char is_b)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	if (is_b)
		write(1, "rrb\n", 4);
	else
		write(1, "rra\n", 4);
}

void	rotate(t_list **lst, const char is_b)
{
	t_list	*tmp;

	if (!(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lstlast(tmp)->next = *lst;
	*lst = tmp;
	if (is_b)
		write(1, "rb\n", 3);
	else
		write(1, "ra\n", 3);
}

void	simple_sort(t_list **a, t_list **b, int size)
{
	if (!((*a)->content > (*a)->next->content
			&& (*a)->next->content < (*a)->next->next->content
			&& (*a)->content > (*a)->next->next->content)
		&& !((*a)->content < (*a)->next->content
			&& (*a)->next->content > (*a)->next->next->content
			&& (*a)->content > (*a)->next->next->content) && !is_sorted(*a))
		swap(a, IS_A_STACK);
	if ((*a)->content > (*a)->next->content)
		rotate(a, IS_A_STACK);
	else if ((*a)->content > (*a)->next->next->content)
		reverse_rotate(a, IS_A_STACK);
	if (!(*b))
		return ;
	if ((*b)->next && (*b)->content > (*b)->next->content)
		rotate(b, IS_B_STACK);
	while (*b)
	{
		while ((size != (*b)->content && (*a)->content < (*b)->content)
			|| ((*a)->content != 0 && size == (*b)->content))
			rotate(a, IS_A_STACK);
		push(b, a, IS_A_STACK);
		++size;
	}
	while ((*a)->content != 0)
		rotate(a, IS_A_STACK);
}
