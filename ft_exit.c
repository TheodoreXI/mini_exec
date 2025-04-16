#include "minishell.h"

int ft_check_string(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]) != 0)
            return (1);
        i++;
    }
    return (0);
}

int ft_modulo(char *str)
{
    long    n;
    int     m;

    n = ft_atoi(str);
    if (ft_strcmp(str, "9223372036854775807") != 0 && n == LONG_MAX)
    {
        write (2, "bash: exit: ", 13);
        write(2, str, ft_strlen(str));
        write(2, ": numeric argument required", 28);
        exit (1);
    }
    m = n % 256;
    return (m);
}


void    ft_exit(char **s)
{
    if (s[1] == NULL)
        exit (0);
    else
    {
        if (ft_check_string(s[1]) != 0)
        {
            write(2, "minishell: exit: ", 18);
            write(2, s[1], ft_strlen(s[1]));
            write(2, ": numeric argument required\n", 29);
            exit (255);
        }
        else if (s[2] != NULL)
            write(2, "minishell: exit: too many arguments\n", 37);
        else
        {
            printf("%d\n", ft_modulo(s[1]));
            exit (ft_modulo(s[1]));
        }
    }
}

int main(int argc, char **argv)
{
    ft_exit(argv);
    // printf("%ld\n", LONG_MAX);
}