/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_ft_strcmp_str6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:00:56 by mowen             #+#    #+#             */
/*   Updated: 2017/02/14 23:07:08 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int     test_ft_strcmp_str6(void)
{
	if (ft_strcmp("   hey3chars", "  hey3chars") == strcmp("   hey3chars", "  hey3chars"))
		return (0);
	else
		return (-1);
}
