/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:22:41 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/30 11:49:44 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int	len_ft_printf;
	int	len_printf;

	// Test Just Text
	len_ft_printf = ft_printf("ft_printf: just text\n");
	len_printf = printf("printf: just text\n");
	printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);

	
	// Test Char
	char	c = 'c';
	len_ft_printf = ft_printf("ft_printf: %c\n", c);
	len_printf = printf("printf: %c\n", c);
	printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);

	
	// Test String
	char str[] = "Gotta get Gotta get Away...";
	len_ft_printf = ft_printf("ft_printf: %s\n", str);
	len_printf = printf("printf: %s\n", str);
	printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);
	return (0);
}