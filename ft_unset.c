#include "minishell.h"

t_env *ft_check(t_env *h, char *str)
{
    while (h != NULL)
    {
        if (ft_strcmp(h->key, str) == 0)
            return (h);
        h = h->next;
    }
    return (NULL);
}

int ft_parse(char *s)
{
    int i;

    i = 0;
    if (ft_isalpha(s[0]) != 0 && s[0] != '_')
        return (1);
    while (s[i] != '\0')
    {
        if (ft_isalpha(s[i]) != 0 && s[i] != '_' && ft_isdigit(s[i]) != 0)  
            return (1);
        i++;
    }
    return (0);
}

t_env   *ft_unset(t_env *h, char **s)
{
    t_env   *node;
    int     flag;
    t_env   *start;//parsing
    int     i;

    flag = 0;
    i = 1;
    start = NULL;
    if (s == NULL)
        return (NULL);
    start = h;
    while (s[i] != NULL)
    {
        h = start;
        if (ft_parse(s[i]) == 1)
        {
            write(2, "unset: ", 8);
            write(2, s[i], ft_strlen(s[i]));
            write(2, ": invalid parameter name", 25);
        }
        else
        {
            node = ft_check(h, s[i]);
            if (node != NULL)
            {
                while (h != NULL && h->next != NULL)
                {
                    if (flag == 0 && h == node)
                    {
                        h = h->next;
                        return (h);
                    }
                    if (h->next == node)
                    {
                        h->next = node->next;
                        node->next = NULL;
                    }
                    flag = 1;
                    h = h->next;
                }
            }
        }
        i++;
    }
    return (start);
}

int main(int argc, char **argv, char **env)
{
    t_env   *head;

    head = env_fill(env);
    ft_unset(head, argv);
    while (head != NULL)
    {
        printf("%s=%s\n", head->key, head->value);
        head = head -> next;
    }
}