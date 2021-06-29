#include "pipex.h"
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	char		*edst;
	const char	*esrc;

	if (!num || dst == src)
		return (dst);
	esrc = src;
	edst = dst;
	while (num > 0)
	{
		*edst = *esrc;
		num--;
		esrc++;
		edst++;
	}
	return (dst);
}

char	*ft_strdup(const char *str)
{
	char	*dst;
	int		len;

	len = ft_strlen(str);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, str, len);
	dst[len] = '\0';
	return (dst);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	strlen;

	if (str == NULL)
		return (NULL);
	strlen = ft_strlen(str);
	if (start > strlen)
		return (ft_strdup(""));
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	dst = malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, &str[start], len + 1);
	dst[len] = '\0';
	return (dst);
}

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < num)
	{
		if (str1[i] == '\0' && str2[i] == '\0')
			return (0);
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}