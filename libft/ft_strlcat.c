/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:46:14 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/28 11:21:28 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (dst_len >= size)
	{
		return (src_len + size);
	}
	while (i < src_len && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* int main()
{
	char dest[40] = "Hello";
	char src[20] = " There";
	ft_strlcat(dest, src, 10);
	printf("%s \n", dest);
	char dest1[40] = "Hello";
	char src1[20] = " There";
	strlcat(dest1, src1, 10);
	printf("%s \n", dest1);

} */
