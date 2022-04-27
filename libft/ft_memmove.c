/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:10:50 by adesmet           #+#    #+#             */
/*   Updated: 2021/02/06 11:53:44 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	i = -1;
	if (ptr < ptr2)
	{
		while (++i < len)
			ptr[i] = ptr2[i];
	}
	if (ptr > ptr2)
	{
		while (len--)
			ptr[len] = ptr2[len];
	}
	return (dest);
}
