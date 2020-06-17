#include <stdio.h>
#define MAX 100

int Input_Array (int*);
void Output_Array (int*, int);
void Find_Max_Min_Position (int*, int, int*, int*, int*, int*);

//Nhap mang
int Input_Array (int a[])
{
    int n, i;
    printf("\tNhap n: ");
    scanf("%d",&n);
    for (i=0; i<n; i++)
    {
        printf("\t\ta[%d] = ",i);
        scanf("%d",&a[i]);
    }
    return n;
}

//In mang
void Output_Array (int a[], int n)
{
    int i;
    printf("\t");
    for (i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
}

//Tim max, min, tim vi tri max min
void Find_Max_Min_Position (int a[], int n, int* max, int* min, int* pos_max, int* pos_min)
{
    int i;
    *max = *min = a[0];
    *pos_max = *pos_min = 0;
    for (i=1; i<n; i++)
    {
        if (a[i]>*max)
        {
            *max = a[i];
            *pos_max = i;
        }
        if (a[i]<*min)
        {
            *min = a[i];
            *pos_min = i;
        }
    }
}

int main()
{
    int a[MAX];
    int max, min, pos_max, pos_min;
    int n = Input_Array (a);
    printf("\tMang vua nhap la: \n");
    Output_Array(a,n);
    Find_Max_Min_Position(a,n,&max,&min,&pos_max,&pos_min);
    printf("\tGia tri max la a[%d] = %d\n",pos_max+1,max);
    printf("\tGia tri min la a[%d] = %d\n",pos_min+1,min);
    return 0;
}
