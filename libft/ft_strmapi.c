/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 00:07:14 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/08 13:03:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ans;

	i = -1;
	if (!s || !f)
		return (NULL);
	ans = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!ans)
		return (NULL);
	while (s[++i])
	{
		ans[i] = f(i, s[i]);
	}
	ans[i] = 0;
	return (ans);
}
