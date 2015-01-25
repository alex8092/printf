#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <stdarg.h>
# include "ft_printf.h"
# include "ft_string.h"
# include "ft_sstream.h"

typedef struct s_printf			t_printf;
typedef struct s_printf_opt		t_printf_opt;
typedef struct s_printf_flag	t_printf_flag;

struct			s_printf_opt
{
	char		*ident;
	size_t		size;
	void		(*parse)(void);
};

struct			s_printf_flag
{
	char		ident;
	t_bool		active;
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
void			ft_printf_get_size(void);
void			ft_printf_get_precision(void);
void			ft_printf_dispatch_arg(void);
void			ft_printf_next(void);
void			ft_printf_get_flags(void);
t_bool			ft_printf_has_flag(char c);
void			ft_printf_disable_flag(char c);
void			ft_printf_reset_flags(void);
void			ft_printf_parse_string(void);
void			ft_printf_parse_wstring(void);
void			ft_printf_parse_pointer(void);
void			ft_printf_parse_int(void);
void			ft_printf_parse_longint(void);
void			ft_printf_parse_octal(void);
void			ft_printf_parse_longoctal(void);
void			ft_printf_parse_unsigned(void);
void			ft_printf_parse_longunsigned(void);
void			ft_printf_parse_hexa(void);
void			ft_printf_parse_longhexa(void);
void			ft_printf_parse_upperhexa(void);
void			ft_printf_parse_char(void);
void			ft_printf_parse_wchar(void);

#endif
