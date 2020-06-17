#include <stdio.h>
#define MAX 100

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

//Sap xep mang
void Sort_Ascending (int a[], int n)
{
    int i, j, temp;
    //Sap xep chon
    for (i=0; i<n-1; i++)
        for (j=i+1; j<n; j++)
            if (a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main()
{
    int a[MAX];
    int n = Input_Array(a);
    printf("\tDay so vua nhap la: \n");
    Output_Array(a,n);
    Sort_Ascending(a,n);
    printf("\tDay so sau khi sap xep tang dan la: \n");
    Output_Array(a,n);
    return 0;
}
