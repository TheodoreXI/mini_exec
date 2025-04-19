/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:30:59 by aakroud           #+#    #+#             */
/*   Updated: 2025/03/24 22:19:59 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*f1;
	unsigned char	*f2;

	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	i = 0;
	while (i < n && f1[i] != '\0')
	{
		if (f1[i] != f2[i])
			return (f1[i] - f2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (f1[i] - f2[i]);
}

static char	*ft_empty(void)
{
	char	*empty;

	empty = (char *)malloc(1);
	if (empty == NULL)
		return (NULL);
	empty[0] = '\0';
	return (empty);
}

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	t;
	char	*sub;

	i = 0;
	t = 0;
	if (s == NULL)
		return (NULL);
	t = ft_strlen(s);
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	if (start >= t)
		return (free (sub), ft_empty());
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	*ft_memcpy(void	*dest, const void *src, size_t	n)
{
	size_t				i;
	unsigned char		*d1;
	unsigned const char	*s1;

	i = 0;
	d1 = (unsigned char *)dest;
	s1 = (unsigned const char *)src;
	if (dest == src)
		return (dest);
	if (d1 == NULL && s1 == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (d1);
}
