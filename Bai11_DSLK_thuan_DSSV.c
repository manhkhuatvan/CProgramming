#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[25];
    int age;
    float avg_mark;
}SinhVien;

typedef struct NODE{
    SinhVien Data;
    struct NODE* Next;
}NODE;

typedef struct {
    NODE* first;
    NODE* last;
}TList;

//Khoi tao NODE
NODE* KhoitaoNode()
{
    NODE* x = (NODE*)malloc(sizeof(NODE));
    if(x == NULL)
    {
        printf("\tBo nho khong du ");
        return 0;
    }
    x->Next = NULL;
    return x;
}

//Khoi tao danh sach LISTSV
void KhoitaoList(TList* x)
{
    x->first = NULL;
    x->last = NULL;
}

//Nhap thong tin sinh vien ke ca ten
void Nhap (NODE* x)
{
    char tg[25];
    int tuoi;
    float diem;
    fflush(stdin);
    printf("\tNhap ten Sinh Vien: ");
    gets(tg);
    strcpy(x->Data.name,tg);
    fflush(stdin);
    do
    {
        printf("\tTuoi: ");
        scanf("%d", &tuoi);
    }while(tuoi<=0);
    x->Data.age = tuoi;
    fflush(stdin);
    do
    {
        printf("\tDiem: ");
        scanf("%f", &diem);
    }while(diem < 0 || diem > 10);
    x->Data.avg_mark = diem;
    fflush(stdin);
    x->Next = NULL;
}

//Nhap thong tin sinh vien khong can ten
void Nhap_khong_ten (NODE* x, char temp[])
{
    int tuoi;
    float diem;
    fflush(stdin);
    strcpy(x->Data.name,temp);
    fflush(stdin);
    do
    {
        printf("\tTuoi: ");
        scanf("%d", &tuoi);
    }while(tuoi<=0);
    x->Data.age = tuoi;
    fflush(stdin);
    do
    {
        printf("\tDiem: ");
        scanf("%f", &diem);
    }while(diem < 0 || diem > 10);
    x->Data.avg_mark = diem;
    fflush(stdin);
    x->Next = NULL;
}

//In 1 sinh vien
void InSV(NODE* p, int dem)
{
    printf("\t|%4d|%-25s|%5d|%7.1f|\n",dem,p->Data.name,p->Data.age,p->Data.avg_mark);
}

//In DANH SACH SINH VIEN
void InDanhSach(TList x)
{
    printf("\n\t\t DANH SACH SINH VIEN\n");
    printf("\t %4s_%-25s_%5s_%7s\n","____","_________________________","_____","_______");
    printf("\t|%4s|%-25s|%5s|%7s|\n","STT","Ho va ten","Tuoi","Diem TB");
    printf("\t|%4s+%-25s+%5s+%7s|\n","----","-------------------------","-----","-------");
    NODE *p;
3    int dem = 1;
    p = x.first;
    while(p != NULL)
    {
        InSV(p,dem);
        p = p->Next;
        dem++;
    }
    printf("\t|%4s|%-25s|%5s|%7s|\n","____","_________________________","_____","_______");
    printf("\n");
}

//Them mot NODE vao Cuoi danh sach
void ThemCuoi(TList* x, NODE* t)
{
    if(x->first == NULL)
        x->first = t;
    else
        x->last->Next = t;
    x->last = t;
}

// Them mot sinh vien vao cuoi danh sach
int NhapSV(TList* x)
{
    NODE* a = KhoitaoNode();
    Nhap(a);
    ThemCuoi(x,a);
    return 0;
}

//Giai phong bo nho
void giaiphong(TList *x)
{
    NODE *p = x->first;
    NODE *a;
   while( p->Next != NULL)
    {
        a = p;
        p = p->Next;
        free(a);
    }
}

