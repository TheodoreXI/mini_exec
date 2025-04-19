/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:25:38 by aakroud           #+#    #+#             */
/*   Updated: 2025/03/24 22:17:31 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
			if (*str == '\0')
			{
				free (str);
				return (NULL);
			}
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char	const	*s1, char	const	*s2)
{
	size_t	l1;
	size_t	l2;
	char	*total;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	total = (char *)malloc(l1 + l2 + 1);
	if (total == NULL)
		return (NULL);
	ft_memcpy(total, s1, l1);
	ft_memcpy(&total[l1], s2, l2);
	total[l1 + l2] = '\0';
	return (total);
}

char	*ft_strmcpy(char *src)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc(ft_strlen(src) + 2);
	if (dest == NULL)
		return (NULL);
	dest[j] = '/';
	j++;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

void	ft_free(char **p)
{
	int	i;

	i = 0;
	while (p[i] != NULL)
	{
		free (p[i]);
		i++;
	}
	free (p);
}
