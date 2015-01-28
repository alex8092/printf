#include "ft_printf_private.h"

void	ft_printf_parse_longlong(void)
{
	static t_printf		*inst = 0;
	long long			value;

	if (!inst)
		inst = ft_printf_instance();
	value = va_arg(inst->args, long long);
	ft_printf_add_number(value);
}