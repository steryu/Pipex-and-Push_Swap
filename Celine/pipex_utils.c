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

char	*search_path(char **mypaths, char *cmd)
{
	int		i;
	char	*final_cmd;

	i = -1;
	while (mypaths[i])
	{
		final_cmd = ft_strjoin(ft_strjoin(mypaths[i], "/"), cmd);
		if (access(final_cmd, F_OK) == 0)
			return (final_cmd);
		i++;
	}
	return (0);
}

char	*execute(char *cmd, char **env)
{
	char	**mypaths;
	char	*path_env;
	char	*cmdarg;
	char	*final_cmd;

	path_env = get_path(env);
	mypaths = ft_split(path_env, ':');
	cmdarg = *ft_split(cmd, ' ');
	if (search_path(mypaths, cmd) == NULL)
		exit(0);
	else
		execve(final_cmd, &cmdarg, env);
	perror("could not execute");
	return (0);
}
