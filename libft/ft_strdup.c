/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:54:38 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/08 12:19:34 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;

	len = ft_strlen(s1) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (0);
	ft_memcpy(str, s1, len);
	return (str);
}

/* int main()
{
	const char *str = "asd";
	char *bla = ft_strdup(str);
	printf("%s\n", bla);
} */
