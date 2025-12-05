/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:02:20 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/05 14:28:21 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list	*lst;

	if (argc < 2)
		return (0);
	a = NULL;
	if (!parse(argv + 1, &lst))
	{
		write(2, "Error\n", 6);
		ft_lstclear(&lst);
		return (0);
	}
	sort(lst);
	ft_lstclear(&lst);
	return (0);
}
