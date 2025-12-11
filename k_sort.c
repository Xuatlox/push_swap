/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:26:53 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/11 16:04:25 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_b(t_list **a, t_list **b, char **res)
{
	int	i;
	int	size;
	int delta;

	*res = malloc(sizeof(char));
	if (!*res)
		return ;
	size = ft_lstsize(*a);
	**res = 0;
	*b = NULL;
	i = 0;
	while (*a)
	{
		delta = size / 20 + 7;
		if ((*a)->content <= i + delta)
		{
			push(a, b, 1, res);
			--size;
			if (*a && (*a)->content <= i)
				rotate(b, 1, res);
			i++;
		}
		else
			rotate(a, 0, res);
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

void	refill_a(t_list **a, t_list **b, char **res)
{
	int		i;
	int		size;

	size = ft_lstsize(*b);
	while (*b)
	{
		i = find_max(*b);
		if (i <= size / 2)
			while (i)
			{
				rotate(b, 1, res);
				--i;
			}
		else
			while (i < size)
			{
				reverse_rotate(b, res);
				++i;
			}
		--size;
		push(b, a, 0, res);
	}
}
