/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:05:55 by cdiks             #+#    #+#             */
/*   Updated: 2021/12/17 12:20:51 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

void	child_process(int *end, char *cmd1, char **env)
{
	dup2(end[1], STDOUT);
	if (dup2(end[1], STDOUT) < 0)
		return (perror("dup failed"));
	close(end[0]);
	execute(cmd1, env);
}

void	parent_process(int *end, char *cmd2, char **env)
{
	waitpid(-1, NULL, 0);
	dup2(end[0], STDIN);
	if (dup2(end[0], STDIN) < 0)
		return (perror("dup failed"));
	close(end[1]);
	execute(cmd2, env);
}

void	pipex(char *cmd1, char *cmd2, char **env)
{
	int		end[2];
	pid_t	id;

	pipe(end);
	if (pipe(end) < 0)
		return (perror("pipe failed"));
	id = fork();
	if (id < 0)
		return (perror("fork failed"));
	if (id == 0)
		child_process(end, cmd1, env);
	else
		parent_process(end, cmd2, env);
	return ;
}

int	main(int argc, char **argv, char **env)
{
	int		infile;
	int		outfile;
	char	*cmd1;
	char	*cmd2;

	if (argc == 5)
	{
		infile = open(argv[1], O_RDONLY);
		outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (infile < 0 || outfile < 0)
			return (0);
		dup2(infile, STDIN);
		dup2(outfile, STDOUT);
		cmd1 = argv[2];
		cmd2 = argv[3];
		pipex(cmd1, cmd2, env);
		close(infile);
		close(outfile);
	}
	return (0);
}
