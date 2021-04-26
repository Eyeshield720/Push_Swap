/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_ope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:29:35 by jmercier          #+#    #+#             */
/*   Updated: 2021/04/26 05:26:09 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

/*
**	Ope swap and push for both stacks
*/

void		swap_sta(t_stack *a)
{
	int		tmp;

	if (a == NULL || a->len < 2)
		return ;
	tmp = a->first->next->nb;
	a->first->next->nb = a->first->nb;
	a->first->nb = tmp;
}

void		swap_stb(t_stack *b)
{
	int		tmp;

	if (b == NULL || b->len < 2)
		return ;
	tmp = b->first->next->nb;
	b->first->next->nb = b->first->nb;
	b->first->nb = tmp;
}

/*
**  Push first elem Stack B to Stack A
*/

void		push_sta(t_stack *a, t_stack *b)
{
	t_pile	*tmp;

	if (b == NULL)
		return ;
	tmp = b->first->next;
	b->first->next = a->first;
	a->first = b->first;
	b->first = tmp;
	b->len--;
	a->len++;
}

/*
**  Push first elem Stack A to Stack B
*/

void		push_stb(t_stack *a, t_stack *b)
{
	t_pile	*tmp;

	if (a == NULL)
		return ;
	tmp = a->first->next;
	a->first->next = b->first;
	b->first = a->first;
	a->first = tmp;
	a->len--;
	b->len++;
}
