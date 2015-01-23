#include "ft_printf_private.h"

void	ft_printf_parse_upperhexa(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	inst->out->v_upper = true;
	if (ft_printf_has_flag('#'))
		inst->out->v_alternate_form = true;
	inst->out->addx(inst->out, va_arg(inst->args, int));
}