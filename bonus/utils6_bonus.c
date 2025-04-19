/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:06:28 by aakroud           #+#    #+#             */
/*   Updated: 2025/03/24 22:24:22 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_last_child(t_pip *value, char **argv)
{
	value->output_fd = ft_file_create(argv[value->j], argv[1]);
	if (value->output_fd == -1)
	{
		close (value->prev_fd);
		close (value->fd[0]);
		close (value->fd[1]);
		ft_handle_exit(argv[value->j]);
	}
	dup2(value->output_fd, 1);
	dup2(value->prev_fd, 0);
	close (value->output_fd);
	close (value->prev_fd);
	close (value->fd[1]);
	close (value->fd[0]);
}

void	ft_middle_child(t_pip *value)
{
	dup2(value->prev_fd, 0);
	dup2(value->fd[1], 1);
	close (value->prev_fd);
	close (value->fd[1]);
	close (value->fd[0]);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	ft_is_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != 9 && s[i] != 32)
			return (1);
		i++;
	}
	return (0);
}
