#include <stdio.h>

//Kiem tra nam nhuan
int Leap_Check (int y)
{
    if (y%400==0)
        return 1;
    if (y%100==0)
        return 0;
    if (y%4==0)
        return 1;
    return 0;
}

//Tim ngay dua tren thang, nam
int Find_Day (int m, int y)
{
    switch(m)
    {
        case 2:
            {
                if (Leap_Check(y))
                    return 29;
                else
                    return 28;
            }
        case 4: case 6: case 9: case 11:
            {
                return 30;
            }
        default:
            return 31;
    }

}
int main()
{
    int thang, nam;
    printf("\tNhap thang, nam: ");
    scanf("%d%d",&thang,&nam);
    printf("\tThang %d nam %d co %d ngay",thang,nam,Find_Day(thang,nam));
    return 0;
}
