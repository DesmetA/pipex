/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:05:47 by adesmet           #+#    #+#             */
/*   Updated: 2022/04/27 16:28:55 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	exe(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	fileout;
	int	status;

	fileout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fileout, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	exe(argv[3], envp);
}

void	exe(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = check_path(cmd[0], envp);
	if (!path)
	{
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd(": Command not found\n", 2);
		free2d(cmd);
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror(cmd[0]);
		exit(127);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (!pid)
			child_process(argv, envp, fd);
		else
			parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("Please enter 4 arguments exactly", 2);
		error();
	}
}
