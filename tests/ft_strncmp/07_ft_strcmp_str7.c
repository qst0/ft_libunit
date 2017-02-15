/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_ft_strcmp_str7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:01:05 by mowen             #+#    #+#             */
/*   Updated: 2017/02/14 23:09:09 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int     test_ft_strcmp_str7(void)
{
	if (ft_strcmp("ok now that's getting odd", "ok now whats happening") == strcmp("ok now that's getting odd", "ok now whats happening"))
		return (0);
	else
		return (-1);
}
