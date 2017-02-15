/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_ft_strcmp_str5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:00:41 by mowen             #+#    #+#             */
/*   Updated: 2017/02/14 23:08:34 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int     test_ft_strcmp_str5(void)
{
	if (ft_strcmp("this is not the same", "this is\n not the same") == strcmp("this is not the same", "this is\n not the same"))
		return (0);
	else
		return (-1);
}
