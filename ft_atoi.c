/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansimonn <ansimonn@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:43:59 by ansimonn          #+#    #+#             */
/*   Updated: 2025/12/11 18:22:22 by ansimonn         ###   ########.fr       */
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

static char	add_digits(char **digits, long *res)
{
	if (nb_digits(*digits) > 10)
		return (0);
	while (**digits >= '0' && **digits <= '9')
	{
		*res = *res * 10 + **digits - '0';
		++(*digits);
	}
	if (**digits == ' ' || !**digits)
		return (1);
	return (0);
}

char	ft_atoi(char **nptr, long *res)
{
	int		sign;

	sign = 1;
	*res = 0;
	while ((**nptr >= 9 && **nptr <= 13) || **nptr == ' ')
		++(*nptr);
	if (**nptr == '-')
		sign = -1;
	if (**nptr == '+' || **nptr == '-')
		++(*nptr);
	while (**nptr == '0')
		++(*nptr);
	if (**nptr && add_digits(nptr, res))
	{
		if (sign * (*res) > 2147483647 || sign * (*res) < -2147483648)
			return (0);
		*res = sign * (*res);
		return (1);
	}
	return (0);
}
