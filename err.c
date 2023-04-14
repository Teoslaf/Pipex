/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:40:58 by ttaneski          #+#    #+#             */
/*   Updated: 2023/03/31 19:18:39 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_file_too_big(const char *filename)
{
	int		fd;
	int		size;
	char	buf[4096];
	ssize_t	n;

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	n = read(fd, buf, sizeof(buf));
	while (n > 0)
	{
		size += n;
		if (size > MAX_SIZE)
		{
			close (fd);
			return (1);
		}
		n = read(fd, buf, sizeof(buf));
	}
	close(fd);
	if (n < 0)
		return (-1);
	return (0);
}
