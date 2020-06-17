#include <stdio.h>
int ucln (unsigned int a, unsigned int b)
{
    unsigned int temp;
    while (b)
    {
        temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int bcln (unsigned int a, unsigned int b)
{
    unsigned int bcln = a*b/(ucln(a,b));
    return bcln;
}

int main()
{
    unsigned int a, b;
    printf("\tNhap a, b: ");
    scanf ("%u %u",&a,&b);
    printf ("\tBCLN(%u, %u) = %u",a,b,bcln(a,b));
    return 0;
}
