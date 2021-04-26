/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcswap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmercier <jmercier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 05:40:02 by jmercier          #+#    #+#             */
/*   Updated: 2021/04/26 05:44:18 by jmercier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PCSWAP_H
# define PCSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 64

# define BLACK "\033[30m"
# define GREY "\033[1;30m"
# define RED "\033[31m"
# define LRED "\033[1;31m"
# define GREN "\x1B[32m"
# define LGREN "\033[1;32m"
# define YEL "\x1B[33m"
# define LYEL "\033[1;33m"
# define BLU "\x1B[34m"
# define LBLU "\033[1;34m"
# define MAG "\x1B[35m"
# define LMAG "\033[1;35m"
# define CYAN "\x1B[36m"
# define WHITE "\033[1;37m"
# define RES "\x1B[0m"
# define BGREY "\033[100m"
# define BYOLO "\033[103m"
# define BBLU "\033[104m"
# define SOUL "\033[4m"
# define ITAL "\033[3m"
# define ORA "\033[38;5;222m"
# define LORA "\033[1m\033[38;5;222m"

typedef struct		s_pile
{
	int				nb;
	int				index;
	struct s_pile	*next;
}					t_pile;

typedef struct		s_opcmp
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				rr;
	int				rrr;

	int				ind;
	int				value;
	int				check;

	int				tmp_ra;
	int				tmp_rb;
	int				tmp_rra;
	int				tmp_rrb;
	int				nb_ope;

	unsigned short	bonus_v:1;
	unsigned short	fb_ra:1;
	unsigned short	fb_rr:1;
	unsigned short	fb_rrr:1;
	unsigned short	fb_remain:12;
}					t_opcmp;

typedef struct		s_stack
{
	int				len;
	int				max;
	int				max2;
	int				max3;
	int				min;
	int				diff;
	int				pos;
	t_opcmp			must;
	t_opcmp			to_cmp;
	struct s_pile	*first;
}					t_stack;

typedef void		(t_op_stack)(t_stack *a);
typedef void		(t_op_both)(t_stack *a, t_stack *b);

/*
**		Push_Swap & Checker algo
*/

int					begin_sort1(t_stack *a, t_stack *b);
void				begin_sort2(t_stack *a, t_stack *b);

int					first_sort(t_stack *a, t_stack *b);
int					second_sort(t_stack *a, t_stack *b);
void				sort_3max(t_stack *a);
void				manage_3max(t_stack *a, t_pile *tmp, int nb_tmp, int i);
void				short_opesta(t_stack *a, t_stack *b);
int					start_move(t_stack *a, t_stack *b);

void				find_maxb(t_stack *b, t_opcmp *op);
void				find_extrstb(t_stack *b, t_opcmp *op);

void				rev_sortb(t_stack *a, t_stack *b);
void				final_sort(t_stack *a, t_stack *b);
void				main_algo(t_stack *a, t_stack *b);
void				feel_worth_it(t_stack *a, t_stack *b);
void				plan_must(t_stack *b, t_opcmp *op);
void				how_muchop1(t_opcmp *op);
void				worth_it_cmp(t_stack *a, t_stack *b);
void				worth_swapping(t_stack *a);
void				worth_move(t_stack *a, t_stack *b);
void				reset_ope(t_stack *a);
void				finisher(t_stack *a, t_stack *b);

void				print_stacks(t_stack *a, t_stack *b);

void				swap_sta(t_stack *a);
void				swap_stb(t_stack *b);
void				push_stb(t_stack *a, t_stack *b);
void				push_sta(t_stack *a, t_stack *b);

void				rotate_sta(t_stack *a);
void				rotate_stb(t_stack *b);
void				rev_rotate_sta(t_stack *a);
void				rev_rotate_stb(t_stack *b);

void				suit_swap(t_stack *a, t_stack *b);
void				suit_rotate(t_stack *a, t_stack *b);
void				suit_rot_reverse(t_stack *a, t_stack *b);

/*
**	Parsing & Init Stacks
*/

int					parsing_arg(char **av, int bonus);
int					parsing_at_onion(const char *str);
int					set_stacks(t_stack *a, char **arg, int ac);
int					check_first_stack(t_stack *a);
void				find_trio(t_stack *a);

/*
**	Utils
*/

char				*ft_itoa(int n);
long				ft_atoi(const char *str);
int					ft_count(int num);
int					ft_strlen(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isdigit(int c);
int					ft_strcmp(const char *s1, const char *s2);

t_pile				*ft_create_list(int nb, t_pile *pile, int i);
void				free_stack(t_stack *random);

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
char				*ft_strcpy(char *dest, char *src);
int					get_next_line(int const fd, char **line);

#endif
