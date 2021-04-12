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
	// printf("max=[%d]\nmax2=[%d]\nmax3=[%d]\n", a->max, a->max2, a->max3);
}

void	manage_3max(t_stack *a, t_pile *tmp, int nb_tmp, int i)
{
	int		tab[3];

	// printf("max=[%d]\nmax2=[%d]\nmax3=[%d]\n", a->max, a->max2, a->max3);
	tmp = tmp->next;
	a->max2 = tmp->nb;
	tmp = tmp->next;
	a->max3 = tmp->nb;
	// printf("max=[%d]\nmax2=[%d]\nmax3=[%d]\n", a->max, a->max2, a->max3);
	tab[0] = a->max;
	tab[1] = a->max2;
	tab[2] = a->max3;
	while (i < 2)
	{
		// printf("%d\n", i);
		if (tab[i] < tab[i + 1])
		{
			// printf("%d=[%d]-i+1=[%d]\n", i, tab[i], tab[i+1]);
			nb_tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = nb_tmp;
			// printf("tab=[%d]\ntab2=[%d]\ntab3=[%d]\n", tab[0], tab[1], tab[2]);
			i = -1;
		}
		i++;
	}
	a->max = tab[0];
	a->max2 = tab[1];
	a->max3 = tab[2];
	// printf("max=[%d]\nmax2=[%d]\nmax3=[%d]\n", a->max, a->max2, a->max3);
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
