#include <pcswap.h>

void		main_algo(t_stack *a, t_stack *b)
{
	feel_worth_it(a, b);
	worth_move(a, b);
	reset_ope(a);
}

int		main(int ac, char **av)
{
	t_stack 	a;
	t_stack 	b;
	// static int	i = 0;

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
			// printf("[%d - %d]-[%d - %d]-[%d - %d]-[%d]-[%d]\n", a.must.ra, a.must.rb, a.must.rra, a.must.rrb, a.must.rr, a.must.rrr, a.must.nb_ope, a.must.value);
			// exit(0);
			while (a.len > 3)
			{
				main_algo(&a, &b);
				// printf(LBLU"[%d]\n"RESET"must=[%d - %d]-[%d - %d]-[%d - %d]-[%d]-[%d]\ntcmp=[%d - %d]-[%d - %d]-[%d - %d]-[%d]-[%d]\nmaxa=[%d]-[%d]-[%d]\nmaxb=[%d]-[%d]\n",
				// 	i, a.must.ra, a.must.rb, a.must.rra, a.must.rrb, a.must.rr, a.must.rrr, a.must.nb_ope, a.must.value, a.to_cmp.ra, a.to_cmp.rb, a.to_cmp.rra, a.to_cmp.rrb, a.to_cmp.rr, a.to_cmp.rrr, a.to_cmp.nb_ope, a.to_cmp.value,
				// 	a.max, a.max2, a.max3, b.max, b.min);
				// if (i == 10)
				// 	exit(0);
				// i++;
			}
			// printf("[%d - %d]-[%d - %d]-[%d - %d]-[%d]-[%d]\n", a.must.ra, a.must.rb, a.must.rra, a.must.rrb, a.must.rr, a.must.rrr, a.must.nb_ope, a.must.value);
			// exit(0);
			finisher(&a, &b);
		}
		else
			printf("Error\n");
	}
	return (0);
}
