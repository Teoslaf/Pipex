/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:58:08 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/28 13:29:12 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned const char	*p1;
	unsigned char		*p2;

	p1 = (unsigned const char *)src;
	p2 = (unsigned char *)dest;
	if (!dest && !src)
		return (0);
	while (len--)
		*p2++ = *p1++;
	return (dest);
}

/* int main()
{
	char str[50] = "123456";
	char str1[50] = "asdfgh";
	printf("Before memset():%s : %s\n", str, str1);
	ft_memcpy(str, str1, 5);
	printf("After memset(): %s : %s\n", str, str1);
	return 0;
} */