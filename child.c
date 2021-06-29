#include "pipex.h"
void	ft_child(int fd, int *pfd, char **argv, char **envp)
{
	char **cmd;
	char **path;
	char *exec_cmd;
	char *tmp_path;

	tmp_path = ft_find_path(envp);
	cmd = ft_split(argv[2], ' ');
	path = ft_split(tmp_path, ':');
	free(tmp_path);
	exec_cmd = ft_command(cmd[0], path);
	if (!exec_cmd)
		exit(1);
	ft_free_array(path);
	close(pfd[0]);
	dup2(fd, 0); // меняем чтение из консоли на чтение из файла
	dup2(pfd[1], 1); // меняем вывод на экранна фд трубки для записи
	close(pfd[1]);
	if (execve(exec_cmd, cmd, envp) == -1)
		printf("error\n");
	free(exec_cmd);
	ft_free_array(cmd);
}