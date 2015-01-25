#include "ft_printf_private.h"
#include "ft_common.h"

void	ft_printf_get_precision(void)
{
	static t_printf	*inst = 0;
	long int		precision;

	if (!inst)
		inst = ft_printf_instance();
	if (inst->str[inst->index] == '.')
	{
		++inst->index;
		precision = ft_atoi(inst->str + inst->index);
		if (precision < 0)
			++inst->index;
		while (inst->str[inst->index] >= '0' && inst->str[inst->index] <= '9')
			++inst->index;
		if (precision >= 0)
		{
			inst->out->v_precision = precision;
			inst->out->v_char_fill = ' ';
		}
	}
}