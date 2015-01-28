#include "ft_printf_private.h"

void	ft_printf_parse_uintmaxhexa(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	ft_printf_add_hexa(va_arg(inst->args, uintmax_t));
}