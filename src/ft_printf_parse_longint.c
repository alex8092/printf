#include "ft_printf_private.h"

void	ft_printf_parse_longint(void)
{
	static t_printf		*inst = 0;
	long int			value;

	if (!inst)
		inst = ft_printf_instance();
	value = va_arg(inst->args, long int);
	if (ft_printf_has_flag('0') && inst->out->v_min_field_width > 0)
	{
		if (value < 0 || ft_printf_has_flag('+'))
			inst->out->v_precision = inst->out->v_min_field_width - 1;
	}
	inst->out->addl(inst->out, value);
}