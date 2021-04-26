/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:36:55 by jmercier          #+#    #+#             */
/*   Updated: 2021/04/26 01:37:50 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

static size_t	ft_pstrclen(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return (i);
}

static char		*ft_pstrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return ((char*)ptr);
		ptr++;
	}
	if (*ptr == (char)c)
		return ((char*)ptr);
	return (NULL);
}

static char		*ft_psubstr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (s == NULL || start > (unsigned int)ft_strlen(s))
	{
		if (!(dest = (char*)malloc(sizeof(char))))
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && s[start] != '\0' && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

static char		*ft_put_save_in_tab(char *tabfd)
{
	if (ft_pstrchr(tabfd, '\n'))
	{
		ft_strcpy(tabfd, ft_pstrchr(tabfd, '\n') + 1);
		return (tabfd);
	}
	return (NULL);
}

int				get_next_line(int const fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*tabfd[255];
	int			checkfd;
	char		*tmp;
	int			flag;

	flag = 0;
	if (fd < 0 || !line || (!(tabfd[fd]) && (tabfd[fd] =
	ft_strnew(0)) == NULL) || BUFFER_SIZE < 1 || read(fd, buf, 0) == -1)
		return (-1);
	while (!(ft_pstrchr(tabfd[fd], '\n')) &&
									(checkfd = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[checkfd] = '\0';
		tmp = tabfd[fd];
		tabfd[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	*line = ft_psubstr(tabfd[fd], 0, ft_pstrclen(tabfd[fd], '\n'));
	flag = (ft_pstrchr(tabfd[fd], '\n') == NULL) ? 1 : 0;
	tmp = ft_put_save_in_tab(tabfd[fd]);
	if (flag == 1)
		free(tabfd[fd]);
	tabfd[fd] = tmp;
	return (flag == 1 || tabfd[fd] == NULL) ? 0 : 1;
}
