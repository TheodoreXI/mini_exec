#include "minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


static char	*ft_empty(void)
{
	char	*empty;

	empty = (char *)malloc(1);
	if (!empty)
		return (NULL);
	empty[0] = '\0';
	return (empty);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	t;
	char	*sub;

	if (!s)
		return (NULL);
	t = ft_strlen(s);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	if (start >= t)
	{
		free (sub);
		return (ft_empty());
	}
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int ft_nline_check(char *str)
{
    int i;

    if (str[0] == '-' && str[1] == 'n')
    {
        i = 1;
        while (str[i] != '\0' && str[i] == 'n')
            i++;
        if (str[i] == '\0')
            return (0);
    }
    return (1);
}

void    ft_echo(char **s)
{
    char    *str;
    int     flag;
    int     i;
    int     j;

    i = 2;
	flag = 0;
	while (s[i] != NULL)
	{
		if (ft_nline_check(s[i]) == 0)
		{
			while (ft_nline_check(s[i]) == 0)
				i++;
			flag = 0;
		}
		else
			flag = 1;
		while (s[i] != NULL)
		{
			printf("%s", s[i]);
			if (s[i + 1] != NULL)
				printf(" ");
			i++;
		}
		if (s[i] == NULL)
			break;
		i++;
	}
	if (flag == 1)
		printf("\n");
}

int main(int argc, char **argv)
{
	ft_echo(argv);
}