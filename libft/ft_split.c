/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaneski <ttaneski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:47:00 by ttaneski          #+#    #+#             */
/*   Updated: 2022/12/28 13:56:41 by ttaneski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_words(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == c)
			j = 0;
		str++;
	}
	return (i);
}

static char	*ft_word(const char *str, int start, int end)
{
	char	*word;

	word = malloc((end - start + 1) * sizeof(char));
	ft_memcpy(word, str + start, end - start);
	word[end - start] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	i = 0;
	j = 0;
	index = -1;
	split = malloc((c_words(s, c) + 1) * sizeof(char *));
	if (!s || !(split))
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_word(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

/*
	c_words - Count the number of substrings in a string
	return: The number of substrings in the input string
*/
/*
	ft_word - Create a new substring from a string
	return: Pointer to the new substring
*/
/*
	ft_split - Split a string into an array of substrings
	return: Pointer to the array of substrings
*/
/* int main(int argc, char *argv[])
{
	char **result;
	int i;

	i = 0;
	result = ft_split("This is a test", ' ');

	while (result[i])
	{
		printf("%s \n", result[i]);
		i++;
	}
} */