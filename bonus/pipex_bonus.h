/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:19:23 by aakroud           #+#    #+#             */
/*   Updated: 2025/04/19 15:19:35 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include "get_next_line_bonus.h"

typedef struct s_pip
{
	char	*e;
	int		input_fd;
	int		output_fd;
	int		fd[2];
	int		id;
	int		flag;
	char	**cmd;
	int		i;
	int		prev_fd;
	char	*temp;
	char	*str;
	int		j;
}	t_pip;

typedef struct s_cmd
{
	char	**p;
	char	**t;
	char	*str;
	char	*cmd;
	int		i;
}	t_cmd;

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
void	*ft_memcpy(void	*dest, const void *src, size_t	n);
char	*ft_strdup(const char *s1);
char	**ft_split(char	const	*s, char c);
void	ft_cmd_exit(char *str);
char	*ft_find_str(char **env);
char	*ft_strjoin(char	const	*s1, char	const	*s2);
char	*ft_strmcpy(char *src);
char	*ft_cmd_check(char *env, char *s);
int		ft_file_check(char *str);
int		ft_file_create(char *str, char *argv);
void	ft_handle_exit(char *str);
int		ft_strcmp(char *str1, char *str2);
void	ft_free(char **p);
int		delimiter(char c, char del);
void	ft_close_last(t_pip *value);
void	ft_close(t_pip *value);
void	ft_execve_close(t_pip *value);
int		ft_hdoc(char *limiter);
void	ft_cmd_pipex(t_pip *value, char **argv);
void	ft_first_child(t_pip *value, char **argv, int i, int flag);
void	ft_last_child(t_pip *value, char **argv);
void	ft_middle_child(t_pip *value);
int		ft_is_spaces(char *s);

#endif