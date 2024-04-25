/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:43:42 by flfische          #+#    #+#             */
/*   Updated: 2024/03/07 15:15:28 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief converts the initial portion of the string pointed to by str to int
 * @param str string to convert
 * @return int converted string
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	is_negativ;
	int	out;

	i = 0;
	out = 0;
	is_negativ = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negativ = 1 - is_negativ;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + (str[i] - '0');
		i++;
	}
	if (is_negativ)
		out = -1 * out;
	return (out);
}
