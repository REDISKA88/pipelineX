#include "pipex.h"
void	ft_errors(int code)
{
	if (code == 0)
	{
		write(1, "Enter as: ./pipex file1 cmd1 cmd2 file2\n", 40);
		exit(1);
	}
	if (code == 1)
	{
		perror("Open fail");
		exit(1);
	}
	if (code == 2)
	{
		perror("Pipe fail");
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	fd[2];
	int	pfd[2];

	if (argc != 5)
		ft_errors(0);
	fd[0] = open(argv[1], O_RDONLY, 0777);
	fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd[0] == -1 || fd[1] == -1)
		ft_errors(1);
	if (pipe(pfd) == -1)
		ft_errors(2);
	pid = fork();
	if (pid == -1)
	{
		perror("Fork error:");
		return (0);
	}
	if (pid == 0)
		ft_child(fd[0], pfd, argv, envp);
	else
		ft_parent(fd[1], pfd, argv, envp);
	return (0);
}
