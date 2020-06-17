#include <stdio.h>

//Dung de quy
long int giaithua (int n)
{
    if (n==1||n==0)
        return 1;
    return n*giaithua(n-1);
}

//Dung for
long int giaithua2 (int n)
{
    int i;
    long int gt;
    for (i=2,gt=1; i<=n; gt*=i++);
    return gt;
}

int main()
{
    int n;
    printf("\tNhap n: ");
    scanf("%d",&n);
    printf("\t%d! = %d",n,giaithua2(n));
    return 0;
}
