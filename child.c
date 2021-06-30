#include "pipex.h"
void	ft_child(int fd, int *pfd, char **argv, char **envp)
{
	char	**cmd;
	char	**path;
	char	*tmp_path;

	tmp_path = ft_find_path(envp);
	cmd = ft_split(argv[2], ' ');
	path = ft_split(tmp_path, ':');
	free(tmp_path);
	cmd[0] = ft_command(cmd[0], path);
	if (!cmd[0])
		exit(1);
	ft_free_array(path);
	close(pfd[0]);
	dup2(fd, 0);
	dup2(pfd[1], 1);
	close(pfd[1]);
	if (execve(cmd[0], cmd, envp) == -1)
		printf("error\n");
	ft_free_array(cmd);
}
