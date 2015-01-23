#include "ft_printf_private.h"

void	ft_printf_parse_octal(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	if (ft_printf_has_flag('#'))
		inst->out->v_alternate_form = true;
	inst->out->addo(inst->out, va_arg(inst->args, int));
}