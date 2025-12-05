/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:59 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/05 10:41:30 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	add_digits(char **digits, int *res)
{
	while (**digits >= '0' && **digits <= '9')
	{
		*res = *res * 10 + **digits - '0';
		++(*digits);
	}
	if (**digits == ' ' || !**digits)
		return (1);
	return (0);
}

char	ft_atoi(char **nptr, int *res)
{
	int		sign;

	sign = 1;
	*res = 0;
	while ((**nptr >= 9 && **nptr <= 13) || **nptr == 32)
		++(*nptr);
	if (**nptr == '-')
		sign = -1;
	if (**nptr == '+' || **nptr == '-')
		++(*nptr);
	while (**nptr == '0')
		++(*nptr);
	if (add_digits(nptr, res))
	{
		*res = sign * (*res);
		return (1);
	}
	return (0);
}
