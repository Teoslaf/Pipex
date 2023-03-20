/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:32:02 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/28 15:46:45 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/* void to_upper(unsigned int index, char *c)
{
	if (index % 2 == 0)
		*c -= 32;
}

int main(void)
{
	char s[] = "hello, world!";
	ft_striteri(s, to_upper);
	printf("%s\n", s);
	return 0;
} */
