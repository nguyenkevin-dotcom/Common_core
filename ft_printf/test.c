/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:22:41 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/03 01:25:31 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int	len_ft_printf;
	int	len_printf;
	// int len_print;

	// Test Just Text
	len_ft_printf = ft_printf("Mine: just text\n");
	len_printf = printf("Real: just text\n");
	printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);

	
	// Test Char
	char	c = 'c';
	len_ft_printf = ft_printf("Mine: %c\n", c);
	len_printf = printf("Real: %c\n", c);
	printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);

	
	// Test String
	char str[] = "42";
	len_ft_printf = ft_printf("Mine: %s\n", str);
	len_printf = printf("Real: %s\n", str);
	printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);

	// Test hex
	int     a = 0;
    char    str_hex[] = "42";
	len_ft_printf = ft_printf("Mine: %p\n", &a);
    len_printf = printf("Real: %p\n", &a);
    printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);
	len_ft_printf = ft_printf("Mine: %p\n", str_hex);
    len_printf = printf("Real: %p\n", str_hex);
    printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);

	// Test NULL String
    len_ft_printf = ft_printf("Mine: %s\n", (char *)NULL);
    len_printf = printf("Real: %s\n", (char *)NULL);
	printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);
	
    // Test Number with %d
    len_ft_printf = ft_printf("Mine: Number %d\n", -42);
    len_printf = printf("Real: Number %d\n", -42);
    printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);
    
	// Test Number with %i
	len_ft_printf = ft_printf("Mine: Number %i\n", 0b10000); //binary
    len_printf = printf("Real: Number %i\n", 0x10); //hex
    printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);
	
	// Test number with %x
	len_ft_printf = ft_printf("Mine: Number %x\n", 1392487);
    len_printf = printf("Real: Number %x\n", 1392487);
    printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);
	
	// Test number with %X
	len_ft_printf = ft_printf("Mine: Number %X\n", 123984713);
    len_printf = printf("Real: Number %X\n", 123984713);
    printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);

	// Test number with %
	len_ft_printf = ft_printf("Mine: Number %%%x\n", 123984713);
    len_printf = printf("Real: Number %%%x\n", 123984713);
    printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);

	// Test number with mix
	len_ft_printf = ft_printf("Mine: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// 									%c%s%d%i%u%x%X%%				%c%s%d%i%u%x%X%%
    len_printf = printf("Real: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
    printf("length ft_printf: %d\nlength printf: %d\n\n", len_ft_printf, len_printf);
	return (0);
}