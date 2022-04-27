/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:25:35 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/08 13:08:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long		ans;
	int						sign;

	sign = 1;
	ans = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ans = (ans * 10) + *str - '0';
		str++;
	}
	if (ans >= LLONG_MAX && sign == 1)
		return (-1);
	if (ans >= LLONG_MAX && sign == -1)
		return (0);
	return (sign * ans);
}
