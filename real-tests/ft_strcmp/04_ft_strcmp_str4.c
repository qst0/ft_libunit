/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ft_strcmp_str4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:00:31 by mowen             #+#    #+#             */
/*   Updated: 2017/02/14 23:05:07 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int     test_ft_strcmp_str4(void)
{
	if (ft_strcmp("abcdefg", "321456") == strcmp("abcdefg", "321456"))
		return (0);
	else
		return (-1);
}
