/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:49:57 by cdiks             #+#    #+#             */
/*   Updated: 2021/12/17 15:02:19 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

int		check_file(char filename, char *name)
{
	if (filename == 'i')
	{
		if (access(name, F_OK) == 0)
			return (open(name, O_RDONLY));
		else
		{
			write(2, "no such file or directory: ", 28);
			write(2, name, ft_strlen(name));
			write(2, "\n", 1);
		}
	}
	else
		return (open(name, O_CREAT | O_RDWR | O_TRUNC, 0644));
	return (0);
}

char	*get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*search_path(char **mypaths, char *cmdarg)
{
	int		i;
	char	*final_cmd;

	i = 0;
	while (mypaths[i])
	{
		if (cmdarg[0] == '/')
			final_cmd = ft_strjoin(mypaths[i], cmdarg);
		else
			final_cmd = ft_strjoin(ft_strjoin(mypaths[i], "/"), cmdarg);
		if (access(final_cmd, F_OK) == 0)
			return (final_cmd);
		free(final_cmd);
		i++;
	}
	return (0);
}

char	*execute(char *cmd, char **env)
{
	char	**mypaths;
	char	*path_env;
	char	**cmdarg;
	char	*final_cmd;

	path_env = get_path(env);
	mypaths = ft_split(path_env, ':');
	cmdarg = ft_split(cmd, ' ');
	final_cmd = search_path(mypaths, cmdarg[0]);
	if (final_cmd == NULL)
		exit(0);
	else
		execve(final_cmd, cmdarg, env);
	perror("could not execute");
	return (0);
}
