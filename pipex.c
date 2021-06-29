#include "pipex.h"
// fd[0] read
// fd[1] write
int main(int argc, char **argv, char **envp)
{
	int pid;
	int fd[2];
	int pfd[2];

	if (argc != 5)
		return (-1);
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_WRONLY, O_TRUNC, O_CREAT, 0777);
	if (fd[0] == -1 || fd[1] == -1)
		return (-1);
	if (pipe(pfd) == -1)
		perror("Pipe error:");
	pid = fork();
	if (pid == -1)
	{
		perror("Fork error:");
		return (0);
	}
	if (pid == 0)
		ft_child(fd[0], fd, argv, envp);
	else
		ft_parent(fd[1], fd, argv, envp);
	return (0);
}