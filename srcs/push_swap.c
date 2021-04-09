#include <pcswap.h>

int		parsing_arg(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (!av[i])
			return (0);
		j = 0;
		while (av[i][j])
		{
			if (!atoi_spe(av[i]))
				return (0);
			// while (av[i][j] == ' ' && av[i][j] == '\t')
				// j++;
			// if (next_char())
		}
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stack 	a;
	t_stack 	b;
	t_pile		pile;
	t_opfcmp	must;
	t_opfcmp	to_cmp;

	if (ac > 1)
	{
		if (parsing_arg(av))
		{
			
		}
		return (0);
	}
	printf("Error\n");
	return (0);
}
