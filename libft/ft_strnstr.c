/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:58:06 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/28 16:56:22 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (little[0] == '\0' || &(*little) == &(*big))
		return ((char *)big);
	while (big[a] != '\0' && a < len)
	{
		b = 0;
		while (big[a + b] == little[b] && a + b < len && little[b])
		{
			b++;
		}
		if (little[b] == '\0')
			return ((char *)big + a);
		a++;
	}
	return (0);
}

/* int  main(void)
{
	char    big[] = "dobar den kako si";
	char    small[] = "kako";
	if (ft_strnstr(str, find, 15))
	{
		printf ("%s\n", ft_strnstr(str, find, 15));
	}
	else
	{
		printf ("F\n");
	}
	return (0);
}  */
