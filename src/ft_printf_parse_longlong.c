/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_longlong.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:26 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:26 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_parse_longlong(void)
{
	static t_printf		*inst = 0;
	long long			value;

	if (!inst)
		inst = ft_printf_instance();
	value = va_arg(inst->args, long long);
	ft_printf_add_number(value);
}
