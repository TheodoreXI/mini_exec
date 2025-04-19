/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:52:01 by aakroud           #+#    #+#             */
/*   Updated: 2025/04/19 15:19:40 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_pipex
{
	char	*e;
	int		fd[2];
	int		id;
	int		id2;
}	t_pipex;

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
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
void	ft_cmd_exit(char *str);
char	*ft_find_str(char **env);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmcpy(char *src);
char	*ft_cmd_check(char *env, char *s);
int		ft_file_check(char *str);
int		ft_file_create(char *str);
void	ft_handle_exit(char *str);
char	*ft_strchr(const char *s, int c);
void	ft_id_close(int fd[2], int file_fd, int i);
int		delimiter(char c, char del);
void	ft_free(char **p);
int		ft_is_spaces(char *s);

#endif