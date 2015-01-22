#include "ft_printf_private.h"
#include "ft_common.h"

void	ft_printf_parse_wstring(void)
{
	static t_printf		*inst = 0;
	wchar_t				*str;
	size_t				size;

	if (!inst)
		inst = ft_printf_instance();
	str = va_arg(inst->args, wchar_t *);
	if (str)
	{
		size = ft_wstrlen(str);
		size = size * sizeof(wchar_t) - size;
		inst->minus_ret_size += size;
		inst->out->addw(inst->out, str);
	}
	else
		inst->out->add(inst->out, "(null)");
}