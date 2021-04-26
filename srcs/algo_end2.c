/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_end2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 23:41:14 by jmercier          #+#    #+#             */
/*   Updated: 2021/04/25 23:42:01 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

static void	worth_swapping2(t_stack *a)
{
	if (a->to_cmp.fb_ra)
	{
		a->must.fb_ra = 1;
		a->must.fb_rr = 0;
		a->must.fb_rrr = 0;
	}
	else if (a->to_cmp.fb_rr)
	{
		a->must.fb_ra = 0;
		a->must.fb_rr = 1;
		a->must.fb_rrr = 0;
	}
	else if (a->to_cmp.fb_rrr)
	{
		a->must.fb_ra = 0;
		a->must.fb_rr = 0;
		a->must.fb_rrr = 1;
	}
}

void		worth_swapping(t_stack *a)
{
	if (a->must.nb_ope > a->to_cmp.nb_ope ||
	(a->must.nb_ope == a->to_cmp.nb_ope && a->must.value > a->to_cmp.value))
	{
		a->must.ra = a->to_cmp.ra;
		a->must.rb = a->to_cmp.rb;
		a->must.rra = a->to_cmp.rra;
		a->must.rrb = a->to_cmp.rrb;
		a->must.rr = a->to_cmp.rr;
		a->must.rrr = a->to_cmp.rrr;
		a->must.nb_ope = a->to_cmp.nb_ope;
		a->must.value = a->to_cmp.value;
		a->must.tmp_ra = a->to_cmp.tmp_ra;
		a->must.tmp_rb = a->to_cmp.tmp_rb;
		a->must.tmp_rra = a->to_cmp.tmp_rra;
		a->must.tmp_rrb = a->to_cmp.tmp_rrb;
		worth_swapping2(a);
	}
}

void		reset_ope(t_stack *a)
{
	a->must.ra = 0;
	a->must.rb = 0;
	a->must.rra = 0;
	a->must.rrb = 0;
	a->must.rr = 0;
	a->must.rrr = 0;
	a->must.nb_ope = 0;
	a->must.fb_rr = 0;
	a->must.fb_rrr = 0;
	a->to_cmp.ra = 0;
}

void		feel_worth_it(t_stack *a, t_stack *b)
{
	t_pile	*tmp;

	tmp = a->first;
	a->must.value = tmp->nb;
	if (a->must.value == a->max || a->must.value == a->max2
		|| a->must.value == a->max3)
	{
		a->must.ra++;
		a->must.check = 1;
		return ;
	}
	plan_must(b, &a->must);
	how_muchop1(&a->must);
	worth_it_cmp(a, b);
}
