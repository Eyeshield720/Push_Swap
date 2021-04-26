/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_ope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:19:03 by jmercier          #+#    #+#             */
/*   Updated: 2021/04/26 05:25:01 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

void		suit_swap(t_stack *a, t_stack *b)
{
	swap_sta(a);
	swap_stb(b);
}

void		suit_rotate(t_stack *a, t_stack *b)
{
	rotate_sta(a);
	rotate_stb(b);
}

void		suit_rot_reverse(t_stack *a, t_stack *b)
{
	rev_rotate_sta(a);
	rev_rotate_stb(b);
}
