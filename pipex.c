/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:23:55 by aakroud           #+#    #+#             */
/*   Updated: 2025/04/19 15:06:35 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_id1(int fd[2], char *cmd1, char *e, char *infile)
{
	int		input_fd;
	char	**result;

	input_fd = ft_file_check(infile);
	if (input_fd == -1)
		ft_handle_exit(infile);
	close(fd[0]);
	if (dup2(fd[1], 1) == -1 || dup2(input_fd, 0) == -1)
		ft_id_close(fd, input_fd, 1);
	close(input_fd);
	close(fd[1]);
	result = ft_split(cmd1, 32);
	if (result == NULL)
	{
		close(fd[1]);
		exit(1);
	}
	result[0] = ft_cmd_check(e, result[0]);
	if (result[0] == NULL)
		ft_cmd_exit(cmd1);
	execve(result[0], result, NULL);
	exit(1);
}

void	ft_id2(int fd[2], char *cmd2, char *e, char *outfile)
{
	int		output_fd;
	char	**result;

	output_fd = ft_file_create(outfile);
	if (output_fd == -1)
		ft_handle_exit(outfile);
	close(fd[1]);
	if (dup2(fd[0], 0) == -1 || dup2(output_fd, 1) == -1)
		ft_id_close(fd, output_fd, 1);
	result = ft_split(cmd2, 32);
	if (result == NULL)
	{
		close(fd[0]);
		exit(1);
	}
	result[0] = ft_cmd_check(e, result[0]);
	if (result[0] == NULL)
		ft_cmd_exit(cmd2);
	execve(result[0], result, NULL);
	exit(1);
}

void	ft_child_exit(t_pipex *value)
{
	close(value->fd[0]);
	close(value->fd[1]);
	exit(1);
}

void	ft_close(t_pipex *value)
{
	close(value->fd[0]);
	close(value->fd[1]);
	wait(NULL);
	wait(NULL);
	free (value->e);
}

int	main(int argc, char *argv[], char **env)
{
	t_pipex	value;

	value.e = ft_find_str(env);
	if (argc == 5)
	{
		if (pipe(value.fd) == -1)
			exit(1);
		value.id = fork();
		if (value.id == -1)
			ft_child_exit(&value);
		if (value.id == 0)
			ft_id1(value.fd, argv[2], value.e, argv[1]);
		else
		{
			value.id2 = fork();
			if (value.id2 == -1)
				ft_child_exit(&value);
			if (value.id2 == 0)
				ft_id2(value.fd, argv[3], value.e, argv[4]);
		}
		ft_close(&value);
	}
}
