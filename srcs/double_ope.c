#include <pcswap.h>

void        suit_swap(t_stack *a, t_stack *b)
{
    swap_sta(a);
    swap_stb(b);
}

void        suit_rotate(t_stack *a, t_stack *b)
{
    rotate_sta(a);
    rotate_stb(b);
}

void        suit_rot_reverse(t_stack *a, t_stack *b)
{
    rev_rotate_sta(a);
    rev_rotate_stb(b);
}