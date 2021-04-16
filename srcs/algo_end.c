#include <pcswap.h>

void		find_maxb(t_stack *b, t_opcmp *op)
{
	t_pile	*tmp;

	tmp = b->first;
	b->max = tmp->nb;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (b->max < tmp->nb)
		{
			b->max = tmp->nb;
		}
	}
	tmp = b->first;
	op->ind = 1;
	while (b->max != tmp->nb)
	{
		op->ind++;
		tmp = tmp->next;
	}
}

void		rev_sortb(t_stack *a, t_stack *b)
{
	find_maxb(b, &a->must);
	if (a->must.ind < b->len / 2)
	{
		while (b->first->nb != b->max)
		{
			rotate_stb(b);
			printf("rb\n");
			print_stacks(a, b);
		}
	}
	else
	{
		while (b->first->nb != b->max)
		{
			rev_rotate_stb(b);
			printf("rrb\n");
			print_stacks(a, b);
		}
	}
	
}

void		final_sort(t_stack *a, t_stack *b)
{
	rev_sortb(a, b);
	while (b->len > 0)
	{
		push_sta(a, b);
		printf("pa\n");
		print_stacks(a, b);
		if (b->len > 0)
			rev_sortb(a, b);
	}
}