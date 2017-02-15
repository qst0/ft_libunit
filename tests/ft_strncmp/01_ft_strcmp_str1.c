/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_strcmp_str1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mowen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 22:58:51 by mowen             #+#    #+#             */
/*   Updated: 2017/02/14 23:03:32 by mowen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int     test_ft_strcmp_str1(void)
{
	if (ft_strcmp("hey i'm stressed", "hey i'm stressed") == strcmp("hey i'm stressed", "hey i'm stressed"))
		return (0);
	else
		return (-1);
}
