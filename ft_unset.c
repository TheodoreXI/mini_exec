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

t_env   *ft_unset(t_env *h, char **s)
{
    t_env   *node;
    int     flag;
    t_env   *start;

    flag = 0;
    start = NULL;
    if (s && s[1] != NULL)
    {
        node = ft_check(h, s[1]);
        if (node != NULL)
        {
            start = h;
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
    return (start);
}

int main(int argc, char **argv)
{
    t_env   a;
    t_env   b;
    t_env   c;
    t_env   d;

    a.key = ft_strdup("path");
    a.value = ft_strdup("jjidfue");
    b.key = ft_strdup("bin");
    b.value = ft_strdup("ffgdefrf");
    c.key = ft_strdup("becurity");
    c.value = ft_strdup("kkforjfn");
    d.key = ft_strdup("shell");
    d.value = ft_strdup("fffrjuruejf");

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;
    t_env   *head;
    head = &a;
    head = ft_unset(head, argv);
    while (head != NULL)
    {
        printf("%s\n", head->key);
        printf("%s\n", head->value);
        head = head -> next;
    }
}