/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:36:17 by user42            #+#    #+#             */
/*   Updated: 2022/04/26 17:28:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void error(void)
{
    perror("Fatal error");
    exit(EXIT_FAILURE);
}

void free2d(char **toB3)
{
	int i;

	i = -1;
	while(toB3[++i])
		free(toB3[i]);
	free(toB3);
}

char *find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char *check_path(char *cmd, char **envp)
{
	char 	**paths;
	char	*path;
	char	*tmp;
	int		i;

	paths = ft_split(find_path(envp),':');
	i = 0;
	while(paths[i])
	{
		tmp = ft_strjoin(paths[i],"/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if(!access(path, F_OK))
			return (path);
		free(path);
		i++;
	}
	free2d(paths);
	return(NULL);
}
