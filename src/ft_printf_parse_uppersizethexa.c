#include "ft_printf_private.h"

void	ft_printf_parse_uppersizethexa(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	inst->out->v_upper = true;
	ft_printf_add_hexa(va_arg(inst->args, size_t));
}