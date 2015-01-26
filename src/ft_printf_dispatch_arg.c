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
	{ "O", 1, &ft_printf_parse_longoctal },
	{ "u", 1, &ft_printf_parse_unsigned },
	{ "U", 1, &ft_printf_parse_longunsigned },
	{ "x", 1, &ft_printf_parse_hexa },
	{ "X", 1, &ft_printf_parse_upperhexa },
	{ "c", 1, &ft_printf_parse_char },
	{ "C", 1, &ft_printf_parse_wchar }
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
	ft_printf_get_flags();
	if (ft_printf_has_flag('+'))
		inst->out->v_always_sign = true;
	if (ft_printf_has_flag('#'))
		inst->out->v_alternate_form = true;
	if (ft_printf_has_flag('-'))
		inst->out->v_left_align = true;
	if (ft_printf_has_flag(' '))
		inst->out->v_space_or_sign = true;
	if (ft_printf_has_flag('0') && ft_printf_has_flag('-'))
		ft_printf_disable_flag('0');
	ft_printf_get_size();
	ft_printf_get_precision();
	if (ft_printf_has_flag('0'))
		inst->out->v_char_fill = '0';
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