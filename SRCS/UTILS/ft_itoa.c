/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabid <mabid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:19:52 by mabid             #+#    #+#             */
/*   Updated: 2023/01/20 19:25:20 by shammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_negative(int number)
{
	if (number < 0)
		return (1);
	else
		return (0);
}

static int	count_digits(unsigned int number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number >= 1)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	negative;
	unsigned int	number;
	unsigned int	digits;

	negative = is_negative(n);
	if (negative == 1)
		return (NULL);
	else
		number = n;
	digits = count_digits(number);
	str = (char *)malloc(digits + negative + 1);
	if (str == NULL)
		return (NULL);
	str[digits + negative] = '\0';
	while (digits > 0)
	{
		str[(digits - 1) + negative] = (number % 10) + '0';
		number /= 10;
		digits--;
	}
	return (str);
}
