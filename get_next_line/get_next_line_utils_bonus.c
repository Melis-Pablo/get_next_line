/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelis <pmelis@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:37:38 by pmelis            #+#    #+#             */
/*   Updated: 2023/04/19 23:37:45 by pmelis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
#ft_strlen():	find length of string.

#Parameters:	const char *str

#Return value:	int i -- length of str

#How it works:	Uses counter and a while loop to cycle trough the string until
				the end and returns the counter.
*/

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
#ft_strchr():	find the chr c in string s

#Parameters:	const char *s
				int c

#Return value:	char * -- chr found

#How it works:	if s is null it returns 0, ir goes trought s until it finds c
				or it ends, after it checks if current s == c, if it finds it
				it will return it, if it doesn't it returns 0
*/

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s && *s != (char) c)
		s++;
	if (*s == (char) c)
		return ((char *)s);
	return (0);
}

/*
#ft_strjoin:	concatenates 2 strings and returns a new allocated str

#Parameters:	char *s1
				char *s2

#Return value:	char *str -- new str

#How it works:	if s1 is null it will allocate memory for an empty str and after
				if s1 or s2 are null ir will return null. it will then allocate
				memory for the new str. then it will copy s1 into str, and then
				s2 into str, terminate it with '\0', free s1 and return str.
*/

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
			str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}
