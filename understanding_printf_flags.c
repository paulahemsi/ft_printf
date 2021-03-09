/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   understanding_printf_flags.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 13:35:20 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/03/09 08:20:25 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int	ft_printf(const char *format, ...)
{
	va_list args;
	int done;
	
	char *substr = strstr(format, "42");
	if (substr != format)
		return (0);
	va_start(args, format);
	done = vfprintf(stdout, format, args);
	va_end(args);
	return (done);
}

void	red(void)
{
	printf("\033[1;31m");
}

void	yellow(void)
{
	printf("\e[0;93m");
}

void	cyan(void)
{
	printf("\e[0;36m");
}

void	purple(void)
{
	printf("\e[0;35m");
}
	
void	blue(void)
{
	printf("\e[0;34m");
}

void	green(void)
{
	printf("\e[0;32m");
}
void	reset(void)
{
	printf("\033[0m");
}

int	main(void)
{
	printf("\n");
	yellow();
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("-------------------------------------------PRNTF FLAG TEST------------------------------------------\n");
	printf("----------------------------------------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("---------------------------------------------character----------------------------------------------\n");
	reset();
	printf("\n");
	printf("%-60s: |%c|","format identifier", 'x');
	printf("\n");
	printf("%-60s: |%20c|", "with minimum field (20) width", 'x');
	printf("\n");
	printf("%-60s: |%-20c|", "minimum field (20) left align", 'x');
	printf("\n");
	printf("%-60s: |%-*c|", "minimum (8) field (*) left align", 8, 'x');
	printf("\n");
	printf("\n");
	yellow();
	printf("----------------------------------------------string--------------------------------------------------\n");
	reset();
	printf("\n");
	printf("%-60s: |%s|","format identifier", "quarenta e dois");
	printf("\n");
	printf("%-60s: |%20s|", "with minimum field (20) width", "quarenta e dois");
	printf("\n");
	printf("%-60s: |%-20s|", "minimum field (20) left align", "quarenta e dois");
	printf("\n");
	printf("%-60s: |%-20s|", "minimum field (20) left align", "quarenta e dois");
	printf("\n");
	printf("%-60s: |%.8s|", "precision (8) field", "quarenta e dois");
	printf("\n");
	printf("%-60s: |%-.8s|", "precision (8) field left align", "quarenta e dois");
	printf("\n");
	printf("%-60s: |%20.8s|", "minimum (20) and precision (8) field", "quarenta e dois");
	printf("\n");
	printf("%-60s: |%-20.8s|", "minimum (20) and precision (8) field left align", "quarenta e dois");
	printf("\n");
	printf("%-60s: |%-*.*s|", "minimum (20) and precision (8) field left align", 20, 8, "quarenta e dois");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	yellow();
	printf("---------------------------------------------pointer----------------------------------------------------\n");
	reset();
	printf("\n");
	
	int *pointer;
	int num;
	
	num = 42;
	pointer = &num;
	printf("%-60s: |%p|","format identifier", pointer);
	printf("\n");
	printf("%-60s: |%20p|", "with minimum field (20) width", pointer);
	printf("\n");
	printf("%-60s: |%-20p|", "minimum field (20) left align", pointer);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	yellow();
	printf("----------------------------------------decimal_signed_integer---------------------------------------------\n");
	reset();
	printf("\n");
	int hex_neg = -0x2a;
	
	printf("%-60s: |%d|","format identifier", -42);
	printf("\n");
	printf("%-60s: |%d|","(hex) format identifier", hex_neg);
	printf("\n");
	printf("%-60s: |%20d|", "with minimum field (20) width", -42);
	printf("\n");
	printf("%-60s: |%020d|", "minimum field (20) width with 0's", -42);
	printf("\n");
	printf("%-60s: |%-20d|", "minimum field (20) left align", -42);
	printf("\n");
	printf("%-60s: |%20.1d|", "precision (1) and minimum (20) field", -42);
	printf("\n");
	printf("%-60s: |%.2d|", "precision (2) field", hex_neg);
	printf("\n");
	printf("%-60s: |%-.10d|", "precision (10) field left align", hex_neg);
	printf("\n");
	printf("%-60s: |%20.10d|", "minimum (20) and precision (10) field", -12345678);
	printf("\n");
	printf("%-60s: |%-20.10d|", "minimum (20) and precision (10) field left align", -12345678);
	printf("\n");
	printf("%-60s: |%-*.*d|", "minimum (20) and precision (1) field left align", 20, 1, hex_neg);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	yellow();
	printf("-----------------------------------------------integer--------------------------------------------------------\n");
	reset();
	printf("\n");
	printf("%-60s: |%i|","format identifier", -42);
	printf("\n");
	printf("%-60s: |%20i|", "with minimum field (20) width", -42);
	printf("\n");
	printf("%-60s: |%020i|", "minimum field (20) width with 0's", -42);
	printf("\n");
	printf("%-60s: |%-20i|", "minimum field (20) left align", -42);
	printf("\n");
	printf("%-60s: |%20.1i|", "precision (1) and minimum (20) field", -42);
	printf("\n");
	printf("%-60s: |%.1i|", "precision (1) field", -42);
	printf("\n");
	printf("%-60s: |%-.1i|", "(hex_neg) precision (1) field left align", hex_neg);
	printf("\n");
	printf("%-60s: |%020.10i|", "minimum (20) and precision (10) field", -12345678);
	printf("\n");
	printf("%-60s: |%-20.10i|", "minimum (20) and precision (10) field left align", -12345678);
	printf("\n");
	printf("\n");
	printf("%-60s: |%-*.*i|", "(hex_neg) minimum (20) and precision (1) field left align", 20, 1, hex_neg);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	yellow();
	printf("-------------------------------------------unsigned_integer------------------------------------------------------\n");
	reset();
	printf("\n");
	red();
	printf("%-60s: |%u|","negative input", -42);
	reset();
	printf("\n");
	printf("%-60s: |%u|","format identifier", 42);
	printf("\n");
	printf("%-60s: |%20u|", "with minimum field (20) width", 42);
	printf("\n");
	printf("%-60s: |%020u|", "minimum field (20) width with 0's", 42);
	printf("\n");
	printf("%-60s: |%-20u|", "minimum field (20) left align", 42);
	printf("\n");
	printf("%-60s: |%20.1u|", "precision (1) and minimum (20) field", 42);
	printf("\n");
	printf("%-60s: |%.1u|", "precision (1) field", 42);
	printf("\n");
	printf("%-60s: |%-.1u|", "(hex_neg) precision (1) field left align", 42);
	printf("\n");
	printf("%-60s: |%-20.1u|", "minimum (20) and precision (1) field left align", 42);
	printf("\n");
	printf("%-60s: |%-*.*u|", "(hex_neg) minimum (20) and precision (1) field left align", 20, 1, 42);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	yellow();
	printf("---------------------------------------------hex_integer_lowercase----------------------------------------------------\n");
	reset();
	
	int hex = 0x9f4;
	int integer = 42;
	
	printf("\n");
	printf("%-60s: |%x|","(int) format identifier", integer);
	printf("\n");
	printf("%-60s: |%x|","(hex) format identifier", hex);
	printf("\n");
	printf("%-60s: |%20x|", "(int) with minimum field (20) width", integer);
	printf("\n");
	printf("%-60s: |%20x|", "(hex) with minimum field (20) width", hex);
	printf("\n");
	printf("%-60s: |%020x|", "(int) minimum field (20) width with 0's", integer);
	printf("\n");
	printf("%-60s: |%020x|", "(hex) minimum field (20) width with 0's", hex);
	printf("\n");
	printf("%-60s: |%-20x|", "(int) minimum field (20) left align", integer);
	printf("\n");
	printf("%-60s: |%-20x|", "(hex) minimum field (20) left align", hex);
	printf("\n");
	printf("%-60s: |%20.1x|", "precision (1) and minimum (20) field", hex);
	printf("\n");
	printf("%-60s: |%.1x|", "precision (1) field", integer);
	printf("\n");
	printf("%-60s: |%-.1x|", "(hex_neg) precision (1) field left align", hex);
	printf("\n");
	printf("%-60s: |%-20.1x|", "minimum (20) and precision (1) field left align", hex);
	printf("\n");
	printf("%-60s: |%-*.*x|", "(hex_neg) minimum (20) and precision (1) field left align", 20, 1, hex);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	yellow();
	printf("---------------------------------------------hex_integer_lowercase----------------------------------------------------\n");
	reset();
	printf("\n");
	printf("%-60s: |%X|","(int) format identifier", integer);
	printf("\n");
	printf("%-60s: |%X|","(hex) format identifier", hex);
	printf("\n");
	printf("%-60s: |%20X|", "(int) with minimum field (20) width", integer);
	printf("\n");
	printf("%-60s: |%20X|", "(hex) with minimum field (20) width", hex);
	printf("\n");
	printf("%-60s: |%020X|", "(int) minimum field (20) width with 0's", integer);
	printf("\n");
	printf("%-60s: |%020x|", "(hex) minimum field (20) width with 0's", hex);
	printf("\n");
	printf("%-60s: |%-20X|", "(int) minimum field (20) left align", integer);
	printf("\n");
	printf("%-60s: |%-20X|", "(hex) minimum field (20) left align", hex);
	printf("\n");
	printf("%-60s: |%20.1X|", "precision (1) and minimum (20) field", hex);
	printf("\n");
	printf("%-60s: |%.1X|", "precision (1) field", integer);
	printf("\n");
	printf("%-60s: |%-.1X|", "(hex_neg) precision (1) field left align", hex);
	printf("\n");
	printf("%-60s: |%-20.1X|", "minimum (20) and precision (1) field left align", hex);
	printf("\n");
	printf("%-60s: |%-*.*X|", "(hex_neg) minimum (20) and precision (1) field left align", 20, 1, hex);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	yellow();
	printf("--------------------------------------------------------%%---------------------------------------------------------------\n");
	reset();
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	return (0);
}