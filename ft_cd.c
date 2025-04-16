#include "minishell.h"

// t_env	*env_fill(char **argev)
// {
// 	int i;
// 	int j;
// 	t_env	*head;
// 	t_env	*new_node;
// 	t_env	*tmp;

// 	i = 0;
// 	j = 0;
// 	head = malloc(sizeof(t_env));
// 	while (argev[i] && argev[i][j] != '=')
// 		j++;
// 	head->key = ft_substr(argev[i],0, j);
// 	head->value = ft_substr(argev[i], (j + 1), ft_strlen(argev[i]) - (j + 1));
// 	j = 0;
// 	head->next = NULL;
// 	tmp = head;
// 	i++;
// 	while (argev[i])
// 	{
// 		new_node = malloc(sizeof(t_env));
// 		while (argev[i] && argev[i][j] != '=')
// 			j++;
// 		new_node->key = ft_substr(argev[i],0, j);
// 		new_node->value = ft_substr(argev[i], (j + 1), ft_strlen(argev[i]) - (j + 1));
// 		j = 0;
// 		new_node->next = NULL;
// 		tmp->next = new_node;
// 		tmp = new_node;
// 		i++;
// 	}
// 	return (head);
// }


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

void    ft_cd(char **s, t_env *h)
{
    char    *path;
    t_env   *PWD;
    t_env   *OLD_PWD;

    PWD = ft_check(h, "PWD");
    OLD_PWD = ft_lstnew("OLDPWD", NULL);
    if (s[1] == NULL)
    {
        path = getenv("HOME");
        if (path == NULL)
        {
            write(2, "minishell: cd: HOME not set", 28);
            exit (1); 
        }
        if (chdir(path) == -1)
        {
            write(2, "minishell: cd: ", 16);
            write(2, path, ft_strlen(path));
            write(2, ": No such file or directory", 28);
            exit (1);
        }
        OLD_PWD->value = PWD->value;
        PWD->value = path;
        printf("old_pwd: %s\n", OLD_PWD->value);
        printf("pwd: %s\n", PWD->value);
    }
    else
    {
        if (chdir(s[1]) == -1)
        {
            write(2, "minishell: cd: ", 16);
            write(2, s[1], ft_strlen(s[1]));
            write(2, ": No such file or directory", 28);
            exit (1);
        }
        OLD_PWD->value = PWD->value;
        PWD->value = getcwd(NULL, 0);
        printf("old_pwd: %s\n", OLD_PWD->value);
        printf("pwd: %s\n", PWD->value);
    }
}

int main(int argc, char **argv, char **env)
{
    t_env   *head;

    head = env_fill(env);
    ft_cd(argv, head);
}