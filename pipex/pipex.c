#include "pipex.h"

char	*get_env_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (0);
}

char	*get_path(char *cmd, char **env)
{
	char	*path_env;
	char	**mypath;
	char	*bin;
	int		i;

	path_env = get_env_path(env);
	mypath = (ft_split(path_env, ':'));
	i = 0;
	while (mypath[i])
	{
		if (cmd[0] == '/')
			bin = ft_strjoin(mypath[i], cmd);
		else
			bin = ft_strjoin(ft_strjoin(mypath[i], "/"), cmd);
		if (!access(bin, F_OK))
			return (bin);
		free(bin);
		i++;
	}
	return (0);
}

void	exec(char *cmd, char **env)
{
	char	*path;
	char	**cmdargs;

	cmdargs = ft_split(cmd, ' ');
	path = get_path(cmdargs[0], env);
	execve(path, cmdargs, env);
	write(2, "command not found: ", 19);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 2);
	exit(0);
}

void	pipex(int f1, int f2, char *cmd1, char **env)
{
	pid_t	parent;
	int		end[2];

	pipe(end);
	if (pipe(end) == -1)
		return (perror("pipe error"));
	parent = fork();
	if (parent < 0)
		return (perror("fork error"));
	if (!parent)
	{
		dup2(end[1], STDOUT);
		close(end[0]);
		close(f1);
		exec(cmd1, env);
	}
	else
	{
		waitpid(parent, NULL, 0);
		dup2(end[0], STDIN);
		close(end[1]);
		close(f2);
	}
}

int	main(int ac, char **ag, char **env)
{
	int	f1;
	int	f2;

	if (ac == 5)
	{
		f1 = file_check(ag[1], 0);
		f2 = file_check(ag[4], 1);
		if (f1 < 0 || f2 < 0)
			return (-1);
		dup2(f1, STDIN);
		dup2(f2, STDOUT);
		pipex(f1, f2, ag[2], env);
		exec(ag[3], env);
	}
	else
		write(1, "invalid number of arguments", 27);
	return (0);
}
