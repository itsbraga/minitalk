/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:58:27 by panther           #+#    #+#             */
/*   Updated: 2023/12/13 20:44:59 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_printparams(va_list args, const char *format)
{
	int	input;

	input = 0;
	if (*format == 'c')
		input += ft_printchar(va_arg(args, int));
	else if (*format == 's')
		input += ft_printstr(va_arg(args, char *));
	else if (*format == 'p')
		input += ft_printptr(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		input += ft_printnbr(va_arg(args, int));
	else if (*format == 'u')
		input += ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		input += ft_printhex(va_arg(args, unsigned int), format);
	else if (*format == '%')
		input += ft_printchar('%');
	return (input);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_printparams(args, &format[i + 1]);
			i++;
		}
		else
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	char	*test;
//
// 	test = "Check address";
// 	puts("What my function does:\n");
// 	printf("printf ret=%d\n", ft_printf("%c\n%s\n%p\n%d\n%i\n",
// 						 'a', "Møme", test, 42, -2147483647));
// 	printf("printf ret=%d\n", ft_printf("%u\n%x\n%X\n", 5, 42, 102));
// 	printf("printf ret=%d\n", ft_printf("%x\n%X\n", 42, 10256465));
// 	printf("printf ret=%d\n", ft_printf(0));
// 	printf("printf ret=%d\n", ft_printf(NULL));
//	
// 	puts("\n\nTrue f:\n");
// 	printf("printf ret=%d\n", printf("%c\n%s\n%p\n%d\n%i\n",
// 						'a', "Møme", test, 42, -2147483647));
// 	printf("printf ret=%d\n", printf("%u\n%x\n%X\n", 5, 42, 102));
// 	printf("printf ret=%d\n", printf("%x\n%X\n", 42, 10256465));
// 	printf("printf ret=%d\n", printf(0));
// 	printf("printf ret=%d\n", printf(NULL));
// }