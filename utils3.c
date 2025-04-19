/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:11:42 by aakroud           #+#    #+#             */
/*   Updated: 2025/03/22 01:11:53 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count_strings(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && delimiter(s[i], c) == 1)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && delimiter(s[i], c) == 0)
			i++;
	}
	return (count);
}

static int	ft_lent_strlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && delimiter(s[i], c) == 0)
		i++;
	return (i);
}

static char	*ft_word(const char *s, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_lent_strlen(s, c);
	word = (char *)malloc(len_word + 1);
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_fill_string(char **str, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && delimiter(s[i], c) == 1)
			i++;
		if (s[i] != '\0')
		{
			str[j] = ft_word(&s[i], c);
			if (!str[j])
				return (0);
			j++;
		}
		while (s[i] != '\0' && delimiter(s[i], c) == 0)
			i++;
	}
	str[j] = 0;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**strings;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (ft_count_strings(s, c) + 1));
	if (!strings)
		return (NULL);
	if (!ft_fill_string(strings, s, c))
	{
		while (strings[i] != NULL)
			free(strings[i++]);
		free(strings);
		return (NULL);
	}
	return (strings);
}
