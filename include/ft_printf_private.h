#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <stdarg.h>
# include "ft_printf.h"
# include "ft_string.h"
# include "ft_sstream.h"

typedef struct s_printf		t_printf;
typedef struct s_printf_opt	t_printf_opt;

struct			s_printf_opt
{
	char		*ident;
	size_t		size;
	void		(*parse)(void);
};

struct			s_printf
{
	va_list		args;
	const char	*str;
	size_t		last_index;
	size_t		index;
	size_t		size;
	size_t		minus_ret_size;
	t_sstream	*out;
};

t_printf		*ft_printf_instance(void);
void			ft_printf_dispatch_arg(void);
void			ft_printf_next(void);
void			ft_printf_parse_string(void);
void			ft_printf_parse_wstring(void);
void			ft_printf_parse_pointer(void);
void			ft_printf_parse_int(void);
void			ft_printf_parse_longint(void);
void			ft_printf_parse_octal(void);
void			ft_printf_parse_longoctal(void);

#endif