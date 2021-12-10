/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:36:55 by jmercier          #+#    #+#             */
/*   Updated: 2021/12/10 07:37:50 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

static int	recursive(const int fd, char **line, size_t index)
{
	char	buf;
	int		ret;

	ret = read(fd, &buf, 1);
	if (ret == 1 && buf != '\n')
	{
		recursive(fd, line, index + 1);
		(*line)[index] = buf;
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * index + 1);
		(*line)[index] = '\0';
	}
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	int		ret;

	ret = recursive(fd, line, 0);
	return (ret);
}
