/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:11:35 by jmercier          #+#    #+#             */
/*   Updated: 2021/05/26 03:38:28 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

static void	find_mina(t_stack *a)
{
	t_pile	*tmp;

	tmp = a->first;
	a->min = tmp->nb;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (a->min > tmp->nb)
			a->min = tmp->nb;
	}
}

void		begin_sort2(t_stack *a, t_stack *b)
{
	if (a->pos < a->len / 2)
	{
		while (a->pos > 1)
		{
			rotate_sta(a);
			printf("ra\n");
			print_stacks(a, b);
			a->pos--;
		}
	}
	else
	{
		while (a->pos < a->len + 1)
		{
			rev_rotate_sta(a);
			printf("rra\n");
			print_stacks(a, b);
			a->pos++;
		}
	}
	swap_sta(a);
	printf("sa\n");
	print_stacks(a, b);
}

int			begin_sort1(t_stack *a, t_stack *b)
{
	if (a->diff == 1 && a->len > 5)
	{
		find_mina(a);
		begin_sort2(a, b);
		if (a->pos == 1)
		{
			while (a->min != a->first->nb)
			{
				rev_rotate_sta(a);
				printf("rra\n") ? print_stacks(a, b) : 0;
			}
		}
		else
		{
			while (a->min != a->first->nb)
			{
				rotate_sta(a);
				printf("ra\n") ? print_stacks(a, b) : 0;
			}
		}
		if (check_first_stack(a) == 1)
			return (1);
		return (0);
	}
	return (1);
}

int			check_first_stack(t_stack *a)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	a->diff = 0;
	a->pos = 1;
	tmp = a->first;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
		{
			a->diff++;
			if (a->diff == 1)
				i = a->pos;
		}
		tmp = tmp->next;
		a->pos++;
	}
	if (a->diff == 1)
		a->pos = i;
	if (a->diff > 0)
		return (1);
	return (0);
}
