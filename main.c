//#include "pushswap.h"
#include "42_libft/include/libft.h"

int check_arg_format(int argc,char **argv)
{
	int i;
	char *str;

	i = argc - 1;
	str = argv[i];
	while (i >= 1)
	{
		if (*str >= '0' && *str <= '9' || *str == ' ' || *str == '-')
		{
			str++;
			printf("str - 1 = %c\n",*(str - 1));
			printf("str = %c\n",*str);
			if (*(str - 1) == '-' && (*str < '0' || *str > '9'))
				return (-1);
		}
		else if (*str == 0)
			i--;
		else
		{
			ft_printf("ERROR\n");
			return (-1);
		}
	}
	if (argc < 1)
	{
			ft_printf("ERROR NO ARG\n");
	}
	return (1);
}



int main(int argc,char **argv)
{
	//printf("%ld\n",ft_atol("--------------125"));
	if (check_arg_format(argc,argv) == -1);
		return (-1);
}