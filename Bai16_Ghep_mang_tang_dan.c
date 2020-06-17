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
    printf("\t| 1 - Nhap 2 mang tang dan             |\n");
    printf("\t| 2 - Ghep 2 day                       |\n");
    printf("\t| 3 - In 3 day so                      |\n");
    printf("\t| 4 - Ket thuc                         |\n");
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

//Nhap mang
void Input_Array (int a[], int n)
{
    int i;
    for (i=0; i<n; i++)
        scanf("%d",&a[i]);
}

//In mang
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

//Ghep 2 mang, gia ve do dai mang tong
int Merge_Array (int a1[], int a2[], int asum[], int n1, int n2)
{
    int nsum;
    int i,j,k;
    a1[n1] = 1<<30;
    a2[n2] = 1<<30;
    for (i=0,j=0,k=0; k<n1+n2;)
        asum[k++] = a1[i]<a2[j]?a1[i++]:a2[j++];
    return k;
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
    int n1,n2,nsum;
    label:
    Selection();
    scanf("%d",&select);
    switch(select)
    {
        case 1:
            {
                printf("\tNhap so phan tu mang 1: ");
                n1 = Input_Num();
                printf("\tNhap mang 1: ");
                Input_Array(a1,n1);
                printf("\tNhap so phan tu mang 2: ");
                n2 = Input_Num();
                printf("\tNhap mang 2: ");
                Input_Array(a2,n2);
                printf("\tBan da nhap xong 2 mang\n");
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
                    printf("\t\aNhap mang da!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                nsum = Merge_Array(a1,a2,a_sum,n1,n2);
                flag2 = 1;
                Loading();
                system("cls");
                goto label;
            }
        case 3:
            {
                if (flag1==0)
                {
                    printf("\t\aNhap mang truoc!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                if (flag2==0)
                {
                    printf("\t\aGhep mang da!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                printf("\tBa mang vua nhap la: \n");
                Output_Array(a1,n1);
                Output_Array(a2,n2);
                Output_Array(a_sum,nsum);
                printf("\tBam phim bat ki de chon tiep\n");
                getch();
                system("cls");
                goto label;
            }
        case 4:
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

