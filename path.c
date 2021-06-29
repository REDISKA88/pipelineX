#include "pipex.h"
char	*ft_find_path(char **envp)
{
	int i;

	i = 0;
	while (envp[i++])
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_strdup(&envp[i][5]));
	}
	return (0);
}

char *ft_command(char *cmd, char **path)
{
	int i;
	char *temp;
	char *exec;

	i = 0;
	exec = NULL;
	cmd = ft_strjoin("/",cmd);
	while (path[i])
	{
		temp = ft_strdup(path[i]);
		exec = ft_strjoin(temp, cmd);
		free(temp);
		if (!access(exec, 0) && !access(exec, 1))
			break;
		else
		{
			free(exec);
			exec = NULL;
		}
		i++;
	}
	return(exec);
}

void ft_free_array(char **temp)
{
	int i;

	i = 0;
	while(temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}
