#include <pcswap.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*sf;

	if (!s1 || !s2)
		return (NULL);
	if (!(sf = (char*)malloc(sizeof(char) *
					((ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		sf[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		sf[i + j] = s2[j];
	sf[i + j] = '\0';
	return (sf);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
