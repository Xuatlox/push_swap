/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:59 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/12 14:47:27 by ansimonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	nb_digits(const char *str)
{
	int		i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	return (i);
}

static char	add_digits(char **digits, long *conv)
{
	while (**digits == '0')
		++(*digits);
	if (nb_digits(*digits) > 10)
		return (0);
	while (**digits >= '0' && **digits <= '9')
	{
		*conv = *conv * 10 + **digits - '0';
		++(*digits);
	}
	if (!(**digits == ' ' || !**digits))
		return (0);
	while (**digits == ' ')
		++(*digits);
	return (1);
}

char	ft_atoi(char **nptr, int *res)
{
	int		sign;
	long	conv;

	sign = 1;
	conv = 0;
	while (**nptr == ' ')
		++(*nptr);
	if (**nptr == '-')
		sign = -1;
	if (**nptr == '+' || **nptr == '-')
	{
		if (*(*nptr + 1) < '0' || *(*nptr + 1) > '9')
			return (0);
		++(*nptr);
	}
	if (**nptr && add_digits(nptr, &conv))
	{
		if (conv * sign > 2147483647 || conv * sign < -2147483648)
			return (0);
		*res = sign * conv;
		return (1);
	}
	return (0);
}
