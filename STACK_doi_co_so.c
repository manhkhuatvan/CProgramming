#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100

typedef struct
{
    int top;
    int Data[MAX];
}TStack;

//refresh stack
void create_stack (TStack* Stack)
{
    Stack->top = 0;
}

int Is_empty(TStack* Stack)
{
    return (Stack->top == 0);
}

int Is_full (TStack* Stack)
{
    return (Stack->top == MAX);
}

void Push (TStack* Stack, int x)
{
    if (!Is_full(Stack))
    {
        Stack->Data[Stack->top] = x;
        Stack->top++;
    }
}

int Peak (TStack* Stack)
{
    return Stack->Data[Stack->top-1];
}

int Pop (TStack* Stack)
{
    if (!Is_empty(Stack))
    {
        Stack->top--;
        return Stack->Data[Stack->top];
    }
}

void Input_Stack (TStack* Stack)
{
    int x;
    while (1)
    {
        printf("\tNhap phan tu: ");
        scanf("%d",&x);
        Push(Stack,x);
        printf("\tNhap tiep? y/n: ");
        fflush(stdin);
        char tmp = getchar();
        if (tmp=='n'||tmp=='N')
            break;
    }
}

void Output_Stack (TStack* Stack)
{
    int i;
    for (i=Stack->top-1; i>=0; i--)
        printf("%d",Stack->Data[i]);
}

void He_co_so_2 (TStack* Stack, int n)
{
    while (n>0)
    {
        Push(Stack,n%2);
        n/=2;
    }
}

void He_co_so_8 (TStack* Stack, int n)
{
    while (n>0)
    {
        Push(Stack,n%8);
        n/=8;
    }
}

void menu()
{
    printf("\t ____________________________________________________ \n");
    printf("\t|                         MENU                       |\n");
    printf("\t|----------------------------------------------------|\n");
    printf("\t| 1. Nhap n                                          |\n");
    printf("\t| 2. Chuyen sang he co so 2                          |\n");
    printf("\t| 3. Chuyen sang he co so 8                          |\n");
    printf("\t| 4. Chuyen sang he co so 16                         |\n");
    printf("\t| 0. Exit                                            |\n");
    printf("\t|____________________________________________________|\n");
    printf("\t\tVui long chon: ");
}

int main()
{
    int n;
    int chon;
    TStack Stack;
    create_stack(&Stack);
    while (1)
    {
        menu();
        scanf("%d",&chon);
        switch (chon)
        {
            case 1:
                printf("\tBan da chon nhap n \n");
                printf("\t\tNhap n: ");
                scanf("%d",&n);
                break;
            case 2:
                printf("\tBan da chon doi sang co so 2\n");
                He_co_so_2(&Stack,n);
                printf("\t\t%d(10) = ",n);
                Output_Stack(&Stack);
                printf("(2)\n");
                create_stack(&Stack);
                break;
            case 3:
                printf("\tBan da chon doi sang co so 8\n");
                He_co_so_8(&Stack,n);
                printf("\t\t%d(10) = ",n);
                Output_Stack(&Stack);
                printf("(8)\n");
                create_stack(&Stack);
                break;
            case 4:
                printf("\tBan da chon doi sang co so 16\n");
                printf("\t\t%d(10) = 0x%x(16)\n",n,n);
                break;
            case 0:
                exit(0);
            default:
                printf("\tBan da chon sai, vui long chon lai\n\a");
                break;
        }
        getch();
        system("cls");
    }
    return 0;
}
