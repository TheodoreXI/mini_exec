/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:15:54 by aakroud           #+#    #+#             */
/*   Updated: 2025/04/15 17:19:48 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
#include <limits.h> //remove after

typedef struct s_list
{
	char			*data;
	char			*token;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;


typedef struct s_list_fd
{
	int					fd;
	char				*name;
	char				*command;
	char				*redir;
	struct s_list_fd	*next;
}	t_list_fd;

typedef struct s_tree
{
	char			*type;
	struct s_tree	*left;
	struct s_tree	*right;
	char			*command;
	char			**command_arr;
	char			*redirections;
}	t_tree;

typedef	struct s_env
{
	char *key;
	char *value;
	struct s_env *next;
}	t_env;

char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char	const	*s1, char	const	*s2);
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *str1, char *str2);
void	ft_lstadd_back(t_env **lst, t_env *new);
t_env	*ft_lstnew(void *key, void *value);
char	*ft_strchr(char *str, int c);
int		ft_isalpha(int c);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, const char *src);
int		ft_strncmp(char *str1, char *str2, size_t n);
int		ft_isdigit(int c);
t_env	*env_fill(char **argev);
long	ft_atoi(const char *str);

#endif
