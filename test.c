#include "minishell.h"

int main(int argc, char **argv)
{
    char **p;
    char *str;

    p = ft_split(argv[1], '=');
    int i = 0;
    while (p[i] != NULL)
    {
        printf("%s\n", p[i]);
        i++;
    }
}     