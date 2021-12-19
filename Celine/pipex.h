/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiks <cdiks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:17:32 by cdiks             #+#    #+#             */
/*   Updated: 2021/12/17 12:08:43 by cdiks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include "./libft/libft.h"

char		*execute(char *cmd, char **env);
char		*search_path(char **mypaths, char *cmd);
void		child_process(int *end, char *cmd1, char **env);
void		parent_process(int *end, char *cmd2, char **env);
void		pipex(char *cmd1, char *cmd2, char **env);
char		*get_path(char **env);

#endif