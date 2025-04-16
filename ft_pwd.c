#include "minishell.h"

void    ft_pwd(void)
{
    char *path;

    path = getcwd(NULL, 0);
    if (path == NULL)
    {
        perror("pwd: ");
        exit (1);
    }
    printf("%s\n", path);
    free (path);
}

// int main()
// {
//     ft_pwd();
// }