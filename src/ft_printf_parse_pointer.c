#include "ft_printf_private.h"

void	ft_printf_parse_pointer(void)
{
	static t_printf		*inst = 0;
	void				*ptr;

	if (!inst)
		inst = ft_printf_instance();
	ptr = va_arg(inst->args, void *);
	if (ptr)
		inst->out->add(inst->out, "0x")->addlx(inst->out, (unsigned long)ptr);
	else
		inst->out->add(inst->out, "0x");
}