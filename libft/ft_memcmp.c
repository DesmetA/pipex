/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:13:18 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/08 13:01:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dest1, const void *dest2, size_t len)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	size_t			i;

	ptr = (unsigned char *)dest1;
	ptr2 = (unsigned char *)dest2;
	i = -1;
	while (++i < len)
	{
		if (ptr[i] != ptr2[i])
			return (ptr[i] - ptr2[i]);
	}
	return (0);
}
