/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 11:36:17 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/08 13:02:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_digit(int n)
{
	int	i;
	int	count;

	i = 0;
	if (n <= 0)
	{
		count = -n;
		i++;
	}
	else
		count = n;
	while (count > 0)
	{
		count = count / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		size;
	long	num;

	size = ft_count_digit(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ans = ft_calloc(sizeof(char), size + 1);
	if (!ans)
		return (NULL);
	if (n < 0)
	{
		ans[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		ans[0] = '0';
	while (num)
	{
		ans[--size] = (num % 10) + '0';
		num = num / 10;
	}
	return (ans);
}
