/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:32:02 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/05 17:49:37 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst;

	if (argc < 2)
		return (0);
	parse(argv + 1, &lst);
	//sort(lst);
	while (lst)
	{
		printf("%d", lst->content);
		lst = lst->next;
	}
	return (0);
}
