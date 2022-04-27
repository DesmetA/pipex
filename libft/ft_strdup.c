/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:07:52 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/08 12:56:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	i;

	i = -1;
	s2 = (char *)(ft_calloc(sizeof(char), ft_strlen(s) + 1));
	if (!s2)
		return (NULL);
	while (s[++i])
		s2[i] = s[i];
	return (s2);
}
