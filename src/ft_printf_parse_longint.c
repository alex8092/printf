#include "ft_printf_private.h"

void	ft_printf_parse_longint(void)
{
	static t_printf		*inst = 0;
	long int			value;

	if (!inst)
		inst = ft_printf_instance();
	value = va_arg(inst->args, long int);
	ft_printf_add_number(value);
}