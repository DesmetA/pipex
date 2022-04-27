/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:36:13 by user42            #+#    #+#             */
/*   Updated: 2022/04/27 15:53:12 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);
void	exe(char *argv, char **envp);

void	error(void);
void	free2d(char **toB3);
char	*find_path(char **envp);
char	*check_path(char *cmd, char **envp);

size_t	ft_strlen(char *str);
size_t	ft_word_size(char *s, char c, int count);
size_t	ft_del_count(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	ft_free(char **ans, size_t i);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_bzero(void *dest, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strncmp(char *s1, char *s2, size_t len);

#endif