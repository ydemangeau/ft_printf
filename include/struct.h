#ifndef STRUCT_H
# define STRUCT_H

#include "printf.h"

typedef struct	s_flag
{
	int			sign;//+
	int			justify;//-
	int			prefix;//#
	int			pad_zero;//0
	int			space;// ' '
}				t_flag;

typedef enum	s_lenght
{
	none,
	h,
	hh,
	l,
	ll
}				t_lenght;

typedef struct	s_handler
{
	int			field_width;
	int			precision;
	t_lenght	lenght;
	t_flag		flags;
}				t_handler;

#endif