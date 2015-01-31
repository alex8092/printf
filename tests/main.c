#include <stdio.h>
#include <wchar.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ft_printer.h"

void    print_test(const char *name, int ret, int ret2)
{
    printf("test [%s] - ft (%d) - %d\n", name, ret, ret2);
}
# define TEST_PRINTF(X, Y) \
{ \
    ssize_t     ret; \
    ssize_t     ret2; \
    char        buf[2048]; \
    char        buf2[2048]; \
    int fd = open("test.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0777); \
    int fd2 = open("test2.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0777); \
    ft_printer_init(fd); \
    ret = ft_printf(X, Y); \
    ft_printer_init(1); \
    ret2 = dprintf(fd2, X, Y); \
    close(fd); \
    close(fd2); \
    fd = open("test.tmp", O_RDONLY); \
    fd2 = open("test2.tmp", O_RDONLY); \
    read(fd, buf, ret); \
    read(fd2, buf2, ret); \
    buf[ret] = 0; \
    buf2[ret2] = 0; \
    close(fd); \
    close(fd2); \
    if (ret == ret2 && ft_strcmp(buf, buf2)) { \
        printf("test[%s] -> \033[33mFAIL\033[0m { \"%.*s\", \"%.*s\" }\n", X, (int)ret, buf, (int)ret, buf2); \
    } \
    else if (ret == ret2) { \
        printf("test[%s] -> OK { \"%.*s\", \"%.*s\" }\n", X, (int)ret, buf, (int)ret, buf2); \
    } else {
        printf("test[%s] -> \033[33mFAIL RETURN\033[0m { \"%.*s\", \"%.*s\" }\n", X, (int)ret, buf, (int)ret, buf2);
    } \
} \

ssize_t    ft_wstrcmp(wchar_t *s1, wchar_t *s2)
{
    size_t i;

    i = 0;
    while (s1[i] && s1[i] == s2[i])
        ++i;
    return (s2[i] - s1[i]);
}

