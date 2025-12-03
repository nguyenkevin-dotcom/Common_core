/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:10:40 by kevnguye          #+#    #+#             */
/*   Updated: 2025/12/03 16:27:42 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_formats(va_list *args, const char format);
int	ft_printf_char(int c);
int	ft_printf_str(char *str);
int	ft_printf_ptr(void *ptr);
int	ft_printf_dec(int n);
int	ft_printf_unsigned_n(unsigned int n);
int	ft_printf_hex(unsigned long long n, const char format);
int	ft_printf_percentage(void);
#endif