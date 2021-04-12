#include <pcswap.h>

void        rotate_sta(t_stack *a)
{
    t_pile  *tmp;
    t_pile  *tmp2;

    if (a->first == NULL || a->len < 2)
        return ;
    tmp = a->first;
    tmp2 = tmp->next;
    // printf(LRED"\t[%d]\n"RESET, tmp->nb);
    while (a->first->next)
        a->first = a->first->next;
    a->first->next = tmp;
    tmp->next = NULL;
    a->first = tmp2;
    // printf(RED"\t[%d]\n"RESET, a->first->nb);
}

void        rotate_stb(t_stack *b)
{
    t_pile  *tmp;
    t_pile  *tmp2;

    if (b->first == NULL || b->len < 2)
        return ;
    tmp = b->first;
    tmp2 = tmp->next;
    while (b->first->next)
        b->first = b->first->next;
    b->first->next = tmp;
    tmp->next = NULL;
    b->first = tmp2;
}

void        rev_rotate_sta(t_stack *a)
{
    t_pile  *tmp;
    t_pile  *tmp2;

    if (a->first == NULL || a->len < 2)
        return ;
    tmp = a->first;
    while (a->first->next->next)
        a->first = a->first->next;
    tmp2 = a->first->next;
    a->first->next = NULL;
    tmp2->next = tmp;
    a->first = tmp2;
}

void        rev_rotate_stb(t_stack *b)
{
    t_pile  *tmp;
    t_pile  *tmp2;

    if (b->first == NULL || b->len < 2)
        return ;
    tmp = b->first;
    while (b->first->next->next)
        b->first = b->first->next;
    tmp2 = b->first->next;
    b->first->next = NULL;
    tmp2->next = tmp;
    b->first = tmp2;
}
