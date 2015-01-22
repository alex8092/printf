#include "ft_printf_private.h"

void	ft_printf_parse_int(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	inst->out->addi(inst->out, va_arg(inst->args, int));
}