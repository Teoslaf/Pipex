/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:16:32 by ttaneski          #+#    #+#             */
/*   Updated: 2023/03/15 17:12:14 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* void    pipex(int f1, int f2)
{
    int fd[2];
    pid_t pid;
    pipe(fd);
        if (pipe(fd) == -1)
    {
        printf("error opening the pipe");
        return (1);
    }
    if(pid < 0)
        return (prerror("Fork: "));
    if(pid == 0)
    {

    }
} */

int main(void)
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        printf("error opening the pipe");
        return (1);
    }
    int id = fork();
    if (id == 0)
    {
        int file = open("file1.txt", O_WRONLY | O_CREAT, 0777);
        if (file == -1)
            return (2);
         
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        char cmd[] = "/usr/bin/ls";
        char *argv[] = {"ls", "-l", NULL};
        char *envm[] = {NULL};
        if (execve(cmd, argv, envm) == -1)
            perror("error");
        printf("ayo");
    }
    int pid2 = fork();
    if (pid2 < 0)
        return (2);
    if (pid2 == 0)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        char cmd[] = "/usr/bin/wc";
        char *argv[] = {"wc", "-w", NULL};
        char *envm[] = {NULL};
        if (execve(cmd, argv, envm) == -1)
            perror("error");
        printf("ayo");
    }
    close(fd[0]);
    close(fd[1]);

    waitpid(id, NULL, 0);
    waitpid(pid2, NULL, 0);

    return (0);
}