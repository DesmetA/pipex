/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notLibft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:18:22 by adesmet           #+#    #+#             */
/*   Updated: 2022/04/27 12:49:38 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	ft_del_count(char *s, char c)
{
	size_t	count;
	size_t	i;

	i = -1;
	count = 0;
	if (!s)
		return (0);
	while (s[++i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
		if (!s[i])
			break ;
	}
	return (count);
}

size_t	ft_word_size(char *s, char c, int count)
{
	int	i;

	i = count;
	while (s[i] != c && s[i])
		i++;
	return (i - count);
}

void	ft_free(char **ans, size_t i)
{
	while (i--)
		free(ans[i]);
	free(ans);
}

char	**ft_split(char *s, char c)
{
	int		i;
	size_t	k;
	size_t	size;
	char	**ans;

	i = 0;
	k = -1;
	size = ft_del_count(s, c) + 1;
	ans = (char **)ft_calloc(sizeof(char *), size);
	if (!s || !ans)
		return (NULL);
	while (++k < size - 1)
	{
		while (s[i] == c && s[i])
			i++;
		ans[k] = ft_substr(s, i, ft_word_size(s, c, i));
		if (!ans)
		{
			//ft_free(ans, k);
			return (NULL);
		}
		i += ft_word_size(s, c, i);
	}
	ans[k] = NULL;
	return (ans);
}

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
	return (ptr);
}
