#include <pcswap.h>

void		print_stacks(t_stack *a, t_stack *b)
{
	t_pile	*tmpa;
	t_pile	*tmpb;

	tmpa = a->first;
	tmpb = b->first;
	if (a->must.bonus_v == 0)
		 return ;
	printf(GREY"---------------------------\n"RESET);
	printf(GREY"\t| "RESET ITAL SOUL CYAN"stack A" RESET GREY" |\n"RESET);
	printf(GREY"---------------------------\n"RESET);
	while (tmpa)
	{
		printf(ORA"\t[%d]\n"RESET, tmpa->nb);
		tmpa = tmpa->next;
	}
	printf(GREY"------------------------\n"RESET);
	printf(GREY"\t| "RESET ITAL SOUL CYAN"stack B" RESET GREY" |\n"RESET);
	printf(GREY"---------------------------\n"RESET);
	while (tmpb)
	{
		printf(MAG"\t[%d]\n"RESET, tmpb->nb);
		tmpb = tmpb->next;
	}
	printf(GREY"---------------------------\n"RESET);
}
