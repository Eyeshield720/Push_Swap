#include <pcswap.h>

void		synchro_stacks(t_stack *a, t_stack *b)
{
	t_pile	*tmpa;
	t_pile	*tmpb;

	tmpa = a->first;
	tmpb = b->first;
	printf(GREY"-----------------------------\r\t\t\t\t""-----------------------------\n"RESET);
	printf(GREY"\t| "RESET ITAL SOUL CYAN"stack A" RESET GREY" |\r\t\t\t\t"RESET);
	printf(GREY"\t| "RESET ITAL SOUL CYAN"stack B" RESET GREY" |\n"RESET);
	printf(GREY"-----------------------------\r\t\t\t\t""-----------------------------\n"RESET);
	while (tmpa || tmpb)
	{
		if (tmpa != NULL)
		{
			printf(ORA"\t[%d]\r\t\t\t\t"RESET, tmpa->nb);
			if (tmpb == NULL)
				printf("\n");
			tmpa = tmpa->next;
		}
		if (tmpb != NULL)
		{
			if (tmpa == NULL)
				printf("\r\t\t\t\t");
			printf(MAG"\t[%d]\n"RESET, tmpb->nb);
			tmpb = tmpb->next;
		}
	}
	printf(GREY"-----------------------------\r\t\t\t\t"RESET);
	printf(GREY"-----------------------------\n"RESET);
}

void		print_stacks(t_stack *a, t_stack *b)
{
	t_pile	*tmpa;
	t_pile	*tmpb;

	tmpa = a->first;
	tmpb = b->first;
	if (a->must.bonus_v == 0)
		 return ;
	// printf(GREY"---------------------------\n"RESET);
	// printf(GREY"\t| "RESET ITAL SOUL CYAN"stack A" RESET GREY" |\n"RESET);
	// printf(GREY"---------------------------\n"RESET);
	// while (tmpa)
	// {
	// 	printf(ORA"\t[%d]\n"RESET, tmpa->nb);
	// 	tmpa = tmpa->next;
	// }
	// printf(GREY"---------------------------\n"RESET);
	// printf(GREY"\t| "RESET ITAL SOUL CYAN"stack B" RESET GREY" |\n"RESET);
	// printf(GREY"---------------------------\n"RESET);
	// while (tmpb)
	// {
	// 	printf(MAG"\t[%d]\n"RESET, tmpb->nb);
	// 	tmpb = tmpb->next;
	// }
	// printf(GREY"---------------------------\n"RESET);
	printf(GREY"-----------------------------\r\t\t\t\t""-----------------------------\n"RESET);
	printf(GREY"\t| "RESET ITAL SOUL CYAN"stack A" RESET GREY" |\r\t\t\t\t"RESET);
	printf(GREY"\t| "RESET ITAL SOUL CYAN"stack B" RESET GREY" |\n"RESET);
	printf(GREY"-----------------------------\r\t\t\t\t""-----------------------------\n"RESET);
	while (tmpa || tmpb)
	{
		if (tmpa != NULL)
		{
			printf(ORA"\t[%d]\r\t\t\t\t"RESET, tmpa->nb);
			if (tmpb == NULL)
				printf("\n");
			tmpa = tmpa->next;
		}
		if (tmpb != NULL)
		{
			if (tmpa == NULL)
				printf("\r\t\t\t\t");
			printf(MAG"\t[%d]\n"RESET, tmpb->nb);
			tmpb = tmpb->next;
		}
	}
	printf(GREY"-----------------------------\r\t\t\t\t"RESET);
	printf(GREY"-----------------------------\n"RESET);
}
