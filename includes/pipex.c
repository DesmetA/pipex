/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:05:47 by adesmet           #+#    #+#             */
/*   Updated: 2022/04/26 15:28:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char** argv, char** envp)
{
    int     fd[2]
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
}

void error(void)
{
    perror("Fatal error");
    exit(EXIT_FAILURE);
}

void child_process(char** argv, char** envp, int* fd)
{
	int filein;

	filein = open(argv[1], O_RDONLY);
	if(filein == -1 || dup2(filein, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
		error();
	close(fd[0]);
	exe(argv[2],envp);
}

void parent_process(char** argv, char** envp, int* fd)
{
	int fileout;

	waitpid(-1, &status, 0);
	fileout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC);
	if(fileout == -1 || dup2(fileout, STDOUT_FILENO) == -1 || dup2(fd[0], STDIN_FILENO) == -1)
		error();
	close(fd[1]);
	exe(argv[3],envp);
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

	paths = ft_split(find_path(envp),':'));
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
	return(0);
}

void free2d(char **toB3)
{
	int i;

	i = -1;
	while(toB3[++i])
		free(toB3[i]);
	free toB3;
}

void exe(char* argv, char** envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv,' ');
	path = check_path(cmd[0]),envp);
	if(!path)
	{
		free2d(cmd);
		error();
	}
	if(execve(path,cmd, envp) == -1)
		error();
}