#include "School.h"
static student school[MAX_STUDENTS];
student std;
int main()
{
    int option, exitFlag = 0, index, i = 0, menuKey = 0 , size;
    char in;
    size = sizeof(school) / sizeof(school[0]);
    in = 1;
    welcomeMessage();
    while (1)
    {
        if (in == 2)
        {
            printf(ANSI_COLOR_MAGENTA "==> Press 1 Back to main Menu: ");

            scanf("%d", &menuKey);
            printf("===============================\n" ANSI_COLOR_RESET);
        }
        if (menuKey == 1 || in == 1)
        {
            options();
            printf(ANSI_COLOR_MAGENTA "-----\n==> Choice No. ");
            scanf("%d", &option);
            printf("-----\n" ANSI_COLOR_RESET);
        }
        editingOptions(school, option, size, &exitFlag);
        in = 2;
        if (exitFlag == 1)
            break;
    }
    // printf("Number of student = %d\n" , printAll(school , size));
    byeMessage();

    return 0;
}