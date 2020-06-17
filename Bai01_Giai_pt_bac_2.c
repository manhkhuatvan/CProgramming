#include <stdio.h>
#include <math.h>

int pt_bac2 (float a, float b, float c, float* x1, float* x2)
{
    float delta;
    if (a==0)
        if (b==0)
            if (c==0)
                return 3;
            else
                return 0;
        else
        {
            *x1 = -c/b;
            *x2 = *x1 + 1;
            return 1;
        }
    else
    {
        delta = b*b - 4*a*c;
        if (delta<0)
            return 0;
        else if (delta==0)
        {
            *x1 = *x2 = -b/(2*a);
            return 1;
        }
        else
        {
            float can = sqrt(delta);
            *x1 = (-b + can)/(2*a);
            *x2 = (-b - can)/(2*a);
            return 2;
        }
    }
}


int main()
{
    float a,b,c,x1,x2;
    int so_nghiem;
    printf("\tNhap a, b, c: ");
    scanf("%f%f%f",&a,&b,&c);
    so_nghiem = pt_bac2 (a,b,c,&x1,&x2);
    switch (so_nghiem)
    {
        case 0:
            {
                printf("\tPhuong trinh vo nghiem\n");
                break;
            }
        case 1:
            {
                if (x1==x2)
                    printf("\tPhuong trinh co nghiem kep x1 = x2 = %.2f\n",x1);
                else
                    printf("\tPhuong trinh co mot nghiem x = %.2f\n",x1);
                break;
            }
        case 2:
            {
                printf("\tPhuong trinh co 2 nghiem phan biet x1 = %.2f, x2 = %.2f\n",x1,x2);
                break;
            }
        default:
            {
                printf("\tPhuong trinh vo so nghiem\n");
                break;
            }
    }
    return 0;
}
