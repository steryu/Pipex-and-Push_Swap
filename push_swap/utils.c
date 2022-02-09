/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-ass <svan-ass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:46:41 by svan-ass          #+#    #+#             */
/*   Updated: 2022/02/09 09:50:35 by svan-ass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi2(const char *str)
{
	int					i;
	unsigned long long	result;
	int					min;

	i = 0;
	min = 1;
	result = 0;
	while (*str != '\0' && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str != '\0' && *str == '-')
	{
		min = -1;
		str++;
	}
	else if (*str == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
	}
	return (result * min);
}

int	check_min_max(const char *str)
{
	long long	temp;

	temp = ft_atoi2(str);
	if (temp >= INT_MIN && temp <= INT_MAX && ft_strlen(str) < 12)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str, t_stack *stack)
{
	int	i;
	int	result;
	int	min;

	i = 0;
	min = 1;
	result = 0;
	if (*str != '\0' && *str == '-')
	{
		min = -1;
		str++;
	}
	if (!*str)
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			result = (result * 10) + (str[i++] - '0');
		else
			exit_error(stack);
		if (check_min_max(str) == 0)
			exit_error(stack);
	}
	return (result * min);
}
