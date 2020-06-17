#include <stdio.h>

void Output_result (float ori_GDP, float deve_speed)
{
    float temp = ori_GDP;
    int year = 2014;
    printf("\t ___________\n");
    printf("\t|%-5s|%5s|\n","Nam", "GDP");
    printf("\t|%5s|%5s|\n","-----","-----");
    while (1)
    {
        if (temp>=2*ori_GDP)
            break;
        printf("\t|%-5d|%5.1f|\n",year++,temp);
        temp *= 1+deve_speed;
    }
    printf("\t|%-5s|%5s|\n","_____", "_____");
}

int main()
{
    float ori_GDP;
    int nam = 2014;
    float deve_speed;
    printf("\tNhap vao tong GDP nam 2014: ");
    scanf("%f",&ori_GDP);
    printf("\tNhap toc do tang truong tung nam (theo %%): ");
    scanf("%f",&deve_speed);
    deve_speed /= 100;
    Output_result (ori_GDP,deve_speed);
    return 0;

}
