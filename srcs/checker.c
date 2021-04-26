/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:17:44 by jmercier          #+#    #+#             */
/*   Updated: 2021/04/26 01:18:18 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

static int	check_order(t_stack *a)
{
	t_pile	*tmp;

	tmp = a->first;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	just_do_it2(t_stack *a, t_stack *b, char *line)
{
	int					ind;
	const static char	*instruct[] = {"pa", "pb", "ss",
										"rr", "rrr", NULL};
	static t_op_both	*stack_both[] = {
		&push_sta, &push_stb, &suit_swap,
		&suit_rotate, suit_rot_reverse,
	};

	ind = 0;
	while (instruct[ind])
	{
		if (!ft_strcmp(instruct[ind], line))
		{
			stack_both[ind](a, b);
			return (1);
		}
		else
			ind++;
	}
	return (0);
}

static int	just_do_it(t_stack *a, t_stack *b, char *line)
{
	int						ind;
	const static char		*instruct[] = {"sa", "ra", "rra", "sb",
	"rb", "rrb", NULL};
	static t_op_stack		*only_stack[] = {
		&swap_sta, &rotate_sta, &rev_rotate_sta,
		&swap_stb, &rotate_stb, &rev_rotate_stb,
	};

	ind = 0;
	while (instruct[ind])
	{
		if (!ft_strcmp(instruct[ind], line))
		{
			if (ind >= 0 && ind <= 2)
				only_stack[ind](a);
			else if (ind >= 3 && ind <= 5)
				only_stack[ind](b);
			return (1);
		}
		else
			ind++;
	}
	return (just_do_it2(a, b, line));
}

static int	read_stdin(t_stack *a, t_stack *b)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!just_do_it(a, b, line))
		{
			free(line);
			free_stack(a);
			free_stack(b);
			return (0);
		}
		free(line);
	}
	free(line);
	line = NULL;
	if (b->len == 0 && check_order(a))
		printf("OK\n");
	else
		printf("KO\n");
	return (1);
}

int			main(int ac, char **av)
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
			if (!read_stdin(&a, &b))
			{
				printf("Error\n");
				free_stack(&a);
				free_stack(&b);
				return (0);
			}
		}
		else
			printf("Error\n");
	}
	return (0);
}
