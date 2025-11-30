/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:10:40 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/30 11:43:43 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int ft_printf(const char *format, ...);
int	ft_formats(va_list args, const char format);
int ft_printf_char(va_list args);
int	ft_printf_str(va_list args);
#endif