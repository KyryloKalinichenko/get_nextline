/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:56:12 by kkalinic          #+#    #+#             */
/*   Updated: 2020/11/27 10:29:53 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(long n)
{
	long k;
	long p;

	k = 1;
	p = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		k++;
	}
	while (n > 9)
	{
		n /= 10;
		k++;
	}
	return (k + p);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		p;
	long	k;

	k = n;
	p = ft_len(k);
	s = malloc(sizeof(char) * (p + 1));
	if (s == NULL)
		return (NULL);
	s[p] = '\0';
	if (k == 0)
		s[0] = '0';
	if (k < 0)
	{
		s[0] = '-';
		k *= -1;
	}
	while (k > 0)
	{
		p--;
		s[p] = ((k % 10) + 48);
		k /= 10;
	}
	return (s);
}
