#include "minishell.h"

int	delimiter(char c, char del)
{
	return (c == del);
}

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


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	
	return (dest);
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

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	dup = (char *)malloc(i + 1);
	if (dup == NULL)
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

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

t_env	*ft_lstnew(void *key, void *value)
{
	t_env	*newnode;

	newnode = (t_env *)malloc(sizeof(t_env));
	if (newnode == NULL)
		return (NULL);
	newnode -> key = key;
	newnode -> value = value;
	newnode -> next = NULL;
	return (newnode);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*help;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		new -> next = *lst;
		*lst = new;
		return ;
	}
	help = *lst;
	while (help -> next != NULL)
		help = help -> next;
	help -> next = new;
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (0);
	else
		return (1);
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
	char	*empty;
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
	{
		empty = ft_empty();
		return (empty);
	}
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	else
		return (1);
}

t_env	*env_fill(char **argev)
{
	int i;
	int j;
	t_env	*head;
	t_env	*new_node;
	t_env	*tmp;

	i = 0;
	j = 0;
	head = malloc(sizeof(t_env));
	while (argev[i] && argev[i][j] != '=')
		j++;
	head->key = ft_substr(argev[i],0, j);
	head->value = ft_substr(argev[i], (j + 1), ft_strlen(argev[i]) - (j + 1));
	j = 0;
	head->next = NULL;
	tmp = head;
	i++;
	while (argev[i])
	{
		new_node = malloc(sizeof(t_env));
		while (argev[i] && argev[i][j] != '=')
			j++;
		new_node->key = ft_substr(argev[i],0, j);
		new_node->value = ft_substr(argev[i], (j + 1), ft_strlen(argev[i]) - (j + 1));
		j = 0;
		new_node->next = NULL;
		tmp->next = new_node;
		tmp = new_node;
		i++;
	}
	return (head);
}

static int	ft_space(const char **str, int sign)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

long	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long			res;
	long			tmp;

	sign = 1;
	i = 0;
	res = 0;
	tmp = 0;
	sign = ft_space(&str, sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res / 10 != tmp)
			return (LONG_MAX);
		tmp = res;
		i++;
	}
	return (res * sign);
}
