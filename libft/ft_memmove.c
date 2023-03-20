/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:15:14 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/28 11:15:58 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (dest == src || n == 0)
	{
		return (dest);
	}
	else if (src > dest)
	{
		a = (unsigned char *)dest;
		b = (unsigned char *)src;
		while (n--)
			*a++ = *b++;
	}
	else
	{
		a = (unsigned char *)dest + (n - 1);
		b = (unsigned char *)src + (n - 1);
		while (n--)
			*a-- = *b--;
	}
	return (dest);
}

/* int main(void)
{
	char i[] = "123!";
	char j[] = " qwe";
	printf("BEFORE: %s\n", i); 
	ft_memmove(i, j, 30);
	printf("AFTER: %s\n", i);
	return (0);
}
 */