/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:12:04 by aakroud           #+#    #+#             */
/*   Updated: 2025/03/24 22:18:30 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d1;
	unsigned const char	*s1;

	if (!dest && !src)
		return (NULL);
	d1 = (unsigned char *)dest;
	s1 = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (d1);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = ft_strlen(s1);
	dup = (char *)malloc(i + 1);
	if (!dup)
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*total;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	total = (char *)malloc(l1 + l2 + 1);
	if (!total)
		return (NULL);
	ft_memcpy(total, s1, l1);
	ft_memcpy(&total[l1], s2, l2);
	total[l1 + l2] = '\0';
	return (total);
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
