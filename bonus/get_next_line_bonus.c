/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakroud <aakroud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:41:38 by aakroud           #+#    #+#             */
/*   Updated: 2025/03/23 20:07:50 by aakroud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char *stash)
{
	char	*buffer;
	int		i;

	i = 0;
	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	buffer = malloc(i + 2);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		buffer[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		buffer[i] = stash[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static char	*update_line(char *stash, char *list)
{
	char	*new_buffer;
	size_t	i;
	size_t	lent;
	size_t	total;

	i = 0;
	lent = ft_strlen(list);
	total = ft_strlen(stash);
	if (stash == NULL || lent >= total)
		return (NULL);
	new_buffer = malloc(total - lent + 1);
	if (new_buffer == NULL)
		return (NULL);
	while (stash[lent + i] != '\0')
	{
		new_buffer[i] = stash[lent + i];
		i++;
	}
	new_buffer[i] = '\0';
	return (new_buffer);
}

static char	*ft_read(char **stash, int bytes_read, int fd, char *temp)
{
	char	*temp_stash;

	if (stash == NULL)
		return (NULL);
	while (ft_strchr(*stash, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(temp), free(*stash), NULL);
		else if (bytes_read == 0 && *stash == NULL)
			return (free(temp), NULL);
		temp[bytes_read] = '\0';
		temp_stash = *stash;
		*stash = ft_strjoin(*stash, temp);
		if (stash == NULL)
			return (free(temp_stash), free(temp), NULL);
		free(temp_stash);
		temp_stash = NULL;
	}
	return (*stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*temp;
	char		*line;
	int			bytes_read;
	char		*new_stash;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (temp == NULL)
		return (NULL);
	stash = ft_read(&stash, bytes_read, fd, temp);
	if (!stash)
		return (NULL);
	free (temp);
	line = get_line(stash);
	new_stash = update_line(stash, line);
	free(stash);
	stash = new_stash;
	return (line);
}
