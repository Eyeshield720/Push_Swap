/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:48:11 by jmercier          #+#    #+#             */
/*   Updated: 2021/04/26 01:48:25 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pcswap.h"

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	int		c;
	size_t	i;

	i = 0;
	c = 0;
	while (i < n)
	{
		((unsigned char*)s)[i] = (unsigned char)c;
		i++;
	}
}

long	ft_atoi(const char *str)
{
	long	res;
	int		i;
	int		sig;

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
