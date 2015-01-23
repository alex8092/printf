#include "ft_printf_private.h"

void	ft_printf_parse_char(void)
{
	static t_printf		*inst = 0;
	int					c;

	if (!inst)
		inst = ft_printf_instance();
	c = va_arg(inst->args, int);
	inst->out->addc(inst->out, (unsigned char)c);
}