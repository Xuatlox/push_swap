/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:26:53 by ansimonn          #+#    #+#             */
/*   Updated: 2026/01/05 11:11:38 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sqrt(long nbr)
{
	double	i;

	i = 0;
	while (i * i < nbr)
		++i;
	return (i);
}

void	fill_b(t_list **a, t_list **b)
{
	int		i;
	long	size;
	int		delta;

	size = ft_lstsize(*a);
	*b = NULL;
	i = 0;
	while (*a)
	{
		delta = sqrt(size * 3);
		if ((*a)->content <= i + delta)
		{
			push(a, b, 1);
			size--;
			if (*b && (*b)->content <= i)
				rotate(b, 1);
			i++;
		}
		else
			rotate(a, 0);
	}
}

static int	find_max(const t_list *lst)
{
	int		max;
	int		i;
	int		max_val;

	max = 0;
	i = 0;
	max_val = 0;
	while (lst)
	{
		if (lst->content > max_val)
		{
			max = i;
			max_val = lst->content;
		}
		++i;
		lst = lst->next;
	}
	return (max);
}

void	refill_a(t_list **a, t_list **b)
{
	int		i;
	int		size;

	size = ft_lstsize(*b);
	while (*b)
	{
		i = find_max(*b);
		if (i <= size / 2)
			while (i--)
				rotate(b, 1);
		else
			while (i++ < size)
				reverse_rotate(b, 1);
		--size;
		push(b, a, 0);
	}
}
