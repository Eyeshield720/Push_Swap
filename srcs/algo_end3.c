/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_end3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 23:42:13 by jmercier          #+#    #+#             */
/*   Updated: 2021/12/10 08:42:31 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

static void	worth_move3(t_stack *a, t_stack *b)
{
	while (a->must.rb > 0)
	{
		rotate_stb(b);
		printf("rb\n");
		print_stacks(a, b);
		a->must.rb--;
	}
	while (a->must.rrb > 0)
	{
		rev_rotate_stb(b);
		printf("rrb\n");
		print_stacks(a, b);
		a->must.rrb--;
	}
	if (a->must.check == 0)
	{
		push_stb(a, b);
		printf("pb\n");
		print_stacks(a, b);
	}
	else
		a->must.check = 0;
}

static void	worth_move2(t_stack *a, t_stack *b)
{
	if (a->must.fb_rr)
	{
		a->must.rra = 0;
		a->must.rrb = 0;
		a->must.rrr = 0;
		while (a->must.rr > 0)
		{
			suit_rotate(a, b);
			printf("rr\n");
			print_stacks(a, b);
			a->must.rr--;
		}
	}
	if (a->must.fb_rrr)
	{
		a->must.ra = 0;
		a->must.rb = 0;
		a->must.rr = 0;
		while (a->must.rrr-- > 0)
		{
			suit_rot_reverse(a, b);
			printf("rrr\n");
			print_stacks(a, b);
		}
	}
}

static void	worth_move2b(t_stack *a)
{
	if (a->must.rb >= a->must.rrb && a->must.rrb > 0)
		a->must.rb = 0;
	else if (a->must.rb <= a->must.rrb && a->must.rb > 0)
		a->must.rrb = 0;
	if (a->must.ra >= a->must.rra && a->must.rra > 0)
		a->must.ra = 0;
	else if (a->must.ra <= a->must.rra && a->must.ra > 0)
		a->must.rra = 0;
}

void	worth_move(t_stack *a, t_stack *b)
{
	worth_move2(a, b);
	if (a->must.fb_ra)
		worth_move2b(a);
	while (a->must.ra > 0)
	{
		rotate_sta(a);
		printf("ra\n");
		print_stacks(a, b);
		a->must.ra--;
	}
	while (a->must.rra > 0)
	{
		rev_rotate_sta(a);
		printf("rra\n");
		print_stacks(a, b);
		a->must.rra--;
	}
	worth_move3(a, b);
}

void	finisher(t_stack *a, t_stack *b)
{
	short_opesta(a, b);
	final_sort(a, b);
	free_stack(a);
	free_stack(b);
}
