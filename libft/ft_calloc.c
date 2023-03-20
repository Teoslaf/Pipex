/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:37:29 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/28 13:53:51 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmbeb, size_t size)
{
	void	*rtn;

	rtn = malloc(size * nmbeb);
	if (!rtn)
		return (rtn);
	ft_bzero(rtn, nmbeb * size);
	return (rtn);
}
