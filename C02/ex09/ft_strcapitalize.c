/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:14:09 by isousman          #+#    #+#             */
/*   Updated: 2026/07/20 14:22:09 by isousman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_mot;

	i = 0;
	new_mot = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && new_mot)
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z' && !new_mot)
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
			new_mot = 0;
		else
			new_mot = 1;
		i++;
	}
	return (str);
}
