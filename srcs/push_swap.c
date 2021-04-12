#include <pcswap.h>

int		start_move(t_stack *a, t_stack *b)
{
	if (!first_sort(a, b))
	{
		if (a->must.bonus_v == 1)
			print_stacks(a, b);
		free_stack(a);
		free_stack(b);
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stack 	a;
	t_stack 	b;

	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	if (ac > 1)
	{
		if (!ft_strcmp(av[1], "-v"))
			a.must.bonus_v = 1;
		if (parsing_arg(av, a.must.bonus_v))
		{
			if (!set_stacks(&a, av))
			{
				printf("Error\n");
				return (0);
			}
			// print_stacks(&a, &b);
			if (!start_move(&a, &b))
				return (0);
			free_stack(&a);
			// free_stack(&b);
		}
		return (1);
	}
	return (0);
}
