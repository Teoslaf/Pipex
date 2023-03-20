/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:59:37 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/28 17:26:08 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void ft_print_result(char const *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
} */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len > (ft_strlen (s)- start))
		n = ft_strlen (s) - start;
	else
		n = len;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(*s) * (n + 1));
	if (!str)
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

/* int main()
{
	char str[] = "123456789";
	char *res = ft_substr(str, 2, 3);
	printf("%s \n", res);
} */
/* int main()
{
	char str[] = "lorem ipsum dolor sit amet";
	char *strsub;
	if (!(strsub = ft_substr(str, 7, 10)))
		ft_print_result("NULL");
	else
		ft_print_result(strsub);
	if (str == strsub)
		ft_print_result("\nA new string was not returned");
} */
