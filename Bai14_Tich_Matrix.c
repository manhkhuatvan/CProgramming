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
    printf("\t| 1 - Nhap 2 ma tran                   |\n");
    printf("\t| 2 - Tinh tich 2 ma tran              |\n");
    printf("\t| 3 - In 3 ma tran                     |\n");
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
            printf("\t\aSo phai lon hon 0!!! Nhap lai: ");
    }
    while (n<0);
    return n;
}

//Nhap ma tran
void Input_Matrix (int m[][MAX], int r, int c)
{
    int i,j;
    for (i=0; i<r; i++)
        for (j=0; j<c; j++)
            scanf("%d",&m[i][j]);
}

//In matrix
void Output_Matrix (int m[][MAX], int r, int c)
{
    int i,j;

    for (i=0; i<r; i++)
    {
        printf("\t");
        for (j=0; j<c; j++)
            printf("%4d",m[i][j]);
        printf("\n");
    }
}

//Tinh tich 2 ma tran
void Multi_Matrix (int m1[][MAX], int m2[][MAX], int m_mul[][MAX], int r1, int n, int c2)
{
    int i, j, total, k;
    for (i=0; i<r1; i++)
    {
        for (j=0; j<c2; j++)
        {
            total = 0;
            int k;
            for (k=0; k<n; k++)
            {
                total += m1[i][k]*m2[k][j];
            }
            m_mul[i][j] = total;
        }
    }
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
    int m1[MAX][MAX], m2[MAX][MAX], m_mul[MAX][MAX];
    int flag1 = 0;
    int flag2 = 0;
    int r1, n, c2, temp;
    label:
    Selection();
    scanf("%d",&select);
    switch(select)
    {
        case 1:
            {
                printf("\tNhap cot, dong mang thu nhat: ");
                r1 = Input_Num();
                n = Input_Num();
                printf("\tNhap ma tran 1: ");
                Input_Matrix(m1,r1,n);
                printf("\tNhap cot, dong mang thu hai: ");
                do
                {
                    temp = Input_Num();
                    if (temp!=n)
                        printf("\tSo dong phai bang so dong ma tran truoc, nhap lai!!\n");
                }
                while (temp!=n);
                c2 = Input_Num();
                printf("\tNhap ma tran 2: ");
                Input_Matrix(m2,n,c2);
                printf("\tBan da nhap xong 2 ma tran\n");
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
                    printf("\t\aNhap cac ma tran!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                Multi_Matrix(m1,m2,m_mul,r1,n,c2);
                flag2 = 1;
                Loading();
                system("cls");
                goto label;
            }
        case 3:
            {
                if (flag1==0)
                {
                    printf("\t\aNhap ma tran truoc!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                if (flag2==0)
                {
                    printf("\t\aTinh tich da!!!\n");
                    Loading();
                    system("cls");
                    goto label;
                }
                printf("\tBa ma tran la: \n");
                Output_Matrix(m1,r1,n);
                printf("\n");
                Output_Matrix(m2,n,c2);
                printf("\n");
                Output_Matrix(m_mul,r1,c2);
                printf("\n");
                printf("\tBam phim bat ki de chon tiep\n");
                getch();
                system("cls");
                goto label;
            }
        case 4:
            {
                printf("\tBan da chon thoat. Xin chao!\n");
                Sleep(1000);
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

