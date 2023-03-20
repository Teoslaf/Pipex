/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:18:07 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/28 17:59:32 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = 0;
	while (*s)
	{
		if (*s == (char)c)
			ret = (char *)s;
		s++;
	}
	if (!(char)c)
		ret = ((char *)s);
	return (ret);
}

/* int main()
{
	const char str[] = "teste";
	char *ret;

	ret = ft_strrchr(str, "t");

	printf("%p\n", ret);

	return (0);
} */
