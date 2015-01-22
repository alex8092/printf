#include "ft_printf_private.h"
#include "ft_common.h"

static t_printf_opt		g_opts[] =
{
	{ "s", 1, &ft_printf_parse_string },
	{ "S", 1, &ft_printf_parse_wstring },
	{ "p", 1, &ft_printf_parse_pointer },
	{ "d", 1, &ft_printf_parse_int },
	{ "i", 1, &ft_printf_parse_int },
	{ "D", 1, &ft_printf_parse_longint },
	{ "o", 1, &ft_printf_parse_octal },
	{ "O", 1, &ft_printf_parse_longoctal }
};

static t_bool	f_check_ident(t_printf *inst, size_t i)
{
	size_t	cur = 0;

	while (cur < g_opts[i].size)
	{
		if (inst->str[inst->index + cur] != g_opts[i].ident[cur])
			return (false);
		++cur;
	}
	return (true);
}

void			ft_printf_dispatch_arg(void)
{
	static t_printf		*inst = 0;
	const size_t		nopts = sizeof(g_opts) / sizeof(g_opts[0]);
	size_t				i;

	if (!inst)
		inst = ft_printf_instance();
	i = 0;
	while (i < nopts)
	{
		if (f_check_ident(inst, i))
		{
			inst->index += g_opts[i].size;
			g_opts[i].parse();
			break ;
		}
		++i;
	}
}