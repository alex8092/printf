#include "ft_printf_private.h"

void	ft_printf_add_unumber(unsigned long long i)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	inst->out->v_always_sign = false;
	inst->out->v_space_or_sign = false;
	inst->out->addull(inst->out, i);
}