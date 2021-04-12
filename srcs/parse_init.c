#include <pcswap.h>

static int  last_check(t_stack *a)
{
    t_pile *tmp1;
    t_pile *tmp2;

    tmp1 = a->first;
    while (tmp1)
    {
        tmp2 = a->first;
        while (tmp2)
        {
            // printf("[%d]=[%d]\n", tmp1->nb, tmp2->nb);
            if ((tmp1->index != tmp2->index) &&
                (tmp1->nb == tmp2->nb || (tmp1->nb > INT_MAX || tmp1->nb < INT_MIN)))
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

int         set_stacks(t_stack *a, char **arg)
{
	t_pile	*tmp;
	int		i;
	int		j;

	i = 1 + a->must.bonus_v;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
            // printf(GREN"[%c]\n"RESET, arg[i][j]);
			while ((arg[i][j] >= 9 && arg[i][j] <= 13) || arg[i][j] == ' ')
				j++;
			tmp = ft_create_list(ft_atoi(arg[i] + j), tmp, a->len);
			tmp->next = a->first;
			a->first = tmp;
			tmp = NULL;
			a->len++;
            if (arg[i][j] == '-' || arg[i][j] == '+')
                j++;
            if (arg[i][j] == '-' || arg[i][j] == '+')
            {
                free_stack(a);
                return (0);
            }
			while ((arg[i][j] >= '0' && arg[i][j] <= '9'))
				j++;
		}
		i++;
	}
    if (!last_check(a))
        return (0);
    return (1);
}

int		    parsing_at_onion(const char *str)
{
	int			i;

	i = 0;
	while (str && str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(str[i] >= 9 && str[i] <= 13)
            && str[i] != ' ' && str[i] != '-' && str[i] != '+')
			return (0);
		if ((str[i] >= '0' && str[i] <= '9') && str[i + 1] == '-' && str[i + 1] == '+')
			return (0);
		i++;
	}
	return (1);
}

int		parsing_arg(char **av, int bonus)
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
