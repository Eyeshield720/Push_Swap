#include <pcswap.h>

static int	ftset(char c, char *set)
{
	int		i;

	i = -1;
	while (set[++i] != '\0')
		if (set[i] == c)
			return (1);
	return (0);
}

static int	ft_word(const char *s, char *set)
{
	int		i;
	int		wo;

	i = -1;
	wo = 0;
	while (s[++i])
	{
		if (!ftset(s[i], set) && (ftset(s[i + 1], set) || !s[i + 1]))
			wo++;
	}
	return (wo);
}

static char	*ft_mallet(const char *src, char *set)
{
	int		len;
	int		ind;
	char	*mallet;

	len = 0;
	while (src[len] && !ftset(src[len], set))
		len++;
	if (!(mallet = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ind = 0;
	while (src[ind] && !ftset(src[ind], set))
	{
		mallet[ind] = src[ind];
		ind++;
	}
	mallet[ind] = '\0';
	return (mallet);
}

char		**ft_split(char const *s, char *set)
{
	int		i;
	int		j;
	int		kase;
	char	**mal;

	if (!s)
		return (NULL);
	kase = ft_word(s, set);
	if (!(mal = (char**)malloc(sizeof(char*) * (kase + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < kase)
	{
		while (s[i] && ftset(s[i], set))
			i++;
		mal[j++] = ft_mallet(&s[i], set);
		while (s[i] && !ftset(s[i], set))
			i++;
	}
	mal[j] = 0;
	return (mal);
}

void		free_chartab(char **chartab)
{
	int ind;

	ind = -1;
	while (chartab[++ind])
	{
		free(chartab[ind]);
		chartab[ind] = NULL;
	}
	free(chartab);
	chartab = NULL;
}