#include <pcswap.h>

void	find_trio(t_stack *a)
{
	t_pile	*tmp;

	tmp = a->first;
	a->max = tmp->nb;
	while (tmp)
	{
		if (a->max < tmp->nb)
		{
			a->max = tmp->nb;
			tmp = a->first;
		}
		if (a->max2 < tmp->nb && a->max2 < a->max && a->max != tmp->nb)
		{
			a->max2 = tmp->nb;
			tmp = a->first;
		}
		if (a->max3 < tmp->nb && a->max3 < a->max2
				&& a->max != tmp->nb && a->max2 != tmp->nb)
		{
			a->max3 = tmp->nb;
			tmp = a->first;
		}
		tmp = tmp->next;
	}
}

void	manage_3max(t_stack *a, t_pile *tmp, int nb_tmp, int i)
{
	int		tab[3];

	tmp = tmp->next;
	a->max2 = tmp->nb;
	tmp = tmp->next;
	a->max3 = tmp->nb;
	tab[0] = a->max;
	tab[1] = a->max2;
	tab[2] = a->max3;
	while (i < 2)
	{
		if (tab[i] < tab[i + 1])
		{
			nb_tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tab[i];
			i = -1;
		}
		i++;
	}
	a->max = tab[0];
	a->max2 = tab[1];
	a->max3 = tab[2];
}

void	sort_3max(t_stack *a)
{
	t_pile	*tmp;
	int		nb_tmp;

	tmp = a->first;
	a->max = tmp->nb;
	if (a->len == 3)
		manage_3max(a, tmp, 0, 0);
	if (a->len == 2)
	{
		tmp = tmp->next;
		a->max2 = tmp->nb;
		if (a->max < a->max2)
		{
			nb_tmp = a->max;
			a->max = a->max2;
			a->max2 = nb_tmp;
		}
	}
}
