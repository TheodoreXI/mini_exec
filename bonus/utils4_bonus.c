/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:32:05 by aakroud           #+#    #+#             */
/*   Updated: 2025/03/22 01:16:26 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	dup = (char *)malloc(i + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	delimiter(char c, char del)
{
	if (del == ':')
		return (c == ':');
	else
		return (c == ' ' || c == '\t');
}

void	ft_close_last(t_pip *value)
{
	close (value->fd[1]);
	close (value->fd[0]);
	close (value->prev_fd);
	value->fd[1] = -1;
	value->fd[0] = -1;
	value->prev_fd = -1;
}

void	ft_close(t_pip *value)
{
	close(value->fd[0]);
	close(value->fd[1]);
	close(value->prev_fd);
	free(value->e);
}

void	ft_execve_close(t_pip *value)
{
	close (value->fd[0]);
	close (value->fd[1]);
	close (value->prev_fd);
	exit (1);
}
