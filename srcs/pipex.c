/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:05:47 by adesmet           #+#    #+#             */
/*   Updated: 2022/04/26 18:39:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void child_process(char** argv, char** envp, int* fd)
{
	int filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if(filein == -1 || dup2(filein, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
		error();
	close(fd[0]);
	exe(argv[2],envp);
}

void parent_process(char** argv, char** envp, int* fd)
{
	int fileout;

	fileout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if(fileout == -1 || dup2(fileout, STDOUT_FILENO) == -1 || dup2(fd[0], STDIN_FILENO) == -1)
		error();
	close(fd[1]);
	exe(argv[3],envp);
}

void exe(char* argv, char** envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv,' ');
	path = check_path(cmd[0],envp);
	if(!path)
	{
		free2d(cmd);
		error();
	}
	if(execve(path,cmd, envp) == -1)
		error();
}

int main(int argc, char** argv, char** envp)
{
    int     fd[2];
    pid_t   pid;

    if(argc == 5)
    {
        if(pipe(fd) == -1)
            error();
        pid = fork();
        if(pid == -1)
            error();
		if(!pid)
			child_process(argv,envp,fd);
		else
			parent_process(argv,envp,fd);
        
    }
    else
        error();
	return(0);
}