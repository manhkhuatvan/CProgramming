#include <stdio.h>

int main()
{
    double a, b, c, a1,b1,c1;
    printf("\tNhap vao 3 canh tam giac: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    if (a+b-c>0 && a+c-b>0 && b+c-a>0)
    {
        //Ktra tam giac deu
        if ((a==b)&&(a==c))
            printf("\t(%.1f, %.1f, %.1f) la tam giac deu",a,b,c);

        //Ktra tam giac can
        else if ((a==b)||(a==c)||(b==c))
        {
            a1 = a*a;
            b1 = b*b;
            c1 = c*c;
            //Ktra tam giac vuong can
            if((a1+b1==c1)||(a1+c1==b1)||(b1+c1==a1))
                printf("\t(%.1f, %.1f, %.1f) la tam giac vuong can",a,b,c);
            else
                printf("\t(%.1f, %.1f, %.1f) la tam giac can",a,b,c);
        }

        else
        {
            a1 = a*a;
            b1 = b*b;
            c1 = c*c;
            //Ktra tam giac vuong
            if((a1+b1==c1)||(a1+c1==b1)||(b1+c1==a1))
               printf("\t(%.1f, %.1f, %.1f) la tam giac vuong",a,b,c);

            //Tam giac thuong
            else
                printf("\t(%.1f, %.1f, %.1f) la tam giac thuong",a,b,c);
        }
    }
    else
        printf("\t(%.1f, %.1f, %.1f) khong phai 3 canh cua 1 tam giac",a,b,c);
    return 0;
}
