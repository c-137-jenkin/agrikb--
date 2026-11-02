#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PESTICIDE 100
#define MAX_STR 128
struct Pesticide
{
    int id;
    char reg_no[MAX_STR];//登记证号
    char crop[MAX_STR];//适用作物
    char name[MAX_STR];//药剂名
    char target[MAX_STR];//防治对象
    char dosage[MAX_STR];//用量
    char interval[MAX_STR];//安全间隔
    int deleted; /* data */
};

struct Pesticide pesticide[MAX_PESTICIDE];
int count = 0;
int main(void)
{

    printf("********************\n------药剂管理------\n********************\n\n");
    printf("1.添加 2.列表 3.删除 0.返回\n ");

    char line[64];

    do
    {

        printf("请选择: \n");

        fgets(line, 64, stdin);
        int choice = 0;
        char extra = 0;

        line[strcspn(line, "\n\r")] = '\0';

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
            printf("see you ！ \n ");
            line[0] = 0;
            break;
            //“添加”功能的实现
        case 1:
            printf("***添加***\n");
            {
                if (count >= MAX_PESTICIDE)

                {
                    printf("容量已满\n");
                    continue;
                }
                struct Pesticide d;
                memset(&d, 0, sizeof(d));//将栈内存的无效数据格式化
                d.id = ++count;//id从1开始

                printf("登记证号:");
                fgets(d.reg_no, MAX_STR, stdin);
                d.reg_no[strcspn(d.reg_no, "\n\r")] = '\0';

                printf("作物:");
                fgets(d.crop, MAX_STR, stdin);
                d.crop[strcspn(d.crop, "\n\r")] = '\0';//去掉输入时残留的回车与换行，下同

                printf("药剂名:");
                fgets(d.name, MAX_STR, stdin);
                d.name[strcspn(d.name, "\n\r")] = '\0';

                printf("防止对象:");
                fgets(d.target, MAX_STR, stdin);
                d.target[strcspn(d.target, "\n\r")] = '\0';

                printf("用量:");
                fgets(d.dosage, MAX_STR, stdin);
                d.dosage[strcspn(d.dosage, "\n\r")] = '\0';

                printf("安全间隔:");
                fgets(d.interval, MAX_STR, stdin);
                d.interval[strcspn(d.interval, "\n\r")] = '\0';

                if (d.name[0] == '\0')
                {
                    printf("药剂名不能为空，添加失败\n");
                    continue;
                }

                pesticide[count] = d;
                printf("添加成功,id = %d \n", d.id);
            }
            break;
        case 2:
            printf("\"列表\"功能\n");
            printf("请选择展示模式：若固定id则输入1，若流动id则输入0\n默认值为\"流动\"模式\n");
            {   int c = 0 ;
                scanf("%d",&c) ;
                getchar() ;
                if (count == 0)//只要进入一次case1count就会自增，所以count=0说明没有数据
                {
                    printf("没有数据,请选择'1'进行添加\n");
                    continue;
                }
                    //'-'表示左对齐，数字表示占位宽度，'-'与'数字'写在'%'与'd/s/f...'之间
                printf("%-4s %-10s %-10s %-16s %-20s %-10s %-10s\n", "ID", "登记证号", "作物名", "药剂名", "作用目标(害虫)" , "用量" , "安全间隔" );

                for(int i = 0 ; i <= count; i++)//count从1开始，所以循环条件是i<=count
                {   if(c){
                        if(pesticide[i].deleted) continue;/*若id是流动的，则删除的部分的id会被其他部分填充。
                                                          若id是固定的，则删除部分id应当不显示，以达到更好的呈现效果*/
                         }
                         //"固定"id模式下,如果deleted为1，说明该条数据已被删除，跳过
                         printf(
                        
                        "%-4d %-10s %-10s %-16s %-20s %-10s %-10s\n",
                         pesticide[i].id,
                         pesticide[i].reg_no,
                         pesticide[i].crop, 
                         pesticide[i].name, 
                         pesticide[i].target,
                         pesticide[i].dosage,
                         pesticide[i].interval

                          );
                }
            }
            break;
        case 3:
            printf("\"删除\"功能\n");
            {   int id_ ;
                printf("要删除的id: ");
                fgets(line , sizeof(line) , stdin ) ;
                line[strcspn(line , "\n\r")] = '\0' ;
                sscanf(line , "%d" , &id_) ;

                if(pesticide[id_].deleted) printf("已删除\n") ;
                else
                {
                    for(int i=0 ; i <= count ; i++ )
                    {
                        if(pesticide[i].id == id_)
                        {
                            pesticide[i].deleted = 1 ;
    
                            memset(&pesticide[i].reg_no , 0 , sizeof(pesticide[i].reg_no )) ;
                            memset(&pesticide[i].crop , 0 , sizeof(pesticide[i].crop )) ;
                            memset(&pesticide[i].name , 0 , sizeof(pesticide[i].name )) ;
                            memset(&pesticide[i].target , 0 , sizeof(pesticide[i].target )) ;
                            memset(&pesticide[i].dosage , 0 , sizeof(pesticide[i].dosage )) ;
                
                            printf("已删除\n") ;

                            printf("是否保留删除数据的id ？\n若不选择则回车，若选择删除则输入任意大于零数字：\n") ; 
                            char choice1[60] ; 
                            fgets(choice1 , 64 , stdin ) ; 
                            choice1[strcspn(choice1 , "\n\r")] = '\0' ;

                            if(choice1[0])
                            {   
                                for(;id_<count;id_++)//用于将空id填充，避免出现列表id不连续。若选择此条建议使用流动id列表
                                {   int id2 = ++id_ ;
                                    id_-- ;
                                    strcpy(pesticide[id_].reg_no , pesticide[id2].reg_no);
                                    strcpy(pesticide[id_].crop , pesticide[id2].crop);
                                    strcpy(pesticide[id_].name , pesticide[id2].name);
                                    strcpy(pesticide[id_].target , pesticide[id2].target);
                                    strcpy(pesticide[id_].dosage , pesticide[id2].dosage);

                                }
                                printf("删除成功！");
                                count-- ;



                            }
                            else {printf("保存成功!");}//不执行填充，若选择此条，建议选择固定id列表
                            break ; 
                        }



                    }


                }
            }
            break;
        }

    } while (line[0] != 0);

    return 0;
}
