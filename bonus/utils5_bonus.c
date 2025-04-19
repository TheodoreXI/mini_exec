/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:35:34 by aakroud           #+#    #+#             */
/*   Updated: 2025/04/19 15:12:19 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_hdoc_free(char **str, char **limiter, int *fd)
{
	free (*str);
	free (*limiter);
	close (*fd);
}

int	ft_hdoc(char *limiter)
{
	char	*str;
	int		fd;
	char	*tmp;

	limiter = ft_strjoin(limiter, "\n");
	if (limiter == NULL)
		exit (1);
	unlink("text.txt");
	fd = open("text.txt", O_RDWR | O_CREAT, 0777);
	if (fd == -1)
		exit (1);
	str = get_next_line(0);
	while (str != NULL && ft_strcmp(limiter, str) != 0)
	{
		write(fd, str, ft_strlen(str));
		tmp = str;
		str = get_next_line(0);
		free(tmp);
	}
	ft_hdoc_free(&str, &limiter, &fd);
	fd = open("text.txt", O_RDONLY, 0777);
	if (fd == -1)
		exit (1);
	return (unlink ("text.txt"), fd);
}

void	ft_cmd_pipex(t_pip *value, char **argv)
{
	value->cmd = ft_split(argv[value->i], 32);
	if (value->cmd == NULL)
	{
		close(value->fd[0]);
		close(value->fd[1]);
		close(value->prev_fd);
		exit (1);
	}
	value->temp = value->cmd[0];
	value->cmd[0] = ft_cmd_check(value->e, value->cmd[0]);
	free (value->temp);
}

void	ft_first_helper(t_pip *value)
{
	if (value->input_fd == -1)
	{
		close(value->fd[0]);
		close(value->fd[1]);
		exit(1);
	}
	else
	{
		close(value->input_fd);
		close(value->fd[1]);
		close(value->fd[0]);
	}
}

void	ft_first_child(t_pip *value, char **argv, int i, int flag)
{
	if (i == 3 && flag == 1)
	{
		value->input_fd = ft_hdoc(argv[2]);
		if (value->input_fd == -1)
			ft_first_helper(value);
		dup2(value->input_fd, 0);
		dup2(value->fd[1], 1);
		ft_first_helper(value);
	}
	else if (i == 2)
	{
		value->input_fd = ft_file_check(argv[1]);
		if (value->input_fd == -1)
		{
			close (value->fd[0]);
			close (value->fd[1]);
			ft_handle_exit(argv[1]);
		}
		dup2(value->input_fd, 0);
		dup2(value->fd[1], 1);
		ft_first_helper(value);
	}
}
