/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:05:47 by adesmet           #+#    #+#             */
/*   Updated: 2022/04/27 11:43:46 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void child_process(char** argv, char** envp, int* fd, int *hasCrashed)
{
	int filein;

	*hasCrashed = 0;
	filein = open(argv[1], O_RDONLY, 0777);
	if(filein == -1 || dup2(filein, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
		error();
	close(fd[0]);
	exe(argv[2],envp);
}

void parent_process(char** argv, char** envp, int* fd, int *hasCrashed)
{
	int fileout;
	int status;

	waitpid(-1, &status, 0);
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
	int		hasCrashed;

    if(argc == 5)
    {
        if(pipe(fd) == -1)
            error();
        pid = fork();
        if(pid == -1)
            error();
		if(!pid)
			child_process(argv,envp,fd, &hasCrashed);
		else
			parent_process(argv,envp,fd, &hasCrashed);
        
    }
    else
        ft_putstr_fd("Please enter 4 arguments exactly when calling thie program", 2);
	return(0);
}