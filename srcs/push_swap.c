/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:20:01 by jmercier          #+#    #+#             */
/*   Updated: 2021/12/10 08:23:09 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

void	main_algo(t_stack *a, t_stack *b)
{
	feel_worth_it(a, b);
	worth_move(a, b);
	reset_ope(a);
}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	if (ac > 1)
	{
		if (!ft_strcmp(av[1], "-v"))
			a.must.bonus_v = 1;
		if (parsing_arg(av, a.must.bonus_v) && set_stacks(&a, av, ac))
		{
			if (!start_move(&a, &b))
				return (0);
			while (a.len > 3)
				main_algo(&a, &b);
			finisher(&a, &b);
		}
		else
			printf("Error\n");
	}
	return (0);
}
