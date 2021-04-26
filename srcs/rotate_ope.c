/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:20:52 by jmercier          #+#    #+#             */
/*   Updated: 2021/04/26 05:27:29 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

void		rotate_sta(t_stack *a)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (a->first == NULL || a->len < 2)
		return ;
	tmp = a->first;
	tmp2 = tmp->next;
	while (a->first->next)
		a->first = a->first->next;
	a->first->next = tmp;
	tmp->next = NULL;
	a->first = tmp2;
}

void		rotate_stb(t_stack *b)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (b->first == NULL || b->len < 2)
		return ;
	tmp = b->first;
	tmp2 = tmp->next;
	while (b->first->next)
		b->first = b->first->next;
	b->first->next = tmp;
	tmp->next = NULL;
	b->first = tmp2;
}

void		rev_rotate_sta(t_stack *a)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (a->first == NULL || a->len < 2)
		return ;
	tmp = a->first;
	while (a->first->next->next)
		a->first = a->first->next;
	tmp2 = a->first->next;
	a->first->next = NULL;
	tmp2->next = tmp;
	a->first = tmp2;
}

void		rev_rotate_stb(t_stack *b)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (b->first == NULL || b->len < 2)
		return ;
	tmp = b->first;
	while (b->first->next->next)
		b->first = b->first->next;
	tmp2 = b->first->next;
	b->first->next = NULL;
	tmp2->next = tmp;
	b->first = tmp2;
}