int main(void)
{
    void *tmp = 0;

    // %%
    TEST_PRINTF("%%", 0);

    // % s
    TEST_PRINTF("%s", "hello world !");
    TEST_PRINTF("%s", (char *)tmp);
    TEST_PRINTF("%10s", "hello world !");
    TEST_PRINTF("%20s", "hello world !");
    TEST_PRINTF("%-20s", "hello world !");
    TEST_PRINTF("%-20.5s", "hello world !");
    TEST_PRINTF("%20.5s", "hello world !");

    // % S
    // TEST_PRINTF("%S", L"hello world !");
    // TEST_PRINTF("%S", (wchar_t*)0);
    // print_test("%S", ft_printf("%S\n", L"hello world !"), printf("%S\n", L"hello world !"));
    // print_test("%S", ft_printf("%S\n", 0), printf("%S\n", (wchar_t *)tmp));
    // print_test("%10S", ft_printf("%10S\n", L"hello world !"), printf("%10S\n", L"hello world !"));
    // print_test("%20S", ft_printf("%20S\n", L"hello world !"), printf("%20S\n", L"hello world !"));
    // print_test("%-20S", ft_printf("%-20S\n", L"hello world !"), printf("%-20S\n", L"hello world !"));
    // print_test("%-20.5S", ft_printf("%-20.5S\n", L"hello world !"), printf("%-20.5S\n", L"hello world !"));
    // print_test("%20.5S", ft_printf("%20.5S\n", L"hello world !"), printf("%20.5S\n", L"hello world !"));

    // % p
    TEST_PRINTF("%p", &tmp);
    TEST_PRINTF("%p", tmp);
    TEST_PRINTF("%25p", &tmp);
    TEST_PRINTF("%-25p", &tmp);
    TEST_PRINTF("%25p", tmp);

    // % d
    TEST_PRINTF("%d", 10);
    TEST_PRINTF("%d", 0);
    TEST_PRINTF("%+d", 0);
    TEST_PRINTF("%+d", -10);
    TEST_PRINTF("%0+d", -10);
    TEST_PRINTF("%0+d", 10);
    TEST_PRINTF("%0+ d", -10);
    TEST_PRINTF("%0+ d", 10);
    TEST_PRINTF("%0+15d", -10);
    TEST_PRINTF("%0+15d", 10);
    TEST_PRINTF("%0-+15d", 10);
    TEST_PRINTF("%0-15d", 10);
    TEST_PRINTF("%0- 15d", 10);
    TEST_PRINTF("%0+.5d", -10);
    TEST_PRINTF("%0+.5d", 10);
    TEST_PRINTF("%0+ .5d", -10);
    TEST_PRINTF("%0+ .5d", 10);
    TEST_PRINTF("%0+15.5d", -10);
    TEST_PRINTF("%0+15.5d", 10);
    TEST_PRINTF("%0+15.5d", 10);
    TEST_PRINTF("%0-+15.5d", 10);
    TEST_PRINTF("%0-15.5d", 10);
    TEST_PRINTF("%0- 15.5d", 10);

    // % i
    TEST_PRINTF("%i", 10);
    TEST_PRINTF("%i", 0);
    TEST_PRINTF("%+i", 0);
    TEST_PRINTF("%+i", -10);
    TEST_PRINTF("%0+i", -10);
    TEST_PRINTF("%0+i", 10);
    TEST_PRINTF("%0+ i", -10);
    TEST_PRINTF("%0+ i", 10);
    TEST_PRINTF("%0+15i", -10);
    TEST_PRINTF("%0+15i", 10);
    TEST_PRINTF("%0-+15i", 10);
    TEST_PRINTF("%0-15i", 10);
    TEST_PRINTF("%0- 15i", 10);
    TEST_PRINTF("%0+.5i", -10);
    TEST_PRINTF("%0+.5i", 10);
    TEST_PRINTF("%0+ .5i", -10);
    TEST_PRINTF("%0+ .5i", 10);
    TEST_PRINTF("%0+15.5i", -10);
    TEST_PRINTF("%0+15.5i", 10);
    TEST_PRINTF("%0+15.5i", 10);
    TEST_PRINTF("%0-+15.5i", 10);
    TEST_PRINTF("%0-15.5i", 10);
    TEST_PRINTF("%0- 15.5i", 10);

    // % D
    TEST_PRINTF("%D", 10);
    TEST_PRINTF("%D", 0);
    TEST_PRINTF("%+D", 0);
    TEST_PRINTF("%+D", -10);
    TEST_PRINTF("%0+D", -10);
    TEST_PRINTF("%0+D", 10);
    TEST_PRINTF("%0+ D", -10);
    TEST_PRINTF("%0+ D", 10);
    TEST_PRINTF("%0+15D", -10);
    TEST_PRINTF("%0+15D", 10);
    TEST_PRINTF("%0-+15D", 10);
    TEST_PRINTF("%0-15D", 10);
    TEST_PRINTF("%0- 15D", 10);
    TEST_PRINTF("%0+.5D", -10);
    TEST_PRINTF("%0+.5D", 10);
    TEST_PRINTF("%0+ .5D", -10);
    TEST_PRINTF("%0+ .5D", 10);
    TEST_PRINTF("%0+15.5D", -10);
    TEST_PRINTF("%0+15.5D", 10);
    TEST_PRINTF("%0+15.5D", 10);
    TEST_PRINTF("%0-+15.5D", 10);
    TEST_PRINTF("%0-15.5D", 10);
    TEST_PRINTF("%0- 15.5D", 10);

    // % u
    TEST_PRINTF("%u", 10);
    TEST_PRINTF("%u", 0);
    TEST_PRINTF("%+u", 0);
    TEST_PRINTF("%+u", -10);
    TEST_PRINTF("%0+u", -10);
    TEST_PRINTF("%0+u", 10);
    TEST_PRINTF("%0+ u", -10);
    TEST_PRINTF("%0+ u", 10);
    TEST_PRINTF("%0+15u", -10);
    TEST_PRINTF("%0+15u", 10);
    TEST_PRINTF("%0-+15u", 10);
    TEST_PRINTF("%0-15u", 10);
    TEST_PRINTF("%0- 15u", 10);
    TEST_PRINTF("%0+.5u", -10);
    TEST_PRINTF("%0+.5u", 10);
    TEST_PRINTF("%0+ .5u", -10);
    TEST_PRINTF("%0+ .5u", 10);
    TEST_PRINTF("%0+15.5u", -10);
    TEST_PRINTF("%0+15.5u", 10);
    TEST_PRINTF("%0+15.5u", 10);
    TEST_PRINTF("%0-+15.5u", 10);
    TEST_PRINTF("%0-15.5u", 10);
    TEST_PRINTF("%0- 15.5u", 10);

    // % U
    TEST_PRINTF("%U", 10);
    TEST_PRINTF("%U", 0);
    TEST_PRINTF("%+U", 0);
    TEST_PRINTF("%+U", -10);
    TEST_PRINTF("%0+U", -10);
    TEST_PRINTF("%0+U", 10);
    TEST_PRINTF("%0+ U", -10);
    TEST_PRINTF("%0+ U", 10);
    TEST_PRINTF("%0+15U", -10);
    TEST_PRINTF("%0+15U", 10);
    TEST_PRINTF("%0-+15U", 10);
    TEST_PRINTF("%0-15U", 10);
    TEST_PRINTF("%0- 15U", 10);
    TEST_PRINTF("%0+.5U", -10);
    TEST_PRINTF("%0+.5U", 10);
    TEST_PRINTF("%0+ .5U", -10);
    TEST_PRINTF("%0+ .5U", 10);
    TEST_PRINTF("%0+15.5U", -10);
    TEST_PRINTF("%0+15.5U", 10);
    TEST_PRINTF("%0+15.5U", 10);
    TEST_PRINTF("%0-+15.5U", 10);
    TEST_PRINTF("%0-15.5U", 10);
    TEST_PRINTF("%0- 15.5U", 10);

    // % o
    TEST_PRINTF("%o", 10);
    TEST_PRINTF("%o", 0);
    TEST_PRINTF("%+o", 0);
    TEST_PRINTF("%+o", -10);
    TEST_PRINTF("%0+o", -10);
    TEST_PRINTF("%0+o", 10);
    TEST_PRINTF("%0+ o", -10);
    TEST_PRINTF("%0+ o", 10);
    TEST_PRINTF("%0+15o", -10);
    TEST_PRINTF("%0+15o", 10);
    TEST_PRINTF("%0-+15o", 10);
    TEST_PRINTF("%0-15o", 10);
    TEST_PRINTF("%0- 15o", 10);
    TEST_PRINTF("%0+.5o", -10);
    TEST_PRINTF("%0+.5o", 10);
    TEST_PRINTF("%0+ .5o", -10);
    TEST_PRINTF("%0+ .5o", 10);
    TEST_PRINTF("%0+15.5o", -10);
    TEST_PRINTF("%0+15.5o", 10);
    TEST_PRINTF("%0+15.5o", 10);
    TEST_PRINTF("%0-+15.5o", 10);
    TEST_PRINTF("%0-15.5o", 10);
    TEST_PRINTF("%0- 15.5o", 10);
    TEST_PRINTF("%#o", 10);
    TEST_PRINTF("%#o", 0);
    TEST_PRINTF("%#+o", 0);
    TEST_PRINTF("%#+o", -10);
    TEST_PRINTF("%#0+o", -10);
    TEST_PRINTF("%#0+o", 10);
    TEST_PRINTF("%#0+ o", -10);
    TEST_PRINTF("%#0+ o", 10);
    TEST_PRINTF("%#0+15o", -10);
    TEST_PRINTF("%#0+15o", 10);
    TEST_PRINTF("%#0-+15o", 10);
    TEST_PRINTF("%#0-15o", 10);
    TEST_PRINTF("%#0- 15o", 10);
    TEST_PRINTF("%#0+.5o", -10);
    TEST_PRINTF("%#0+.5o", 10);
    TEST_PRINTF("%#0+ .5o", -10);
    TEST_PRINTF("%#0+ .5o", 10);
    TEST_PRINTF("%#0+15.5o", -10);
    TEST_PRINTF("%#0+15.5o", 10);
    TEST_PRINTF("%#0+15.5o", 10);
    TEST_PRINTF("%#0-+15.5o", 10);
    TEST_PRINTF("%#0-15.5o", 10);
    TEST_PRINTF("%#0- 15.5o", 10);

    // % O
    TEST_PRINTF("%O", 10);
    TEST_PRINTF("%O", 0);
    TEST_PRINTF("%+O", 0);
    TEST_PRINTF("%+O", -10);
    TEST_PRINTF("%0+O", -10);
    TEST_PRINTF("%0+O", 10);
    TEST_PRINTF("%0+ O", -10);
    TEST_PRINTF("%0+ O", 10);
    TEST_PRINTF("%0+15O", -10);
    TEST_PRINTF("%0+15O", 10);
    TEST_PRINTF("%0-+15O", 10);
    TEST_PRINTF("%0-15O", 10);
    TEST_PRINTF("%0- 15O", 10);
    TEST_PRINTF("%0+.5O", -10);
    TEST_PRINTF("%0+.5O", 10);
    TEST_PRINTF("%0+ .5O", -10);
    TEST_PRINTF("%0+ .5O", 10);
    TEST_PRINTF("%0+15.5O", -10);
    TEST_PRINTF("%0+15.5O", 10);
    TEST_PRINTF("%0+15.5O", 10);
    TEST_PRINTF("%0-+15.5O", 10);
    TEST_PRINTF("%0-15.5O", 10);
    TEST_PRINTF("%0- 15.5O", 10);
    TEST_PRINTF("%#O", 10);
    TEST_PRINTF("%#O", 0);
    TEST_PRINTF("%#+O", 0);
    TEST_PRINTF("%#+O", -10);
    TEST_PRINTF("%#0+O", -10);
    TEST_PRINTF("%#0+O", 10);
    TEST_PRINTF("%#0+ O", -10);
    TEST_PRINTF("%#0+ O", 10);
    TEST_PRINTF("%#0+15O", -10);
    TEST_PRINTF("%#0+15O", 10);
    TEST_PRINTF("%#0-+15O", 10);
    TEST_PRINTF("%#0-15O", 10);
    TEST_PRINTF("%#0- 15O", 10);
    TEST_PRINTF("%#0+.5O", -10);
    TEST_PRINTF("%#0+.5O", 10);
    TEST_PRINTF("%#0+ .5O", -10);
    TEST_PRINTF("%#0+ .5O", 10);
    TEST_PRINTF("%#0+15.5O", -10);
    TEST_PRINTF("%#0+15.5O", 10);
    TEST_PRINTF("%#0+15.5O", 10);
    TEST_PRINTF("%#0-+15.5O", 10);
    TEST_PRINTF("%#0-15.5O", 10);
    TEST_PRINTF("%#0- 15.5O", 10);

    // % x
    TEST_PRINTF("%x", 10);
    TEST_PRINTF("%x", 0);
    TEST_PRINTF("%+x", 0);
    TEST_PRINTF("%+x", -10);
    TEST_PRINTF("%0+x", -10);
    TEST_PRINTF("%0+x", 10);
    TEST_PRINTF("%0+ x", -10);
    TEST_PRINTF("%0+ x", 10);
    TEST_PRINTF("%0+15x", -10);
    TEST_PRINTF("%0+15x", 10);
    TEST_PRINTF("%-+15x", 10);
    TEST_PRINTF("%-15x", 10);
    TEST_PRINTF("%- 15x", 10);
    TEST_PRINTF("%0+.5x", -10);
    TEST_PRINTF("%0+.5x", 10);
    TEST_PRINTF("%0+ .5x", -10);
    TEST_PRINTF("%0+ .5x", 10);
    TEST_PRINTF("%0+15.5x", -10);
    TEST_PRINTF("%0+15.5x", 10);
    TEST_PRINTF("%0+15.5x", 10);
    TEST_PRINTF("%-+15.5x", 10);
    TEST_PRINTF("%-15.5x", 10);
    TEST_PRINTF("%- 15.5x", 10);
    TEST_PRINTF("%#x", 10);
    TEST_PRINTF("%#x", 0);
    TEST_PRINTF("%#+x", 0);
    TEST_PRINTF("%#+x", -10);
    TEST_PRINTF("%#0+x", -10);
    TEST_PRINTF("%#0+x", 10);
    TEST_PRINTF("%#0+ x", -10);
    TEST_PRINTF("%#0+ x", 10);
    TEST_PRINTF("%#0+15x", -10);
    TEST_PRINTF("%#0+15x", 10);
    TEST_PRINTF("%#0-+15x", 10);
    TEST_PRINTF("%#0-15x", 10);
    TEST_PRINTF("%#- 15x", 10);
    TEST_PRINTF("%#0+.5x", -10);
    TEST_PRINTF("%#0+.5x", 10);
    TEST_PRINTF("%#0+ .5x", -10);
    TEST_PRINTF("%#0+ .5x", 10);
    TEST_PRINTF("%#0+15.5x", -10);
    TEST_PRINTF("%#0+15.5x", 10);
    TEST_PRINTF("%#0+15.5x", 10);
    TEST_PRINTF("%#-+15.5x", 10);
    TEST_PRINTF("%#-15.5x", 10);
    TEST_PRINTF("%#- 15.5x", 10);

    // % X
    TEST_PRINTF("%X", 10);
    TEST_PRINTF("%X", 0);
    TEST_PRINTF("%+X", 0);
    TEST_PRINTF("%+X", -10);
    TEST_PRINTF("%0+X", -10);
    TEST_PRINTF("%0+X", 10);
    TEST_PRINTF("%0+15X", -10);
    TEST_PRINTF("%0+15X", 10);
    TEST_PRINTF("%-+15X", 10);
    TEST_PRINTF("%-15X", 10);
    TEST_PRINTF("%- 15X", 10);
    TEST_PRINTF("%0+.5X", -10);
    TEST_PRINTF("%0+.5X", 10);
    TEST_PRINTF("%0+ .5X", -10);
    TEST_PRINTF("%0+ .5X", 10);
    TEST_PRINTF("%0+15.5X", -10);
    TEST_PRINTF("%0+15.5X", 10);
    TEST_PRINTF("%0+15.5X", 10);
    TEST_PRINTF("%-+15.5X", 10);
    TEST_PRINTF("%-15.5X", 10);
    TEST_PRINTF("%#X", 10);
    TEST_PRINTF("%#X", 0);
    TEST_PRINTF("%#+X", 0);
    TEST_PRINTF("%#+X", -10);
    TEST_PRINTF("%#0+X", -10);
    TEST_PRINTF("%#0+X", 10);
    TEST_PRINTF("%#0+15X", -10);
    TEST_PRINTF("%#0+15X", 10);
    TEST_PRINTF("%#-+15X", 10);
    TEST_PRINTF("%#-15X", 10);
    TEST_PRINTF("%#0+.5X", -10);
    TEST_PRINTF("%#0+.5X", 10);
    TEST_PRINTF("%#0+15.5X", -10);
    TEST_PRINTF("%#0+15.5X", 10);
    TEST_PRINTF("%#0+15.5X", 10);
    TEST_PRINTF("%#-+15.5X", 10);
    TEST_PRINTF("%#-15.5X", 10);

    // % c
    TEST_PRINTF("%c", 'a');
    TEST_PRINTF("%c", 0);
<<<<<<< HEAD
    TEST_PRINTF("%+c", 0);
    TEST_PRINTF("%+c", 'z');
    TEST_PRINTF("%+c", 'z');
    TEST_PRINTF("%+c", 'a');
    TEST_PRINTF("%+ c", 'z');
    TEST_PRINTF("%+ c", 'a');
    TEST_PRINTF("%+15c", 'z');
    TEST_PRINTF("%+15c", 'a');
    TEST_PRINTF("%-+15c", 'a');
    TEST_PRINTF("%-15c", 'a');
    TEST_PRINTF("%- 15c", 'a');
    TEST_PRINTF("%+.5c", 'z');
    TEST_PRINTF("%+.5c", 'a');
    TEST_PRINTF("%+ .5c", 'z');
    TEST_PRINTF("%+ .5c", 'a');
    TEST_PRINTF("%+15.5c", 'z');
    TEST_PRINTF("%+15.5c", 'a');
    TEST_PRINTF("%+15.5c", 'a');
    TEST_PRINTF("%-+15.5c", 'a');
    TEST_PRINTF("%-15.5c", 'a');
    TEST_PRINTF("%- 15.5c", 'a');
=======
    TEST_PRINTF("%15c", 'z');
    TEST_PRINTF("%15c", 'a');
    TEST_PRINTF("%-15c", 'a');
    TEST_PRINTF("%-15c", 'z');
    TEST_PRINTF("%c", 200);

    TEST_PRINTF("%llX", (unsigned long long)-1);
>>>>>>> 195d2272b5419a4481857e0c038d21e8eedd45ff
    return (0);
}
