//
// Created by asus on 2026/10/25.
//
#include <stdio.h>
#include <string.h>
int main()
{
    char line[64];
    printf("======AgrikB 植保合规知识库=====\n1.病害管理\n2.药剂管理\n3.规则管理\n4.统计报表\n5.数据校验\n6.导入/导出 CSV\n7.查看日志\n0.退出\n");
    printf("================================\n\n");
    do
    {
        /*fgets 用于读取一整行输入，包括空格。读取成功时，返回的是传进去数组的首地址
         读到\n时停下，并且\n会被读取而不是留在缓冲区。*/
        fgets(line, 64, stdin);
        /*strcspn的返回值是第一个符合要求的数据的数组角标*/
        line[strcspn(line, "\n\r")] = '\0';
        if (line[0] == '\0')
        {
            printf("输入不能为空，请重新输入：\n\n");
            line[0] = 1 ;
            continue;
        }
        char extra;
        int choice;
        /*必须%d读取到数据，%c才会开始读取。而%d是从第一次数字开始读取，到第一个字符处停止。
          比如输入a7,则返回值为0。输入7a，返回值是2。输入a，返回值是0。输入7，返回值是1.*/
        if (sscanf(line, "%d"
                         "%c",
                   &choice, &extra) != 1)
        {
            printf("输入无效，请重新输入数字而非字符:\n\n");

            continue;
        };
        if (choice < 0 || choice > 7)
        {
            printf("无效选项，请重新输入 0 ~ 7 之间的数字\n\n");
            continue;
        }

        switch (choice)
        {
        case 0:
            printf("see you . \n\n");
            line[0] = 0;
        case 1:
            printf("[占位] 病害管理功能尚未实现\n\n");
            break;
        case 2:
            printf("[占位] 药剂管理功能尚未实现\n\n");
            break;
        case 3:
            printf("[占位] 规则管理功能尚未实现\n\n");
            break;
        case 4:
            printf("[占位] 数据校验功能尚未实现\n\n");
            break;
        case 5:
            printf("[占位] 统计报表功能尚未实现\n\n");
            break;
        case 6:
            printf("[占位] 导入/导出功能尚未实现\n\n");
            break;
        case 7:
            printf("[占位] 日志查看功能尚未实现\n\n");  
            break;
        }

    } while (line[0] != 0);

    return 0;
}