#include "../../include/pcswap.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*res;

	res = (unsigned char*)s;
	while (n > 0)
	{
		*res = 0;
		res++;
		n--;
	}
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sig;

	res = 0;
	i = 0;
	sig = 1;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' || str[i] == ' '
			|| str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sig);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		atoi_spe(const char *str)
{
	int			i;
	int			neg;
	long		nb;

	i = 0;
	neg = 0;
	nb = 0;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10 + (str[i] - '0');
		if (nb > INT_MAX && !neg || nb < INT_MIN && neg)
			return (0);
		i++;
	}
	printf("[%d]\n", nb);
	return (1);
}
