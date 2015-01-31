/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 06:19:25 by amerle            #+#    #+#             */
/*   Updated: 2015/01/28 06:19:25 by amerle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (inst->str[inst->index] == '*')
			precision = va_arg(inst->args, int);
		else
		{
			precision = ft_atoi(inst->str + inst->index);
			if (precision < 0)
				++inst->index;
			while (ft_isnum(inst->str[inst->index]))
				++inst->index;
		}
		if (precision >= 0)
		{
			inst->out->v_precision = precision;
			ft_printf_disable_flag('0');
		}
	}
}
