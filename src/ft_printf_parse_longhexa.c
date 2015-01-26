#include "ft_printf_private.h"

void	ft_printf_parse_longhexa(void)
{
	static t_printf		*inst = 0;
	long int			value;

	if (!inst)
		inst = ft_printf_instance();
	if (ft_printf_has_flag('#'))
		inst->out->v_alternate_form = true;
	value = va_arg(inst->args, long int);
	if (ft_printf_has_flag('0') && inst->out->v_min_field_width > 0)
	{
		if (value < 0 || ft_printf_has_flag('+'))
			inst->out->v_precision = inst->out->v_min_field_width - 2;
	}
	inst->out->addlx(inst->out, value);
}