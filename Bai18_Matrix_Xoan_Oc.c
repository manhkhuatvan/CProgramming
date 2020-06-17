#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define MAX 100

void Selection()
{
    printf("\t ______________________________________ \n");
    printf("\t|                MENU                  |\n");
    printf("\t|--------------------------------------|\n");
    printf("\t| 1 - Nhap n                           |\n");
    printf("\t| 2 - Tinh ma tran xoay                |\n");
    printf("\t| 3 - Hien thi ma tran xoay            |\n");
    printf("\t| 4 - Thoat                            |\n");
    printf("\t|______________________________________|\n");
    printf("\tVui long chon: ");
}
void Sort_Array (int a[], int n)
{
    int i, j, temp;
    for (i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if (a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void Input_Matrix (int m[MAX][MAX], int n)
{
    //Gan tung phan tu ma tran m
    int i, j;
    int top = 0;
    int left = 0;
    int bot = n-1;
    int right = n-1;
    j = 1;
    while (1)
    {
        for (i=left; i<=right; i++)
            m[top][i] = j++;
        top++;
        if (j>n*n)
            break;

        for (i=top; i<=bot; i++)
            m[i][right] = j++;
        right--;
        if (j>n*n)
            break;

        for (i=right; i>=left; i--)
            m[bot][i] = j++;
        bot--;
        if (j>n*n)
            break;

        for (i=bot; i>=top; i--)
            m[i][left] = j++;
        left++;
        if (j>n*n)
            break;
    }
}

//In ma tran
void Output_Matrix (int m[MAX][MAX], int n)
{
    int i, j;
    for (i=0; i<n; i++)
    {
        printf("\t\t");
        for (j=0; j<n; j++)
            printf("%4d",m[i][j]);
        printf("\n");
    }
}

//Nhap so nguyen duong
int Input_Num()
{
    int n;
    do
    {
        scanf("%d",&n);
        if (n<0)
            printf("\t\aNhap n >= 0. Nhap lai: ");
    }
    while (n<0);
    return n;
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
    int m[MAX][MAX];
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
                printf("\tNhap kich co ma tran: ");
                n = Input_Num();
                flag1 = 1;
                printf("\tBan da nhap ma tran vuong cap %d\n",n);
                Loading();
                system("cls");
                goto label;
                break;
            }
        case 2:
            {
                if (flag1==0)
                {
                    printf("\t\aNhap n truoc!!!\n");
                    goto label;
                }
                Input_Matrix(m,n);
                flag2 = 1;
                Loading();
                system("cls");
                goto label;
            }
        case 3:
            {
                if (flag1==0)
                {
                    printf("\t\aNhap n truoc!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                if (flag2==0)
                {
                    printf("\t\aTinh ma tran da!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                printf("\tMa tran xoay cap %d la: \n",n);
                Output_Matrix(m,n);
                printf("\t\tBam phim bat ky de chon tiep\n");
                getch();
                system("cls");
                goto label;
            }
        case 4:
            {
                printf("\tBan da chon thoat, xin chao!");
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
