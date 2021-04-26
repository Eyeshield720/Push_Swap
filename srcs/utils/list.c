/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:38:13 by jmercier          #+#    #+#             */
/*   Updated: 2021/04/26 05:23:20 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

t_pile		*ft_create_list(int nb, t_pile *face, int i)
{
	if (!(face = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	face->nb = nb;
	face->index = i;
	face->next = NULL;
	return (face);
}

void		free_stack(t_stack *random)
{
	t_pile	*to_del;

	if (random == NULL)
		return ;
	while (random->first)
	{
		to_del = random->first->next;
		free(random->first);
		random->first = to_del;
		to_del = NULL;
	}
	free(random->first);
	random->first = NULL;
}
