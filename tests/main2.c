/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 08:51:33 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/13 16:43:43 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

// int			ft_putchar_exept(char c)
// {
// 	return (write (1, &c, 1));
// }

// int			ft_printf(char *str, ...)
// {
// 	t_stock		a;
// 	va_list		ap;

// 	va_start(ap, str);
// 	a.cnt = 0;
// 	a.writed = 0;
// 	while (str[a.cnt])
// 	{
// 		if (str[a.cnt] && str[a.cnt] != '%')
// 		{
// 			a.writed += ft_putchar_exept(str[a.cnt]);
// 			a.cnt++;
// 		}
// 		else if (str[a.cnt] == '%')
// 		{
// 			a.writed += ft_istype(str, ap , &a);
// 			a.cnt += 2;
// 		}
// 		else
// 			a.cnt++;
// 	}
// 	va_end(ap);
// 	return (a.writed);
// }

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int			main(int argc, char **argv)
{
	int i;
	int b;
    char    *str;

    str = 0;
	i = ft_printf("coco est deux fois a la maison % d %i %s %O %X et sa fait chier putain de merde\n", 30, 50, "salut", 42, 42);
	b = printf("coco est deux fois a la maison %d %i %s %o %X et sa fait chier putain de merde\n", 30, 50, "salut", 42, 42);
    printf("=== Premiere partie === %%d\n");
  //   printf("%d\n",ft_printf("%20 50 d            ", 2568));
  //   printf("%d\n",printf("%20d            ", 2568));
  //       ft_putchar('\n');
  //   printf("%d\n",ft_printf("%+c %s        ", 'a', "toot"));
  //   printf("%d\n",printf("%+c %+s        ", 'a', "toot"));
  //       ft_putchar('\n');
  //   printf("%d\n",ft_printf("%20 + i %s        ", 1500, "toot"));
  //   printf("%d\n",printf("%20 + i %+s        ", 1500, "toot"));
  //       ft_putchar('\n');
  //   printf("%d\n",ft_printf("%+d %s        ", -1500, "toot"));
  //   printf("%d\n",printf("%+d %s        ", -1500, "toot"));
  //       ft_putchar('\n');
  //   printf("%d\n",ft_printf("%d %p        ", INT_MAX, "toot"));
  //   printf("%d\n",printf("%d % p        ", INT_MAX, "toot"));
  //       ft_putchar('\n');
  //   printf("%d\n",ft_printf("%p %p        ", INT_MIN, "toot"));
  //   printf("%d\n",printf("%p %p        ", INT_MIN, "toot"));
  //       ft_putchar('\n');
  //   printf("%d\n",ft_printf("%p %p        ", 4000000000, str));
  //   printf("%d\n",printf("% p % p        ", 4000000000, str));
  //       ft_putchar('\n');
  //   printf("%d\n",ft_printf("%X %p        ", 4123123123, "toot"));
  //   printf("%d\n",printf("% X %p        ", 4123123123, "toot"));
  //       ft_putchar('\n');
  //   printf("%d\n",ft_printf("%u %s        ", 1, "toot"));
  //   printf("%d\n",printf("%u %s        ", 1, "toot"));
  //       ft_putchar('\n');
  //   printf("%d\n",ft_printf("%u %s        ", -15, "toot"));
  //   printf("%d\n",printf("%u %s        ", -15, "toot"));
  //       ft_putchar('\n');
  //   printf("%d\n",ft_printf("%u %s        ", UINT_MAX, "toot"));
  //   printf("%d\n",printf("%u %s        ", UINT_MAX, "toot"));
  //       ft_putchar('\n');
  //   printf("%d\n",ft_printf("%u %s        ", 0, "toot"));
  //   printf("%d\n",printf("%u %s        ", 0, "toot"));
  //       ft_putchar('\n');
	 // printf("%d\n",ft_printf("%+X %s        ", 0, "toot"));
  //   printf("%d\n",printf("%#X %s        ", 0, "toot"));
  //   ft_putchar('\n');
  //       printf("%d\n",ft_printf("%+x %s        ", 10, "toot"));
  //   printf("%d\n",printf("%#x %s        ", 10, "toot"));
  //       ft_putchar('\n');
  //       printf("%d\n",ft_printf("%+x %s        ", -1, "toot"));
  //   printf("%d\n",printf("%+x %s        ", -1, "toot"));
  //       ft_putchar('\n');
  //       printf("%d\n",ft_printf("%+x %s        ", INT_MAX, "toot"));
  //   printf("%d\n",printf("%+x %s        ", INT_MAX, "toot"));
  //       ft_putchar('\n');
  //       printf("%d\n",ft_printf("%+x %s        ", UINT_MAX, "toot"));
  //   printf("%d\n",printf("%+x %s        ", UINT_MAX, "toot"));
  //       ft_putchar('\n');
  //       printf("%d\n",ft_printf("%+x %s        ", 1500, "toot"));
  //   printf("%d\n",printf("%+x %s        ", 1500, "toot"));
  //       ft_putchar('\n');
    printf("Longueur et precision\n");
    printf("%d\n", ft_printf("%10d %s       ", 0, "toot"));
    printf("%d\n", printf("%10d %s       ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%2d %s            ", 1500, "toot"));
    printf("%d\n", printf("%2d %s            ", 1500, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.2d %s       ", 1500, "toot"));
    printf("%d\n", printf("%.2d %s       ", 1500, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.10d %s      ", 1500, "toot"));
    printf("%d\n", printf("%.10d %s      ", 1500, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%10.10d %s        ", 1500, "toot"));
    printf("%d\n", printf("%10.10d %s        ", 1500, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%15.10d %s        ", 1500, "toot"));
    printf("%d\n", printf("%15.10d %s        ", 1500, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%10.15d %s        ", 1500, "toot"));
    printf("%d\n", printf("%10.15d %s        ", 1500, "toot"));
    ft_putchar('\n');
    printf("Conversion\n");
    printf("%d\n", ft_printf("%ld %s        ", LONG_MAX, "toot"));
    printf("%d\n", printf("%ld %s       ", LONG_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%ld %s        ", LONG_MIN, "toot"));
    printf("%d\n", printf("%ld %s       ", LONG_MIN, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%lld %s       ", LONG_LONG_MAX , "toot"));
    printf("%d\n", printf("%lld %s      ", LONG_LONG_MAX , "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%D %s     ", LONG_MAX, "toot"));
    printf("%d\n", printf("%D %s        ", LONG_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%hd %s        ", 150, "toot"));
    printf("%d\n", printf("%hd %s       ", 150, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%hhd %s       ", 0, "toot"));
    printf("%d\n", printf("%hhd %s      ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%zd %s        ", 3000000000, "toot"));
    printf("%d\n", printf("%zd %s       ", 3000000000, "toot"));
    ft_putchar('\n');
    printf("All\n");
    printf("%d\n", ft_printf("%-+ #10.3d %s     ", 0, "toot"));
    printf("%d\n", printf("%-+ #10.3d %s        ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%05.7d %s     ", 1500, "toot"));
    printf("%d\n", printf("%05.7d %s        ", 1500, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%+ld %s       ", 3000000000, "toot"));
    printf("%d\n", printf("%+ld %s      ", 3000000000, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%+-12.1d %s       ", 1, "toot"));
    printf("%d\n", printf("%+-12.1d %s      ", 1, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.0d %s       ", 0, "toot"));
    printf("%d\n", printf("%.0d %s      ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.-1d %s      ", 1, "toot"));
    printf("%d\n", printf("%.-1d %s     ", 1, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%-+5.3d %s        ", 15, "toot"));
    printf("%d\n", printf("%-+5.3d %s       ", 15, "toot"));
    ft_putchar('\n');
    printf("=== Deuxieme partie %%u ===\n");
    printf("%d\n", ft_printf("%u %s     ", 1, "toot"));
    printf("%d\n", printf("%u %s        ", 1, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%u %s     ", -15, "toot"));
    printf("%d\n", printf("%u %s        ", -15, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%u %s     ", UINT_MAX, "toot"));
    printf("%d\n", printf("%u %s        ", UINT_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%u %s     ", 0, "toot"));
    printf("%d\n", printf("%u %s        ", 0, "toot"));
    ft_putchar('\n');
    printf("Different flags\n");
    printf("%d\n", ft_printf("%#u %s        ", 15, "toot"));
    printf("%d\n", printf("%#u %s       ", 15, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%#u %s        ", 0, "toot"));
    printf("%d\n", printf("%#u %s       ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%+u %s        ", 15, "toot"));
    printf("%d\n", printf("%+u %s       ", 15, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("% u %s        ", 15, "toot"));
    printf("%d\n", printf("% u %s       ", 15, "toot"));
    ft_putchar('\n');
    printf("Longueur et precision\n");
    printf("%d\n", ft_printf("%-10u %s      ", 15, "toot"));
    printf("%d\n", printf("%-10u %s     ", 15, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%10u %s       ", 15, "toot"));
    printf("%d\n", printf("%10u %s      ", 15, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%010u %s      ", 15, "toot"));
    printf("%d\n", printf("%010u %s     ", 15, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%10.2u %s     ", 15, "toot"));
    printf("%d\n", printf("%10.2u %s        ", 15, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%10.10u %s        ", 15, "toot"));
    printf("%d\n", printf("%10.10u %s       ", 15, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.0u %s       ", 0, "toot"));
    printf("%d\n", printf("%.0u %s      ", 0, "toot"));
    ft_putchar('\n');
    printf("Conversion\n");
    printf("%d\n", ft_printf("%lu %s        ", ULONG_MAX, "toot"));
    printf("%d\n", printf("%lu %s       ", ULONG_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%llu %s       ", ULLONG_MAX, "toot"));
    printf("%d\n", printf("%llu %s      ", ULLONG_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%hhu %s       ", UCHAR_MAX, "toot"));
    printf("%d\n", printf("%hhu %s      ", UCHAR_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%hu %s        ", USHRT_MAX, "toot"));
    printf("%d\n", printf("%hu %s       ", USHRT_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%zu %s        ", UINT_MAX, "toot"));
    printf("%d\n", printf("%zu %s       ", UINT_MAX, "toot"));
    ft_putchar('\n');
    printf("All\n");
    printf("%d\n", ft_printf("%+ -#015.10u %s       ", 0, "toot"));
    printf("%d\n", printf("%+ -#015.10u %s      ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%-0u %s       ", 15, "toot"));
    printf("%d\n", printf("%-0u %s      ", 15, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%+u %s        ", 15, "toot"));
    printf("%d\n", printf("%+u %s       ", 15, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.0u %s       ", 0, "toot"));
    printf("%d\n", printf("%.0u %s      ", 0, "toot"));
    ft_putchar('\n');
    printf("=== Troisieme partie %%o ===\n");
    printf("%d\n", ft_printf("%o %s     ", 0, "toot"));
    printf("%d\n", printf("%o %s        ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s     ", 10, "toot"));
    printf("%d\n", printf("%o %s        ", 10, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s     ", -1, "toot"));
    printf("%d\n", printf("%o %s        ", -1, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s     ", INT_MAX, "toot"));
    printf("%d\n", printf("%o %s        ", INT_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s     ", UINT_MAX, "toot"));
    printf("%d\n", printf("%o %s        ", UINT_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s     ", 1500, "toot"));
    printf("%d\n", printf("%o %s        ", 1500, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s     ", 5000, "toot"));
    printf("%d\n", printf("%o %s        ", 5000, "toot"));
    ft_putchar('\n');
    printf("Different flags\n");
    printf("%d\n", ft_printf("%#o %s        ", 0, "toot"));
    printf("%d\n", printf("%#o %s       ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%+0o %s       ", 10, "toot"));
    printf("%d\n", printf("%+0o %s      ", 10, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("% +o %s       ", 0, "toot"));
    printf("%d\n", printf("%+ o %s      ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%#o %s        ", 17, "toot"));
    printf("%d\n", printf("%#o %s       ", 17, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%#o %s        ", 50, "toot"));
    printf("%d\n", printf("%#o %s       ", 50, "toot"));
    ft_putchar('\n');
    printf("Longueur et precision\n");
    printf("%d\n", ft_printf("%-15.10o %s       ", 14, "toot"));
    printf("%d\n", printf("%-15.10o %s      ", 14, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%010o %s      ", 10, "toot"));
    printf("%d\n", printf("%010o %s     ", 10, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%+ -#010.4o %s        ", 10, "toot"));
    printf("%d\n", printf("%+ -#10.4o %s        ", 10, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.0o %s       ", 0, "toot"));
    printf("%d\n", printf("%.0o %s      ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.4o %s       ", 2, "toot"));
    printf("%d\n", printf("%.4o %s      ", 2, "toot"));
    ft_putchar('\n');
    printf("Conversion\n");
    printf("%d\n", ft_printf("%o %s     ", ULONG_MAX, "toot"));
    printf("%d\n", printf("%o %s        ", ULONG_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s     ", ULLONG_MAX, "toot"));
    printf("%d\n", printf("%o %s        ", ULLONG_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s     ", USHRT_MAX, "toot"));
    printf("%d\n", printf("%o %s        ", USHRT_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s     ", UCHAR_MAX, "toot"));
    printf("%d\n", printf("%o %s        ", UCHAR_MAX, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s     ", UINT_MAX, "toot"));
    printf("%d\n", printf("%o %s        ", UINT_MAX, "toot"));
    ft_putchar('\n');
    printf("All\n");
    printf("%d\n", ft_printf("%o %s     ", 0, "toot"));
    printf("%d\n", printf("%o %s        ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s", 0, "toot"));
    printf("%d\n", printf("%o %s", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s     ", 0, "toot"));
    printf("%d\n", printf("%o %s        ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o        ", 0, "toot"));
    printf("%d\n", printf("%o       ", 0, "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%o %s", 0, "toot"));
    printf("%d\n", printf("%o %s", 0, "toot"));
    ft_putchar('\n');
    printf("=== Cinquieme partie %%s et %%c ===\n");
    printf("%d\n", ft_printf("%.2S      ", L"øˆøˆøˆøˆø˙˙¥©"));
    printf("%d\n", printf("%.2S     ", L"øˆøˆøˆøˆø˙˙¥©"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.10s", "toot"));
    printf("%d\n", printf("%.10s", "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.2s      ", "toot"));
    printf("%d\n", printf("%.2s     ", "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.2s      ", "toot"));
    printf("%d\n", printf("%.2s     ", "toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%.10ls        ", L"toot"));
    printf("%d\n", printf("%.10ls       ", L"toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%ls       ", L"toot"));
    printf("%d\n", printf("%ls      ", L"toot"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%p        ", 42));
    printf("%d\n", printf("%p       ", 42));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%p        ", str));
    printf("%d\n", printf("%p       ", str));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%p        ", "toto"));
    printf("%d\n", printf("%p       ", "toto"));
    ft_putchar('\n');
    printf("%d\n", ft_printf("%p        ", 42));
    printf("%d\n", printf("%p       ", 42));

	printf("%d\n", b);
	printf("%d\n", i);
    (void)argc;
    (void)argv;
	return 0;
}
