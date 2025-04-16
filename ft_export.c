#include "minishell.h"

t_env   *ft_sort_list(t_env *h)
{
    char   *tmp_key;
    char   *tmp_value;
    t_env   *head;
    t_env   *start;

    head = h;
    start = NULL;
    while (h != NULL && h->next != NULL)
    {
        start = h->next;
        while (start != NULL)
        {
            if (ft_strcmp(h->key, start->key) > 0)
            {
                tmp_key = h->key;
                h->key = start->key;
                start->key = tmp_key;
                tmp_value = h->value;
                h->value = start->value;
                start->value = tmp_value;
            }
            else if (ft_strcmp(h->key, start->key) == 0 && ft_strcmp(h->value, start->value) > 0)
            {
                tmp_key = h->key;
                h->key = start->key;
                start->key = tmp_key;
                tmp_value = h->value;
                h->value = start->value;
                start->value = tmp_value;
            }
            start = start->next;
        }
        h = h->next;
    }
    return (head);
}

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
        {
            printf("not here\n");     
            return (1);
        }
        i++;
    }
    return (0);
}

int ft_equal_check(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '=')
            return (0);
        i++;
    }
    return (1);
}

void    ft_export(char  **s, t_env *h)
{
    char    **v;
    t_env   *f;
    t_env   *new;
    char    *tmp;
    int     i;
    int     act;

    i = 1;
    if (s[1] == NULL)
    {
        h = ft_sort_list(h);
        while (h != NULL)
        {
            printf("%s=%s\n", h->key, h->value);
            h = h->next;
        }
        exit (1);
    }
    else if (s[i] != NULL)
    {
        while (s[i] != NULL)
        {
            act = 1;
            if (ft_strchr(s[i], '+') == NULL)
            {
                if (ft_equal_check(s[i]) == 0)
                    act = 0;
                v = ft_split(s[i], '=');
                if (v == NULL)
                    return ;
                f = ft_check(h, v[0]);
                if (f != NULL)
                {
                    tmp = f->value;
                    f->value = v[1];
                    free (tmp);
                }
                else
                {
                    if (ft_parse(v[0]) == 1)
                    {
                        if (i == 1)
                        {
                            write(2, "minishell: export: not an identifier: ", 39);
                            write(2, s[i], ft_strlen(s[i]));
                        }
                    }
                    else
                    {
                        if (act == 0)
                        {
                            if (v[1] == NULL)
                                 new = ft_lstnew(v[0], ft_strdup(""));
                            else
                                new = ft_lstnew(v[0], v[1]);
                        }
                        else
                            new = ft_lstnew(v[0], NULL);
                        ft_lstadd_back(&h, new);
                    }
                }

            }
            i++;
        }
        // h = ft_sort_list(h);
    }
}

int main(int argc, char **argv, char **env)
{
    t_env   *head;

    head = env_fill(env);
    ft_export(argv, head);
    while (head != NULL)
    {
        printf("%s=%s\n", head->key, head->value);
        head = head -> next;
    }
}
