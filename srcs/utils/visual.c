/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 01:48:37 by jmercier          #+#    #+#             */
/*   Updated: 2021/04/26 01:57:16 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pcswap.h>

static void	synchro_stacks(t_stack *a, t_stack *b)
{
	t_pile	*tmpa;
	t_pile	*tmpb;

	tmpa = a->first;
	tmpb = b->first;
	while (tmpa || tmpb)
	{
		if (tmpa != NULL)
		{
			printf(ORA"\t[%d]\r\t\t\t\t"RES, tmpa->nb);
			if (tmpb == NULL)
				printf("\n");
			tmpa = tmpa->next;
		}
		if (tmpb != NULL)
		{
			if (tmpa == NULL)
				printf("\r\t\t\t\t");
			printf(MAG"\t[%d]\n"RES, tmpb->nb);
			tmpb = tmpb->next;
		}
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_pile	*tmpa;
	t_pile	*tmpb;

	tmpa = a->first;
	tmpb = b->first;
	if (a->must.bonus_v == 0)
		return ;
	printf(GREY"-----------------------------\r\t\t\t\t"
		"-----------------------------\n"RES);
	printf(GREY"\t| "RES ITAL SOUL CYAN"stack A" RES GREY" |\r\t\t\t\t"RES);
	printf(GREY"\t| "RES ITAL SOUL CYAN"stack B" RES GREY" |\n"RES);
	printf(GREY"-----------------------------\r\t\t\t\t"
		"-----------------------------\n"RES);
	synchro_stacks(a, b);
	printf(GREY"-----------------------------\r\t\t\t\t"RES);
	printf(GREY"-----------------------------\n"RES);
}
