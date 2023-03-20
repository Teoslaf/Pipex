/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:38:55 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/05 11:43:17 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (len--)
		*p++ = (unsigned char)c;
	return (s);
}

/* void *ft_memset(void *s, int c,  unsigned int len)
{
	unsigned int i;
	unsigned char *p=s;

	i = 0;

	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return(s);
} */

/*  int main()
{
	char str[50] = "123456.";
	printf("\nBefore memset(): %s\n\n", str);
	ft_memset(str, '*', 6);
	printf("After memset(): %s\n\n", str);
	return 0;
} */