//Ktra xem ten sinh vien da co trong danh sach hay chua
int ktra (char tempC[], TList* list)
{
    NODE* temp1;
    temp1 = list->first;
    while (temp1 != NULL)
    {
        if (strcmp(temp1->Data.name,tempC)==0)
            return 1;
        temp1 = temp1->Next;
    }
    return 0;
}

//Them 1 SV vao danh sach
void Nhap_mot_SV (char tempC[], TList* list)
{
    NODE* a = KhoitaoNode();
    Nhap_khong_ten(a,tempC);
    ThemCuoi(list,a);
}

//Xoa phan tu dau tien
void Xoa_so_1 (TList* list)
{
    NODE* tmp = list->first;
    list->first = tmp->Next;
    free(tmp);
}

void Xoa_theo_ten (char tempC[], TList* list)
{
    NODE* tmp;
    tmp = list->first;
    if (strcmp(tmp->Data.name,tempC)!=0)
        {
            while (1)
            {
                if (strcmp(tmp->Next->Data.name,tempC)==0)
                    break;
                tmp = tmp->Next;
            }
            NODE* del_tmp = tmp->Next;
            if (list->last==tmp->Next)
            {
                list->last=tmp;
                tmp->Next = NULL;
            }
            else
            {
                tmp->Next = tmp->Next->Next;
            }
            free(del_tmp);
        }
    else
    {
        Xoa_so_1(list);
    }

}

//Ham Tao Danh Sach Tuy chon
int Menu()
{
    char tempC[25];
    int a, i;
    TList x;
    KhoitaoList(&x);
    do
    {
        printf("\t ______________________________________ \n");
        printf("\t|                MENU                  |\n");
        printf("\t|--------------------------------------|\n");
        printf("\t| 1 - Nhap danh sach Sinh Vien         |\n");
        printf("\t| 2 - Liet ke danh sach Sinh Vien      |\n");
        printf("\t| 3 - Chen them 1 sinh vien            |\n");
        printf("\t| 4 - Xoa mot sinh vien                |\n");
        printf("\t| 5 - Sua mot sinh vien                |\n");
        printf("\t| 0 - Thoat                            |\n");
        printf("\t|______________________________________|\n");
        printf("\tVui long chon: ");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                {
                    int n;
                    printf("\n\t\tNhap so luong Sinh vien: ");
                    scanf("%d",&n);
                    for(i=1; i<=n ;i++)
                    {
                        printf("\tSinh vien thu %d\n",i);
                        NhapSV(&x);
                        printf("\n");
                    }
                    break;
                }
            case 2:
                {
                    InDanhSach(x);
                    break;
                }
            case 3:
                {
                    printf("\tNhap ten sinh vien: ");
                    fflush(stdin);
                    gets(tempC);
                    if (ktra(tempC,&x))
                        printf("\tSinh vien da co trong danh sach\n");
                    else
                        {
                            Nhap_mot_SV(tempC,&x);
                        }
                    break;
                }
            case 4:
                {
                    printf("\tNhap ten sinh vien muon xoa: ");
                    fflush(stdin);
                    gets(tempC);
                    if (ktra(tempC,&x))
                    {
                        Xoa_theo_ten(tempC,&x);
                    }
                    else
                    {
                        printf("\tSinh vien nay khong co trong danh sach\n");
                    }
                    break;
                }
            case 5:
                {
                    printf("\tNhap ten sinh vien muon sua: ");
                    fflush(stdin);
                    gets(tempC);
                    if (ktra(tempC,&x))
                    {
                        Xoa_theo_ten(tempC,&x);
                        NODE* tmp = KhoitaoNode();
                        Nhap(tmp);
                        ThemCuoi(&x,tmp);
                    }
                    else
                    {
                        printf("\tSinh vien nay khong co trong danh sach\n");
                    }
                    break;
                }
            case 0:
                {
                    exit(0);
                }
            default:
                printf("\t\aBan chon sai vui long chon lai!\n");
        }
    }
    while(a!=0);
    giaiphong(&x);
    return 1;
}
int main()
{
    system("cls");
    Menu();
    system("cls");
    return 0;
}
