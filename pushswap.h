#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct s_list t_list;

typedef struct s_data
{
	int value;
	int chunk;
}				t_data;

struct s_list
{
	t_list *prev;
	t_list *next;
	t_data data;
};




#endif