/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoung <myoung@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 23:00:55 by myoung            #+#    #+#             */
/*   Updated: 2017/02/14 23:18:34 by myoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libunit.h>

int				unit_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void			unit_putn(int n)
{
	char c;

	if (n > 0)
	{
		unit_putn(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
}

void			unit_puts(char *str)
{
	write(1, str, unit_strlen(str));
}

char			*unit_strdup(const char *s1)
{
	char		*copy;
	int			len;

	len = 0;
	while (s1[len])
		len++;
	copy = (char*)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	len = 0;
	while (s1[len])
	{
		copy[len] = s1[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}

