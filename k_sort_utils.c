/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:14:35 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/10 17:36:06 by ansimonn         ###   ########.fr       */
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
		++add;
	}
	str[i] = 0;
	free(*base);
	*base = str;
}

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
	*lst = tmp;
	tmp->next = NULL;
	stradd(res, "rrb\n");
}

void	rotate(t_list **lst, const char is_b, char **res)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lstlast(tmp)->next = *lst;
	*lst = tmp;
	if (is_b)
		stradd(res, "rb\n");
	else
		stradd(res, "ra\n");
}
