#include "ft_printf_private.h"

void	ft_printf_parse_octal(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	inst->out->addo(inst->out, va_arg(inst->args, int));
}