/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:29:12 by aakroud           #+#    #+#             */
/*   Updated: 2025/03/22 00:51:29 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_file_check(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	return (fd);
}

int	ft_file_create(char *str)
{
	int	fd;

	fd = open(str, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd != -1)
		return (fd);
	return (fd);
}

void	ft_handle_exit(char *str)
{
	write(2, "pipex: no such file or directory: ", 35);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	p;

	p = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == p)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == p)
		return ((char *)&s[i]);
	return (NULL);
}

void	ft_id_close(int fd[2], int file_fd, int i)
{
	if (i == 1)
	{
		close(fd[1]);
		close(file_fd);
		exit(1);
	}
	if (i == 2)
	{
		close(fd[0]);
		close(file_fd);
		exit(1);
	}
}
