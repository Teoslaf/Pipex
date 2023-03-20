/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:17:06 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/08 14:30:24 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	str = (const char *)s;
	while (n > 0)
	{
		if (*str == (char)c)
		{
			return ((void *)str);
		}
		str++;
		n--;
	}
	return (NULL);
}

/* int main()
{
	const char str[] = "123456789";
	const char ch = '7';
	char *ret;

	ret = ft_memchr(str, ch, 8);

	printf("%s\n", ret);

	return (0);
} */