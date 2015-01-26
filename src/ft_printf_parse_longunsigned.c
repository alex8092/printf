#include "ft_printf_private.h"

void	ft_printf_parse_longunsigned(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	inst->out->v_always_sign = false;
	inst->out->v_space_or_sign = false;
	inst->out->addui(inst->out, va_arg(inst->args, unsigned long int));
}