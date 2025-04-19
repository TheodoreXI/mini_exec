/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:22:59 by aakroud           #+#    #+#             */
/*   Updated: 2025/04/19 17:54:19 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_cmd_helper(t_cmd *com, int i, char *env, char *s)
{
	if (i == 0)
	{
		com->p = ft_split(env, ':');
		if (com->p == NULL)
			exit (1);
		com->t = ft_split(s, 32);
		if (com->t == NULL || com->t[0] == NULL)
			exit (1);
		com->str = ft_strmcpy(com->t[0]);
	}
	if (i == 1)
	{
		ft_free(com->t);
		ft_free(com->p);
		free (com->str);
	}
}

char	*ft_cmd_check(char *env, char *s)
{
	t_cmd	com;

	com.i = 0;
	if (s[0] == '\0' || ft_is_spaces(s) == 0)
		return (NULL);
	if (ft_strchr(s, '/') != NULL || env == NULL || env[0] == '\0')
	{
		if (access(s, X_OK) == 0)
			return (ft_strdup(s));
		return (NULL);
	}
	ft_cmd_helper(&com, 0, env, s);
	while (com.p[com.i] != NULL)
	{
		com.cmd = ft_strjoin(com.p[com.i], com.str);
		if (access(com.cmd, X_OK) == 0)
		{
			ft_cmd_helper(&com, 1, env, s);
			return (com.cmd);
		}
		free (com.cmd);
		com.i++;
	}
	ft_cmd_helper(&com, 1, env, s);
	return (NULL);
}

int	ft_file_check(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	return (fd);
}

int	ft_file_create(char *str, char *argv)
{
	int	fd;

	if (ft_strcmp("here_doc", argv) == 0)
		fd = open(str, O_RDWR | O_APPEND | O_CREAT, 0644);
	else
		fd = open(str, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (fd);
}

void	ft_handle_exit(char *str)
{
	write(2, "pipex: no such file or directory: ", 34);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit (1);
}
