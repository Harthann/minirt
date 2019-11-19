/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:03:44 by nieyraud          #+#    #+#             */
/*   Updated: 2019/10/16 15:12:12 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_bzero(str, len + 1);
	if (start > ft_strlen(s))
		return (str);
	ft_memcpy(str, s + start, len);
	return (str);
}
