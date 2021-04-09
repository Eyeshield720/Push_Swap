#ifndef PCSWAP_H
# define PCSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

typedef struct		s_pile
{
	int				nb;
	struct s_elem	*next;
}					t_pile;

typedef struct		s_stack
{
	int				len;
	struct s_elem	*first;
	int				max;
	int				max2;
	int				max3;
	int				min;
	int				diff;
	int				pos;
}					t_stack;

typedef struct		s_opfcmp
{
	int				index;
	int				value;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;
	int				nb_ope;
	int				check;
	int				bonus_v; // == f
	int				i;
	int				j;
	int				k;
	int				l;
}					t_opfcmp;

/*
**
**		Push_Swap & Checker algo
**
*/



/*
**
**	Utils
**
*/

char		*ft_itoa(int n);
int			ft_atoi(const char *str);
int			ft_count(int num);
int			ft_strlen(char *str);
void		ft_bzero(void *s, size_t n);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char *set);
void		free_chartab(char **chartab);
int			ft_strcmp(const char *s1, const char *s2);

#endif