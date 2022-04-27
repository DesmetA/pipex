/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:33:37 by adesmet           #+#    #+#             */
/*   Updated: 2022/04/27 10:53:11 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static	void	ft_free(char **ans, size_t i)
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
			ft_free(ans, k);
			return (NULL);
		}
		i += ft_word_size(s, c, i);
	}
	ans[k] = NULL;
	return (ans);
}
