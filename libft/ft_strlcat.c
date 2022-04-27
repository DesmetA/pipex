/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:53:01 by adesmet           #+#    #+#             */
/*   Updated: 2021/02/02 01:31:18 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ans;

	if (ft_strlen(dst) < size)
		ans = ft_strlen(dst) + ft_strlen(src);
	else
		ans = size + ft_strlen(src);
	while (*(dst++) && size)
		size--;
	dst--;
	i = 0;
	while (src[i] && i < size - 1 && size)
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = '\0';
	return (ans);
}
