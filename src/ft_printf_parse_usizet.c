#include "ft_printf_private.h"

void	ft_printf_parse_usizet(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	ft_printf_add_unumber(va_arg(inst->args, size_t));
}