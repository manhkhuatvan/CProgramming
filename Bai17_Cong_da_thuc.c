#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define MAX 100

void Selection()
{
    printf("\t ______________________________________ \n");
    printf("\t|                MENU                  |\n");
    printf("\t|--------------------------------------|\n");
    printf("\t| 1 - Nhap he so da thuc               |\n");
    printf("\t| 2 - Tinh he so da thuc tong          |\n");
    printf("\t| 3 - In he so 3 da thuc               |\n");
    printf("\t| 4 - In gia tri 3 da thuc             |\n");
    printf("\t| 5 - Ket thuc                         |\n");
    printf("\t|______________________________________|\n");
    printf("\tVui long chon: ");
}

int Input_Num ()
{
    int n;
    do
    {
        scanf("%d",&n);
        if (n<0)
            printf("\t\aSo phan tu phai lon hon 0!!! Nhap lai: ");
    }
    while (n<0);
    return n;
}

//Nhap he so da thuc
void Input_Array (int a[], int n)
{
    int i;
    for (i=0; i<n; i++)
        scanf("%d",&a[i]);
}

//In he so da thuc
void Output_Array (int a[], int n)
{
    int i;
    printf("\t");
    for (i=0; i<n; i++)
    {
        printf("%4d",a[i]);
    }
    printf("\n");
}

//Tinh he so da thuc tong
void Sum_Polynomial(int a1[], int a2[], int a_sum[], int n)
{
    int i;
    for (i=0; i<n; a_sum[i]=a1[i]+a2[i++]);
}

//Tinh gia tri da thuc
float Calculate_Polynomial (int a[], float x, int n)
{
    int i;
    float sum = 0;
    for (i=n-1,sum=0; i>=0; i--)
    {
        sum+=a[i]*pow(x,n-i-1);
    }
    return sum;
}

void Loading()
{
    printf("\tLoading.");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(400);
}

void Menu()
{
    int select;
    int a1[MAX], a2[MAX], a_sum[MAX];
    int flag1 = 0;
    int flag2 = 0;
    int n;
    label:
    Selection();
    scanf("%d",&select);
    switch(select)
    {
        case 1:
            {
                printf("\tNhap so phan tu tung da thuc: ");
                n = Input_Num();
                printf("\tNhap he so da thuc thu nhat: ");
                Input_Array(a1,n);
                printf("\tBan da nhap xong da thuc thu nhat\n");
                printf("\tNhap he so da thuc thu hai: ");
                Input_Array(a2,n);
                printf("\tBan da nhap xong da thuc thu hai\n");
                flag1 = 1;
                Loading();
                system("cls");
                goto label;
                break;
            }
        case 2:
            {
                if (flag1==0)
                {
                    printf("\t\aNhap cac da thuc truoc!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                Sum_Polynomial(a1,a2,a_sum,n);
                flag2 = 1;
                Loading();
                system("cls");
                goto label;
            }
        case 3:
            {
                if (flag1==0)
                {
                    printf("\t\aNhap cac da thuc truoc!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                if (flag2==0)
                {
                    printf("\t\aTinh da thuc tong da!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                printf("\tHe so cac ma tran: \n",n);
                Output_Array(a1,n);
                Output_Array(a2,n);
                Output_Array(a_sum,n);
                printf("\tBam phim bat ki de chon tiep\n");
                getch();
                system("cls");
                goto label;
            }
        case 4:
            {
                if (flag1==0)
                {
                    printf("\t\aNhap cac da thuc truoc!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                if (flag2==0)
                {
                    printf("\t\aTinh da thuc tong da!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                float x;
                printf("\tNhap gia tri x: ");
                scanf("%f",&x);
                printf("\tGia tri cua da thuc 1 = %.2f\n",Calculate_Polynomial(a1,x,n));
                printf("\tGia tri cua da thuc 2 = %.2f\n",Calculate_Polynomial(a2,x,n));
                printf("\tGia tri cua da thuc tong = %.2f\n",Calculate_Polynomial(a_sum,x,n));
                Loading();
                system("cls");
                goto label;
            }
        case 5:
            {
                printf("\tBan da chon thoat. Xin chao!\n");
                Sleep(2000);
                exit(0);
            }
        default:
            {
                printf("\t\aNhap sai roi nhap lai di!!!\n");
                Loading();
                goto label;
            }
    }
}

int main()
{
    printf("\n");
    Loading();
    system("cls");
    Menu();
    return 0;
}

