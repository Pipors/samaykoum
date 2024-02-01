/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatbir <aatbir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:11:44 by omanar            #+#    #+#             */
/*   Updated: 2024/02/02 00:36:20 by aatbir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_loop(const char *str, int i, int is_neg)
{
	unsigned long long	res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		if (res > 9223372036854775807)
			return (0);
	}
	return (res * is_neg);
}

unsigned long long	ft_atoi(const char *str)
{
	int					i;
	int					is_neg;
	unsigned long long	p;

	is_neg = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	p = ft_loop(str, i, is_neg);
	return (p);
}
