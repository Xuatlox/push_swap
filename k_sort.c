/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:26:53 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/09 16:43:07 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stradd(char **base, char *add)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc((ft_strlen(*base) + ft_strlen(add) + 1) * sizeof(char));
	if (!str)
		return ;
	while (**base)
	{
		str[i] = (*base)[i];
		++i;
	}
	while (*add)
	{
		str[i] = *add;
		++(*add);
	}
	str[i] = 0;
	free(*base);
	*base = str;
}

static void	push(t_list *from, t_list **to, const char is_b, char **res)
{
	t_list	*tmp;

	tmp = from->next;
	from->next = *to;
	*to = from;
	from = tmp;
	if (is_b)
		stradd(res, "pb\n");
	else
		stradd(res, "pa\n");
}

static void	rotate(t_list **lst, const char is_b, char **res)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lstlast(*lst)->next = *lst;
	*lst = tmp;
	if (is_b)
		stradd(res, "rb\n");
	else
		stradd(res, "ra\n");
}

void	fill_b(t_list **a, t_list **b, char **res)
{
	int	i;
	int delta;

	res = malloc(sizeof(char));
	if (!res)
		return ;
	b = NULL;
	delta = ft_lstsize(*a) / 20 + 7;
	i = 0;
	while (*a)
	{
		if ((*a)->content <= i + delta)
		{
			push((*a), b, 1, res);
			if ((*a)->content <= i)
				rotate(b, 1, res);
			i++;
		}
		else
			rotate(a, 0, res);
	}
}

char	*k_sort(t_list *a)
{
	t_list	*b;
	char	*res;

	fill_b(&a, &b, &res);
}
