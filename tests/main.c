#include <stdio.h>
#include <wchar.h>
#include "ft_printf.h"

void print_test (const char *name, int ret, int ret2)
{
    printf("test [%s] - ft (%d) - %d\n", name, ret, ret2);
}

int main(void)
{
    void *tmp = 0;

    // %%
    print_test("%%", ft_printf("%%\n"), printf("%%\n"));

    // % s
    print_test("%s", ft_printf("%s\n", "hello world !"), printf("%s\n", "hello world !"));
    print_test("%s", ft_printf("%s\n", 0), printf("%s\n", (char *)tmp));
    print_test("%10s", ft_printf("%10s\n", "hello world !"), printf("%10s\n", "hello world !"));
    print_test("%20s", ft_printf("%20s\n", "hello world !"), printf("%20s\n", "hello world !"));
    print_test("%-20s", ft_printf("%-20s\n", "hello world !"), printf("%-20s\n", "hello world !"));
    print_test("%-20.5s", ft_printf("%-20.5s\n", "hello world !"), printf("%-20.5s\n", "hello world !"));
    print_test("%20.5s", ft_printf("%20.5s\n", "hello world !"), printf("%20.5s\n", "hello world !"));

    // % S
    print_test("%S", ft_printf("%S\n", L"hello world !"), printf("%S\n", L"hello world !"));
    print_test("%S", ft_printf("%S\n", 0), printf("%S\n", (wchar_t *)tmp));
    print_test("%10S", ft_printf("%10S\n", L"hello world !"), printf("%10S\n", L"hello world !"));
    print_test("%20S", ft_printf("%20S\n", L"hello world !"), printf("%20S\n", L"hello world !"));
    print_test("%-20S", ft_printf("%-20S\n", L"hello world !"), printf("%-20S\n", L"hello world !"));
    print_test("%-20.5S", ft_printf("%-20.5S\n", L"hello world !"), printf("%-20.5S\n", L"hello world !"));
    print_test("%20.5S", ft_printf("%20.5S\n", L"hello world !"), printf("%20.5S\n", L"hello world !"));

    // % p
    print_test("%p", ft_printf("%p\n", &tmp), printf("%p\n", &tmp));
    print_test("%p", ft_printf("%p\n", tmp), printf("%p\n", tmp));
    print_test("%25p", ft_printf("%25p\n", &tmp), printf("%25p\n", &tmp));
    print_test("%-25p", ft_printf("%-25p\n", &tmp), printf("%-25p\n", &tmp));
    print_test("%25p", ft_printf("%25p\n", tmp), printf("%25p\n", tmp));

    // % d
    print_test("%d", ft_printf("%d\n", 10), printf("%d\n", 10));
    print_test("%d", ft_printf("%d\n", 0), printf("%d\n", 0));
    print_test("%+d", ft_printf("%+d\n", 0), printf("%+d\n", 0));
    print_test("%+d", ft_printf("%+d\n", -10), printf("%+d\n", -10));
    print_test("%0+d", ft_printf("%0+d\n", -10), printf("%0+d\n", -10));
    print_test("%0+d", ft_printf("%0+d\n", 10), printf("%0+d\n", 10));
    print_test("%0+ d", ft_printf("%0+d\n", -10), printf("%0+d\n", -10));
    print_test("%0+ d", ft_printf("%0+d\n", 10), printf("%0+d\n", 10));
    print_test("%0+15d", ft_printf("%0+15d\n", -10), printf("%0+15d\n", -10));
    print_test("%0+15d", ft_printf("%0+15d\n", 10), printf("%0+15d\n", 10));
    print_test("%0+15d", ft_printf("%0+15d\n", 10), printf("%0+15d\n", 10));
    print_test("%0-+15d", ft_printf("%0-+15d\n", 10), printf("%-+15d\n", 10));
    print_test("%0-15d", ft_printf("%0-15d\n", 10), printf("%-15d\n", 10));
    print_test("%0- 15d", ft_printf("%0- 15d\n", 10), printf("%- 15d\n", 10));
    print_test("%0+.5d", ft_printf("%0+.5d\n", -10), printf("%+.5d\n", -10));
    print_test("%0+.5d", ft_printf("%0+.5d\n", 10), printf("%+.5d\n", 10));
    print_test("%0+ .5d", ft_printf("%0+.5d\n", -10), printf("%+.5d\n", -10));
    print_test("%0+ .5d", ft_printf("%0+.5d\n", 10), printf("%+.5d\n", 10));
    print_test("%0+15.5d", ft_printf("%0+15.5d\n", -10), printf("%+15.5d\n", -10));
    print_test("%0+15.5d", ft_printf("%0+15.5d\n", 10), printf("%+15.5d\n", 10));
    print_test("%0+15.5d", ft_printf("%0+15.5d\n", 10), printf("%+15.5d\n", 10));
    print_test("%0-+15.5d", ft_printf("%0-+15.5d\n", 10), printf("%-+15.5d\n", 10));
    print_test("%0-15.5d", ft_printf("%0-15.5d\n", 10), printf("%-15.5d\n", 10));
    print_test("%0- 15.5d", ft_printf("%0- 15.5d\n", 10), printf("%- 15.5d\n", 10));
    return (0);
}
