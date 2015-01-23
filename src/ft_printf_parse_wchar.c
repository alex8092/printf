#include "ft_printf_private.h"

void	ft_printf_parse_wchar(void)
{
	static t_printf		*inst = 0;
	wint_t				c;
	wchar_t				c2;

	if (!inst)
		inst = ft_printf_instance();
	c = va_arg(inst->args, wint_t);
	c2 = (wchar_t)c;
	inst->out->addn(inst->out, (const char *)&c2, sizeof(wchar_t));
	inst->minus_ret_size += sizeof(wchar_t) - 1;
}