#include <pcswap.h>

void		find_extrstb(t_stack *a, t_stack *b)
{
	t_pile	*tmp;

	tmp = b->first;
	b->min = tmp->nb;
	find_maxb(b, &a->must);
	while (tmp)
	{
		tmp = tmp->next;
		if (b->min < tmp->nb)
			b->min = tmp->nb;
	}
}

static int		plan_must2b(t_stack *b, t_opcmp *op)
{
	if ((op->ind == 1 && op->value > b->max) ||
		(op->value < b->min && b->first->nb == b->max))
		return (0);
	else if (op->ind < b->len / 2)
	{
		while (op->ind > 1)
		{
			op->rb++;
			op->ind--;
		}
		op->rrb = b->len - op->rb;
	}
	else
	{
		while (op->ind < b->len + 1)
		{
			op->rrb++;
			op->ind++;
		}
		op->rb = b->len - op->rrb;
	}
	return (0);
}

void			plan_must(t_stack *b, t_opcmp *op)
{
	int		ind;
	t_pile	*tmp1;
	t_pile	*tmp2;

	find_maxb(b, op);
	if (op->value > b->max || op->value < b->min)
		if (!plan_must2b(b, op))
			return ;
	ind = 0;
	tmp1 = b->first;
	tmp2 = b->first;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
		ind++;
		if (op->value > tmp1->nb && op->value < tmp2->nb)
		{
			op->rb += ind;
			op->rrb = b->len - op->rb;
			break ;
		}
		tmp2 = tmp2->next;
	}
}

static void		worth_it_cmp2(t_stack *a, t_stack *b)
{
	a->to_cmp.rra = a->len - a->to_cmp.ra;
	plan_must(b, &a->to_cmp);
	how_muchop1(&a->to_cmp);
	worth_swapping(a);
	a->to_cmp.ra = 0;
	a->to_cmp.rb = 0;
	a->to_cmp.rra = 0;
	a->to_cmp.rrb = 0;
	a->to_cmp.rr = 0;
	a->to_cmp.rrr = 0;
	a->to_cmp.nb_ope = 0;
}

void			worth_it_cmp(t_stack *a, t_stack *b)
{
	int		ind;
	t_pile	*tmp;

	tmp = a->first;
	ind = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		a->to_cmp.value = tmp->nb;
		ind++;
		a->to_cmp.ra = ind;
		while (a->to_cmp.value == a->max || a->to_cmp.value == a->max2
				|| a->to_cmp.value == a->max3)
		{
			tmp = tmp->next;
			ind++;
			if (!tmp)
				return ;
			a->to_cmp.value = tmp->nb;
			a->to_cmp.ra = ind;
		}
		worth_it_cmp2(a, b);
	}
}
