#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp);
void	ft_child(int fd, int *pfd, char **argv, char **envp);
void	ft_parent(int fd, int *pfd, char **argv, char **envp);
char	*ft_find_path(char **envp);
char *ft_command(char *cmd, char **path);
void ft_free_array(char **temp);

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t num);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int	ft_strncmp(const char *s1, const char *s2, size_t num);
char	*ft_strjoin(char const *s1, char const *s2);
#endif
