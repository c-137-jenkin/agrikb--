#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DISEASE 100
#define MAX_STR 128
struct Disease
{
    int id;
    char crop[MAX_STR];
    char name[MAX_STR];
    char symptom[MAX_STR];
    char describe[MAX_STR];
    int deleted; /* data */
};

struct Disease disease[MAX_DISEASE];
int count = 0;
int main(void)
{

    printf("********************\n------病害管理------\n********************\n\n");
    printf("1.添加 2.列表 3.删除 0.返回\n ");

    char line[64];

    do
    {

        printf("请选择: \n");

        fgets(line, 64, stdin);
        int choice = 0;
        char extra = 0;

        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '\0')
        {
            printf("输入内容不能为空，请重新输入:\n");
            line[0] = 1;
            continue;
        }

        if (sscanf(line, "%d"
                         "%s",
                   &choice, &extra) != 1)
        {
            printf("请输入数字而非字母:\n");
            continue;
        }

        if (choice < 0 || choice > 3)
        {
            printf("请输入0~3之间的数字\n");
            continue;
        }
        switch (choice)
        {
        case 0:
            printf("see you \n ");
            line[0] = 0;
            break;
            //“添加”功能的实现
        case 1:
            printf("***添加***\n");
            {
                if (count >= MAX_DISEASE)

                {
                    printf("容量已满\n");
                    continue;
                }
                struct Disease d;
                memset(&d, 0, sizeof(d));//将栈内存的无效数据格式化
                d.id = ++count;//id从1开始

                printf("作物:");
                fgets(d.crop, MAX_STR, stdin);
                d.crop[strcspn(d.crop, "\n\r")] = '\0';//去掉输入时残留的回车与换行，下同

                printf("病害名:");
                fgets(d.name, MAX_STR, stdin);
                d.crop[strcspn(d.name, "\n\r")] = '\0';

                printf("症状:");
                fgets(d.symptom, MAX_STR, stdin);
                d.crop[strcspn(d.symptom, "\n\r")] = '\0';

                printf("描述:");
                fgets(d.describe, MAX_STR, stdin);
                d.crop[strcspn(d.describe, "\n\r")] = '\0';

                if (d.name[0] == '\0')
                {
                    printf("病害名不能为空，添加失败\n");
                    continue;
                }

                disease[count] = d;
                printf("添加成功,id = %d \n", d.id);
            }
            break;
        case 2:
            printf("\"列表\"功能\n");
            break;
        case 3:
            printf("\"删除\"功能\n");
            break;
        }

    } while (line[0] != 0);

    return 0;
}