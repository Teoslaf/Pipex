/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:11:28 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/08 15:58:56 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
}

/* int main()
{
  char str[50] = "123456.";
  printf("\nBefore bzero(): %s\n\n", str);
  ft_bzero(str, 6);
  printf("After bzero(): %s\n\n", str);
  return 0;
} */