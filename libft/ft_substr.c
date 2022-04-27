/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:35:24 by adesmet           #+#    #+#             */
/*   Updated: 2022/04/27 10:53:11 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	len2;

	len2 = len;
	if (!s)
		return (NULL);
	if (ft_strlen(s) - start + 1 < len)
		len2 = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
	{
		ptr = (char *)ft_calloc(sizeof(char), 1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	ptr = ft_calloc(sizeof(char), len2 + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < len2)
		ptr[i] = s[start + i];
	free(s);
	return (ptr);
}
