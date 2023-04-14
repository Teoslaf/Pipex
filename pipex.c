/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:16:32 by ttaneski          #+#    #+#             */
/*   Updated: 2023/03/31 19:16:04 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	printerror(char *str)
{
	perror(str);
	exit (1);
}

static char	*find_path(char **envp, char *cmd)
{
	char	**paths;
	char	*cmd_path;
	char	*sub;

	cmd = *ft_split(cmd, ' ');
	while (*envp && !ft_strnstr(*envp, "PATH=", 5))
		envp++;
	sub = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
	paths = ft_split(sub, ':');
	free(sub);
	sub = ft_strjoin("/", cmd);
	while (*paths)
	{
		cmd_path = ft_strjoin(*paths, sub);
		if (!cmd_path)
			return (NULL);
		if (!access(cmd_path, F_OK))
			break ;
		free(cmd_path);
		paths++;
	}
	free(sub);
	free(cmd);
	return (cmd_path);
}

static void	inprocess(int pipefd[2], char *infile, char *cmd, char **envp)
{
	int		fd;
	int		execstat;
	int		pid;
	char	*path;

	pid = fork();
	if (pid == -1)
		printerror("fork error");
	else if (pid == 0)
	{
		close(pipefd[0]);
		fd = open(infile, O_RDONLY);
		if (fd == -1)
			printerror("Infile small problem");
		if (is_file_too_big(infile))
			printerror("very big");
		dup2(pipefd[1], STDOUT_FILENO);
		dup2(fd, STDIN_FILENO);
		path = find_path(envp, cmd);
		if (!path)
			printerror("inPath not found");
		execstat = execve(path, ft_split(cmd, ' '), envp);
		if (execstat == -1)
			printerror("execve small problem failed or not foun");
	}
}

static void	outprocess(int pipefd[2], char *outfile, char *cmd, char **envp)
{
	int		fd;
	int		execstat;
	int		pid;
	char	*path;

	pid = fork();
	if (pid == -1)
		printerror("fork error");
	else if (pid == 0)
	{
		close(pipefd[1]);
		fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			printerror("outfile small problem");
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		path = find_path(envp, cmd);
		if (!path)
			printerror("outPath not found");
		execstat = execve(path, ft_split(cmd, ' '), envp);
		if (execstat == -1)
			printerror("execve small problem failed or not foun");
	}
}

int	main(int ac, char **av, char **envp)
{
	int	pipefd[2];

	if (ac != 5)
	{
		ft_putstr_fd("try this bratan: ./pipex filein cmd1 cmd2 fileout\n", 1);
		return (1);
	}
	if (pipe(pipefd) == -1)
		printerror("lmao ur pipe is broken");
	inprocess(pipefd, av[1], av[2], envp);
	wait(NULL);
	outprocess(pipefd, av[4], av[3], envp);
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
