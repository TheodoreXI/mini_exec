#include "minishell.h"

void    ft_env(t_env *h)
{
    while (h != NULL)
    {
        printf("%s=%s\n", h->key, h->value);
        h = h->next;
    }
}