/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:38:29 by isousman          #+#    #+#             */
/*   Updated: 2026/08/02 13:38:57 by isousman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* Calcule la longueur d'une chaîne */
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/* Calcule la taille totale nécessaire pour la concaténation */
int	ft_total_length(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		if (i < size - 1)
			total += ft_strlen(sep);
		i++;
	}
	return (total);
}

/* Copie une chaîne dans une autre à partir d'un index donné */
void	ft_copy_str(char *dest, char *src, int *pos)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[*pos] = src[i];
		(*pos)++;
		i++;
	}
}

/* Concatène toutes les chaînes avec le séparateur */
char	*ft_concat_all(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < size)
	{
		ft_copy_str(dest, strs[i], &pos);
		if (i < size - 1)
			ft_copy_str(dest, sep, &pos);
		i++;
	}
	dest[pos] = '\0';
	return (dest);
}

/* Fonction principale : ft_strjoin */
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;

	if (size == 0)
	{
		result = (char *)malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	total_len = ft_total_length(size, strs, sep);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	result = ft_concat_all(size, strs, sep, result);
	return (result);
}
