/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:54:59 by jcarlen           #+#    #+#             */
/*   Updated: 2021/10/27 10:55:01 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n);

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (dst[j] && j < n)
		j++;
	while (src[k] && ((j + k + 1) < n))
	{
		dst[j + k] = src[k];
		k++;
	}
	if (j != n)
		dst[j + k] = '\0';
	return (j + ft_strlen(src));
}
