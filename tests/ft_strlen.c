extern int _ft_strlen(char *s);

#include <string.h>
#include <stdio.h>

int test(char *s, int c)
{
    int real;
    int ours;
    
    real = 0;
    if (s)
        real = strlen(s);
    ours = _ft_strlen(s);
    printf("Test %d:\t\t{%s} ",c,s);
    printf("real: %d\tours: %d\n",real, ours);

    if (real - ours != 0)
    {
        printf("\033[0;31m ERROR! NOT THE SAME!!!!\033[0m\n");
    }
}

int main(void)
{
    int c;

    c = 0;
    test("Hello World!", c++);
    test("", c++);
    test(0, c++);
    test("\1\1\1\1\\1\1", c++);
    test("test", c++);
    test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum elementum aliquet vehicula. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Duis viverra tempor est id malesuada. Proin et magna nisl. Praesent mattis commodo sem et faucibus. Praesent odio lorem, tempus tincidunt augue nec, commodo commodo justo. Nulla finibus libero eu eros ultrices, non dignissim leo dapibus.", c++);    return (0);
    test(0, c++);
    return (0);
}