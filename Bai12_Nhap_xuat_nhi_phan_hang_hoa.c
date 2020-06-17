#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    char ten_hang[25];
    int don_gia;
    int so_luong;
    int thanh_tien;
}HangHoa;

FILE* f;
char* filepath = "SO_LIEU.C";

void tao_hang_hoa_len_file()
{
    HangHoa tmp;
    char chon_tiep;
    f = fopen(filepath,"wb");

    while (1)
    {
        //them du lieu
        printf("\t\tTen hang: ");
        fflush(stdin);
        gets(tmp.ten_hang);
        printf("\t\tSo luong: ");
        scanf("%d",&tmp.so_luong);
        printf("\t\tDon gia: ");
        scanf("%d",&tmp.don_gia);
        tmp.thanh_tien = tmp.don_gia * tmp.so_luong;

        printf("\tNhap tiep? y/n ");
        fflush(stdin);
        chon_tiep = getchar();
        //In len file
        fwrite(&tmp,1,sizeof(HangHoa),f);

        if (chon_tiep == 'n'||chon_tiep == 'N')
            break;
    }
    fclose(f);

}

void bo_sung_hang_hoa_len_file()
{
    HangHoa tmp;

    //them du lieu
    printf("\t\tTen hang: ");
    fflush(stdin);
    gets(tmp.ten_hang);
    printf("\t\tSo luong: ");
    scanf("%d",&tmp.so_luong);
    printf("\t\tDon gia: ");
    scanf("%d",&tmp.don_gia);
    tmp.thanh_tien = tmp.don_gia * tmp.so_luong;

    //In len file
    f = fopen(filepath,"ab");
    fwrite(&tmp,1,sizeof(HangHoa),f);
    fclose(f);
}

void hien_thi_noi_dung_tep()
{
    HangHoa tmp;


    int i = 1;
    printf("\t\tDANH SACH HANG HOA\n");
    printf("\t|%3s|%25s|%8s|%12s|%14s|\n","STT", "Ten hang", "So luong", "Don gia", "Thanh tien");
    printf("\t|---|-------------------------|--------|------------|--------------|\n");

        //Mo file
    f = fopen(filepath,"rb");
    while(!feof(f))
    {
        fread(&tmp, 1,sizeof(HangHoa),f);
        printf("\t|%3d|%25s|%8d|%12d|%14d|\n",i++,tmp.ten_hang,tmp.so_luong,tmp.don_gia,tmp.thanh_tien);
    }
    fclose(f);
}

void menu()
{
    printf("\t _________________________________________________________\n");
    printf("\t|                           MENU                          |\n");
    printf("\t|---------------------------------------------------------|\n");
    printf("\t| 1. Nhap so lieu ban hang len tep                        |\n");
    printf("\t| 2. Ghi bo sung so lieu ban hang vao cuoi tep SO_LIEU.C  |\n");
    printf("\t| 3. Hien thi noi dung tep SO_LIEU.C                      |\n");
    printf("\t| 4. Ket thuc                                             |\n");
    printf("\t|_________________________________________________________|\n");
    printf("\t\tVui long chon: ");
}

int main()
{
    int chon;
    char chon_tiep;
    while (1)
    {
        menu();
        scanf("%d",&chon);
        switch(chon)
        {
            case 1:
                printf("\tBan da chon nhap so lieu ban hang len tep\n");
                tao_hang_hoa_len_file();
                break;
            case 2:
                printf("\tBan da chon bo sung so lieu ban hang len tep\n");
                while(1)
                {
                    bo_sung_hang_hoa_len_file();
                    printf("\tNhap tiep? y/n ");
                    fflush(stdin);
                    chon_tiep = getchar();
                    if (chon_tiep == 'n'||chon_tiep == 'N')
                        break;
                }
                break;
            case 3:
                printf("\tBan da chon hien thi noi dung tep\n");
                hien_thi_noi_dung_tep();
                break;
            case 4:
                exit(0);
        }
        getch();
        system("cls");
    }
    return 0;
}
