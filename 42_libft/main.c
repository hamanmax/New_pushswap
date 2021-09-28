#include "include/libft.h"
#include "limits.h"

int ft_isnbr(int argc, char **argv)
{
	char *str;

	str = argv[argc - 1];
	while (argc - 1 >= 1)
	{
		while (*str >= '0' && *str <= '9' || *str == '-' || *str == ' ')
		{
			str++;
		}
		if (*str == 0 && (argc - 1) > 1)
		{
			argc--;
			str = argv[argc - 1];
		}
		else if (*str == 0 && argc - 1 == 0)
			return (1);
		else
			return (0);
	}
	return (12);
}

typedef struct s_pile t_pile;
typedef struct s_pile
{
	t_pile	*prev;
	int		value;
	t_pile	*next;
}		t_pile;

int main(int argc, char **argv)
{
	int i;
	long d;

	//printf("%ld\t%ld\n",(long)i,d);
	printf("%ld\n",ft_atol("-2147483649"));
	printf("%d\n",ft_atoi("-2147483649"));
	if (i == d)
	{
		puts("tutu");
	}
	//ft_printf("%d\n", i);
}