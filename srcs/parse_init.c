/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:38:25 by jmercier          #+#    #+#             */
/*   Updated: 2021/12/10 07:58:13 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

static int	last_check(t_stack *a)
{
	t_pile	*tmp1;
	t_pile	*tmp2;

	tmp1 = a->first;
	while (tmp1)
	{
		tmp2 = a->first;
		while (tmp2)
		{
			if ((tmp1->index != tmp2->index) && (tmp1->nb == tmp2->nb))
			{
				free_stack(a);
				return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

static int	set_stacks2(t_stack *a, char **arg, int i, int j)
{
	t_pile	*tmp;
	t_pile	*ftmp;
	long	nb_tmp;

	tmp = NULL;
	ftmp = a->first;
	nb_tmp = ft_atoi(arg[i] + j);
	if (nb_tmp == 0 && (arg[i][j] != '0' && arg[i][j + 1] != '0'))
		return (1);
	if (nb_tmp > INT_MAX || nb_tmp < INT_MIN)
		return (free_stack(a));
	tmp = ft_create_list(ft_atoi(arg[i] + j), tmp, a->len);
	if (a->first == NULL)
		a->first = tmp;
	else
	{
		while (a->first->next != NULL)
			a->first = a->first->next;
		a->first->next = tmp;
		a->first = ftmp;
	}
	tmp = NULL;
	a->len++;
	return (1);
}

int	set_stacks(t_stack *a, char **arg, int ac)
{
	int		i;
	int		j;

	i = (1 + a->must.bonus_v);
	while ((ac - 1) >= i)
	{
		j = 0;
		while (arg[i][j])
		{
			while ((arg[i][j] >= 9 && arg[i][j] <= 13) || arg[i][j] == 32)
				j++;
			if (!set_stacks2(a, arg, i, j))
				return (0);
			if (arg[i][j] == '-' || arg[i][j] == '+')
				j++;
			if (arg[i][j] == '-' || arg[i][j] == '+' || !arg[i][j])
				return (free_stack(a));
			while ((arg[i][j] >= '0' && arg[i][j] <= '9'))
				j++;
		}
		i++;
	}
	return (last_check(a));
}

int	parsing_at_onion(const char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] >= 9 && str[i] <= 13)
			&& str[i] != ' ' && str[i] != '-' && str[i] != '+')
			return (0);
		if ((str[i] >= '0' && str[i] <= '9')
			&& (str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		i++;
	}
	return (1);
}

int	parsing_arg(char **av, int bonus)
{
	int	i;
	int	j;

	i = 1 + bonus;
	while (av[i])
	{
		if (!av[i])
			return (0);
		j = 0;
		while (av[i][j])
		{
			if (!parsing_at_onion(av[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
