#include <pcswap.h>

/*
**	Ope swap and push for both stacks
*/

void		swap_sta(t_stack *a)
{
    // t_pile  *tmp;
    // t_pile  *tmp2;
    // int     nb[2];
    int     tmp;

    if (a == NULL || a->len < 2)
        return ;
    tmp = a->first->next->nb;
    a->first->next->nb = a->first->nb;
    a->first->nb = tmp;
    // tmp = a->first;
    // tmp2 = tmp->next;
    // nb[0] = tmp->nb;
    // nb[1] = tmp2->nb;
    // tmp2->nb = nb[0];
    // tmp->nb = nb[1];
    // a->first = tmp;
}

void		swap_stb(t_stack *b)
{
    t_pile  *tmp;
    t_pile  *tmp2;
    int     nb[2];

    if (b == NULL || b->len < 2)
        return ;
    tmp = b->first;
    tmp2 = tmp->next;
    nb[0] = tmp->nb;
    nb[1] = tmp2->nb;
    tmp2->nb = nb[0];
    tmp->nb = nb[1];
    b->first = tmp;
}

/*
**  Push first elem Stack B to Stack A
*/

void		push_sta(t_stack *a, t_stack *b)
{
    t_pile  *tmp;
    // t_pile  *tmp2 = NULL;

    if (b == NULL)
        return ;
    tmp = b->first->next;
    b->first->next = a->first;
    a->first = b->first;
    b->first = tmp;
    // tmp = b->first;
    // tmp2 = ft_create_list(tmp->nb, tmp2, a->len + 1);
    // tmp2->next = a->first;
    // a->first = tmp2;
    // b->first = tmp->next;
    // free(tmp);
    // tmp = NULL;
    b->len--;
    a->len++;
}

/*
**  Push first elem Stack A to Stack B
*/

void		push_stb(t_stack *a, t_stack *b)
{
    t_pile  *tmp;
    // t_pile  *tmp2 = NULL;

    if (a == NULL)
        return ;
    tmp = a->first->next;
    a->first->next = b->first;
    b->first = a->first;
    a->first = tmp;
    a->len--;
    b->len++;
}
