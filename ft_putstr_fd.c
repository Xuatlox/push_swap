/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:40:45 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/04 15:29:27 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd, int *ret)
{
	if (!s)
	{
		ft_putstr_fd("(null)", fd, ret);
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s, fd, ret);
		s++;
	}
}
