#include <pcswap.h>

static void	clean_rotateop(t_opcmp *op, int res)
{
	op->fb_ra = 0;
	op->fb_rr = 1;
	op->fb_rrr = 0;
	op->nb_ope = res;
	op->ra = op->tmp_ra;
	op->rb = op->tmp_rb;
}

static void	clean_rev_rotateop(t_opcmp *op, int res)
{
	op->fb_ra = 0;
	op->fb_rr = 0;
	op->fb_rrr = 1;
	op->nb_ope = res;
	op->rra = op->tmp_rra;
	op->rrb = op->tmp_rrb;
}

void		how_muchop2(t_opcmp *op)
{
	if (op->ra <= op->rra && op->rb <= op->rrb)
		op->nb_ope = op->ra + op->rb;
	else if (op->ra >= op->rra && op->rb <= op->rrb)
		op->nb_ope = op->rra + op->rb;
	else if (op->ra >= op->rra && op->rb >= op->rrb)
		op->nb_ope = op->rra + op->rrb;
	else if (op->ra <= op->rra && op->rrb <= op->rb)
		op->nb_ope = op->ra + op->rrb;
	op->fb_ra = 1;
	op->tmp_ra = op->ra;
	op->tmp_rb = op->rb;
	while (op->tmp_ra > 0 && op->tmp_rb > 0)
	{
		op->rr++;
		op->tmp_ra--;
		op->tmp_rb--;
	}
	op->tmp_rra = op->rra;
	op->tmp_rrb = op->rrb;
	while (op->tmp_rra > 0 && op->tmp_rrb > 0)
	{
		op->rrr++;
		op->tmp_rra--;
		op->tmp_rrb--;
	}
}

void		how_muchop1(t_opcmp *op)
{
	int		res;

	res = 0;
	how_muchop2(op);
	if ((op->rr + op->tmp_ra + op->tmp_rb < op->rrr + op->tmp_rra + op->tmp_rrb) ||
		((op->rr != 0 && op->rr == op->rrr) &&
		(op->tmp_ra + op->tmp_rb < op->tmp_rra + op->tmp_rrb)))
	{
		res = op->rr + op->tmp_ra + op->tmp_rb;
		if (res < op->nb_ope)
			clean_rotateop(op, res);
	}
	else if ((op->rr + op->tmp_ra + op->tmp_rb > op->rrr + op->tmp_rra + op->tmp_rrb) ||
		((op->rr != 0 && op->rr == op->rrr) &&
		(op->tmp_ra + op->tmp_rb > op->tmp_rra + op->tmp_rrb)))
	{
		res = op->rrr + op->tmp_rra + op->tmp_rrb;
		if (res < op->nb_ope)
			clean_rev_rotateop(op, res);
	}
}


