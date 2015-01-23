#include "ft_printf_private.h"
#include "ft_common.h"

static t_printf_flag	g_flags[] =
{
	{ '#', false }
};

static t_bool	ft_printf_is_arg(char c)
{
	static const size_t	flags_size = sizeof(g_flags) / sizeof(g_flags[0]);
	size_t				i;

	i = 0;
	while (i < flags_size)
	{
		if (g_flags[i].ident == c)
		{
			g_flags[i].active = true;
			return (true);
		}
		++i;
	}
	return (false);
}

t_bool			ft_printf_has_flag(char c)
{
	static const size_t	flags_size = sizeof(g_flags) / sizeof(g_flags[0]);
	size_t				i;

	i = 0;
	while (i < flags_size)
	{
		if (g_flags[i].ident == c)
			return (g_flags[i].active);
		++i;
	}
	return (false);
}

void			ft_printf_get_flags(void)
{
	static t_printf		*inst = 0;

	if (!inst)
		inst = ft_printf_instance();
	while (ft_printf_is_arg(inst->str[inst->index]))
		++inst->index;
}