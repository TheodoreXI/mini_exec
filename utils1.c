/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:24:35 by aakroud           #+#    #+#             */
/*   Updated: 2025/03/24 22:18:22 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_cmd_exit(char *str)
{
	write(2, "pipex: command not found: ", 27);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

char	*ft_find_str(char **env)
{
	int		i;
	char	*str;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			str = ft_substr(env[i], 5, 57);
			return (str);
		}
		i++;
	}
	return (env[i]);
}

char	*ft_strmcpy(char *src)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc(ft_strlen(src) + 2);
	if (!dest)
		return (NULL);
	dest[j++] = '/';
	while (src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dest);
}

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
