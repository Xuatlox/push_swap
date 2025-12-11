/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:02:20 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/11 18:33:21 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
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
	sort(&lst);
	return (0);
}
