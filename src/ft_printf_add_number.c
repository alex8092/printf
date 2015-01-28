#include "ft_printf_private.h"

void	ft_printf_add_number(long long i)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	if (ft_printf_has_flag('0') && inst->out->v_min_field_width > 0)
	{
		if (i < 0 || ft_printf_has_flag('+'))
			inst->out->v_precision = inst->out->v_min_field_width - 1;
	}
	inst->out->addll(inst->out, i);
}