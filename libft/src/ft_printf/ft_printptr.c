/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:50:47 by panther           #+#    #+#             */
/*   Updated: 2023/11/24 17:26:58 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/libft.h"

void	ft_putptr(unsigned long long n)
{
	if (n >= 16)
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd(n + 48, 1);
		else
			ft_putchar_fd(n - 10 + 'a', 1);
	}
}

int	get_ptrlen(unsigned long long n)
{
	int	nlen;

	nlen = 0;
	while (n != 0)
	{
		nlen++;
		n /= 16;
	}
	return (nlen);
}

/* ************************************************************************** */
/*                                                                            */
/*      The intptr_t and uintptr_t types are extremely useful for casting     */
/*      pointers when you want to do address arithmetic. They should be       */
/*      used instead of long or unsigned long for this purpose.               */
/*                                                                            */
/* ************************************************************************** */
//  Here, you put the address pointed by ptr
//
//	************* VERSION LINUX *************
//	unsigned long long in case of norm: C98
//
int	ft_printptr(void *ptr)
{
	int	counter;

	counter = 0;
	if (!ptr)
		counter += write(1, "(nil)", 5);
	else
	{
		counter += write(1, "0x", 2);
		ft_putptr((unsigned long long)ptr);
		counter += get_ptrlen((unsigned long long)ptr);
	}
	return (counter);
}
//
//	************ VERSION OSX ************
//	uintptr_t in case of norm: C99
// 
// int	ft_printptr(uintptr_t ptr)
// {
// 	int	input;

// 	input = 0;
// 	input += write(1, "0x", 2);	
// 	if (!(void *)ptr)
// 		input += write(1, "0", 1);
// 	else
// 	{
// 		ft_putptr(ptr);
// 		input += get_ptrlen(ptr);
// 	}
// 	return (input);
// }
