/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:33:57 by aakroud           #+#    #+#             */
/*   Updated: 2025/04/19 15:18:13 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close_middle(t_pip *value)
{
	close (value->prev_fd);
	value->prev_fd = value->fd[0];
	value->flag = 0;
	close (value->fd[1]);
}

void	ft_first(t_pip *value, char **argv, int argc)
{
	if (ft_strcmp("here_doc", argv[1]) == 0)
	{
		value->i = 3;
		value->flag = 1;
	}
	else
		value->i = 2;
	value->j = value->i;
	while (value->j <= argc - 2)
	{
		value->cmd = ft_split(argv[value->j], 32);
		value->str = ft_cmd_check(value->e, value->cmd[0]);
		if (value->str == NULL)
			ft_cmd_exit(argv[value->j]);
		free (value->str);
		value->j++;
	}
}

void	ft_child(t_pip *value, char **argv, int argc, char **env)
{
	ft_first_child(value, argv, value->i, value->flag);
	if (value->i == argc - 2)
		ft_last_child(value, argv);
	else if (value->flag == 0 && value->i < argc - 2)
		ft_middle_child(value);
	execve(value->cmd[0], value->cmd, env);
	ft_execve_close(value);
}

void	ft_bonus_helper(t_pip *value, int argc)
{
	if (value->i == 3 && value->flag == 1)
		wait(NULL);
	if (value->i < argc - 2)
		ft_close_middle(value);
	else
		ft_close_last(value);
}

int	main(int argc, char *argv[], char **env)
{
	t_pip	value;

	if (argc >= 5 || (argc > 5 && ft_strcmp("here_doc", argv[1]) == 0))
	{
		value.flag = 0;
		value.e = ft_find_str(env);
		ft_first(&value, argv, argc);
		value.prev_fd = -1;
		value.j = argc - 1;
		while (value.i < argc - 1)
		{
			if (value.i != argc - 2)
				pipe(value.fd);
			ft_cmd_pipex(&value, argv);
			value.id = fork();
			if (value.id == 0)
				ft_child(&value, argv, argc, env);
			ft_bonus_helper(&value, argc);
			ft_free(value.cmd);
			value.i++;
		}
		ft_close(&value);
		while (wait (NULL) > 0)
			;
	}
}
