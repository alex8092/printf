#include "ft_printf_private.h"

void	ft_printf_parse_longhexa(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	if (ft_printf_has_flag('#'))
		inst->out->v_alternate_form = true;
	inst->out->addlx(inst->out, va_arg(inst->args, long int));
}