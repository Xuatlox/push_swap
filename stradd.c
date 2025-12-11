/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stradd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:56:54 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/11 14:57:25 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stradd(char **base, char *add)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc((ft_strlen(*base) + ft_strlen(add) + 1) * sizeof(char));
	if (!str)
		return ;
	while ((*base)[i])
	{
		str[i] = (*base)[i];
		++i;
	}
	while (*add)
	{
		str[i] = *add;
		++add;
		++i;
	}
	str[i] = 0;
	free(*base);
	*base = str;
}
