#include "ft_printf_private.h"
#include "ft_common.h"

t_printf	*ft_printf_instance(void)
{
	static t_printf		inst;
	static t_bool		init = false;

	if (!init)
	{
		ft_bzero((void *)&inst, sizeof(t_printf));
		init = true;
	}
	return (&inst);
}