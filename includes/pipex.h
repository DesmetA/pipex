/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:36:13 by user42            #+#    #+#             */
/*   Updated: 2022/04/26 17:24:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

void child_process(char** argv, char** envp, int* fd);
void parent_process(char** argv, char** envp, int* fd);
void exe(char* argv, char** envp);

void error(void);
void free2d(char **toB3);
char *find_path(char **envp);
char *check_path(char *cmd, char **envp);

#endif