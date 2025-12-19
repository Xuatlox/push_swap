/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:02:20 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/19 11:10:44 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*lst;

	if (ac < 2)
		return (0);
	lst = NULL;
	if (!parse(av + 1, &lst))
	{
		write(2, "Error\n", 6);
		ft_lstclear(&lst);
		return (0);
	}
	if (ft_lstsize(lst) < 6)
		small_sort(&lst);
	else
		sort(&lst);
	return (0);
}
