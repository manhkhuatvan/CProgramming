#include <stdio.h>
#include <malloc.h>
#include <math.h>

int** Input_Matrix (int* r, int* c)
{
    int i, j;
    //r = row la so dong, c = column = so cot
    printf("\tNhap so dong, cot: ");
    scanf("%d%d",r,c);

    //Cap phat dong cho matrix m
    int** m;
    m = (int**)malloc ((*r)*sizeof(int*));
    for (i=0; i<*r; i++)
        m[i] = (int*)malloc ((*c)*sizeof(int));

    //Nhap tung phan tu cua matrix m
    printf("\tNhap tung phan tu cua ma tran:\n");
    for (i=0; i<*r; i++)
        for (j=0; j<*c; j++)
            scanf("%d",&m[i][j]);
    return m;
}

//In ma tran
void Output_Matrix (int** m, int r, int c)
{
    int i, j;
    for (i=0; i<r; i++)
    {
        printf("\t");
        for (j=0; j<c;j++)
            printf("%4d",m[i][j]);
        printf("\n");
    }
}

//Tim max, min
void Find_Max_Min (int** m, int r, int c, int* max, int* min)
{
    int i, j;
    *max = *min = m[0][0];
    for (i=0; i<r; i++)
        for (j=0; j<c; j++)
        {
            if (m[i][j]<*min)
                *min = m[i][j];
            if (m[i][j]>*max)
                *max = m[i][j];
        }
}

//Kiem tra n co phai so nguyen to hay khong, gia ve 1 neu co
int _Is_Prime (int n)
{
    if (n<2)
        return 0;
    int i;
    int can = sqrt(n);
    for (i=2; i<=can; i++)
        if (n%i==0)
            return 0;
    return 1;
}

//Tinh tong cac so nguyen to
int Sum_Prime_of_Matrix (int** m, int r, int c)
{
    int tong;
    int i, j;
    for (i=0,tong=0;i<r;i++)
        for (j=0;j<c;j++)
            if (_Is_Prime(m[i][j]))
                tong+= m[i][j];
    return tong;
}

int main()
{
    int r, c, max, min;
    int** m = NULL;
    m = Input_Matrix(&r,&c);
    printf("\tMa tran vua nhap la: \n");
    Output_Matrix(m,r,c);
    Find_Max_Min(m,r,c,&max,&min);
    printf("\tMax = %d, min = %d\n",max,min);
    printf("\tTong cac SNT trong ma tran la: %d",Sum_Prime_of_Matrix(m,r,c));
    return 0;
}
