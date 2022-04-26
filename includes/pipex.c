/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:05:47 by adesmet           #+#    #+#             */
/*   Updated: 2022/04/26 11:24:49 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char** argv)
{
    int     file_des[2]
    pid_t   pid;

    if(argc == 5)
    {
        if(pipe(file_des) == -1)
            error();
        pid = fork();
        if(pid = -1)
            error();
        
    }
    else
        error();
}

void error(void)
{
    perror("Fatal error");
    exit(EXIT_FAILURE);
}