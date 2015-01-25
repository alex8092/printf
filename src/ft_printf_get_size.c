#include "ft_printf_private.h"
#include "ft_common.h"

void	ft_printf_get_size(void)
{
	static t_printf	*inst = 0;
	long int		size;

	if (!inst)
		inst = ft_printf_instance();
	size = ft_atoi((const char *)(inst->str + inst->index));
	if (size)
	{
		if (size < 0)
			++inst->index;
		while (inst->str[inst->index] >= '0' && inst->str[inst->index] <= '9')
			++inst->index;
		if (size < 0)
			return ;
		inst->out->v_min_field_width = size;
	}
}