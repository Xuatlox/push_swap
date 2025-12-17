/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:04:43 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/12 13:48:56 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	is_double(const int nb, t_list **list)
{
	t_list	*tmp;

	if (!list || !*list)
		return (0);
	tmp = *list;
	while (tmp)
	{
		if (nb == tmp->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char	parse(char **argv, t_list **a)
{
	int		conv;
	char	tmp;

	while (*argv)
	{
		if (!**argv)
			return (0);
		while (**argv)
		{
			conv = 0;
			tmp = ft_atoi(argv, &conv);
			if (!tmp || is_double(conv, a))
				return (0);
			ft_lstadd_back(a, ft_lstnew(conv));
		}
		++argv;
	}
	return (1);
}
