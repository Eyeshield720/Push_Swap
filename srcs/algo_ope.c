#include <pcswap.h>

static void push_b3max(t_stack *a, t_stack *b)
{
    int     i;

    i = 0;
    while (i < 2)
    {
        if ((a->first->nb == a->max || a->first->nb == a->max2)
			|| ((a->first->nb == a->max3) && (a->len > 4)))
        {
            rotate_sta(a);
            printf("ra\n");
            print_stacks(a, b);
        }
        else
        {
            push_stb(a, b);
            printf("pb\n");
            print_stacks(a, b);
            i++;
        }
    }
    if (b->first->nb < b->first->next->nb)
    {
        swap_stb(b);
        printf("sb\n");
        print_stacks(a, b);
    }
}


static void short_opesta2(t_stack *a, t_stack *b)
{
	if (a->first->nb == a->max && a->first->next->nb == a->max2)
	{
		rotate_sta(a);
		printf("ra\n");
		print_stacks(a, b);
		swap_sta(a);
		printf("sa\n");
		print_stacks(a, b);
	}
	else if (a->first->nb == a->max && a->first->next->nb == a->max3)
	{
		rotate_sta(a);
		printf("ra\n");
		print_stacks(a, b);
	}
	else if (a->first->nb == a->max2 && a->first->next->nb == a->max)
	{
		rev_rotate_sta(a);
		printf("rra\n");
		print_stacks(a, b);
	}
}

void	    short_opesta(t_stack *a, t_stack *b)
{
	if (a->first->nb == a->max2 && a->first->next->nb == a->max3)
	{
		swap_sta(a);
		printf("sa\n");
		print_stacks(a, b);
	}
	else if (a->first->nb == a->max3 && a->first->next->nb == a->max)
	{
		rev_rotate_sta(a);
		printf("rra\n");
		print_stacks(a, b);
		swap_sta(a);
		printf("sa\n");
		print_stacks(a, b);
	}
	else
		short_opesta2(a, b);
}

int		second_sort(t_stack *a, t_stack *b)
{
	if (a->len == 2)
	{
		sort_3max(a);
		swap_sta(a);
		printf("sa\n");
		print_stacks(a, b);
		final_sort(a, b);
		return (0);
	}
	if (a->len == 3)
	{
		sort_3max(a);
		short_opesta(a, b);
		final_sort(a, b);
		return(0);
	}
	return (1);
}

int		first_sort(t_stack *a, t_stack *b)
{
	if (!check_first_stack(a) || !begin_sort1(a, b))
		return (0);
	if (a->len < 2)
		return (0);	
	if (a->len == 2)
	{
		if (a->first->nb > a->first->next->nb)
		{
			swap_sta(a);
			printf("sa\n");
			print_stacks(a, b);
		}
		return (0);
	}
	find_trio(a);
	if (a->len == 3)
	{
		sort_3max(a);
		short_opesta(a, b);
		return (0);
	}
    push_b3max(a, b);
	return (1);
}
