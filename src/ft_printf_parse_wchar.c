/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_wchar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:28 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:28 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
