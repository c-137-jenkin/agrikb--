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
                d.name[strcspn(d.name, "\n\r")] = '\0';

                printf("症状:");
                fgets(d.symptom, MAX_STR, stdin);
                d.symptom[strcspn(d.symptom, "\n\r")] = '\0';

                printf("描述:");
                fgets(d.describe, MAX_STR, stdin);
                d.describe[strcspn(d.describe, "\n\r")] = '\0';

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
                printf("%-4s %-10s %-16s %-10s %-40s\n", "ID", "作物", "病害名", "症状", "描述");

                for(int i = 0 ; i <= count; i++)//count从1开始，所以循环条件是i<=count
                {   if(c){
                        if(disease[i].deleted) continue;/*若id是流动的，则删除的部分的id会被其他部分填充。
                                                          若id是固定的，则删除部分id应当不显示，以达到更好的呈现效果*/
                         }
                         //"固定"id模式下,如果deleted为1，说明该条数据已被删除，跳过
                         printf(
                        
                        "%-4d %-10s %-16s %-10s %-40s\n",
                         disease[i].id,
                         disease[i].crop, 
                         disease[i].name, 
                         disease[i].symptom,
                         disease[i].describe

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

                if(disease[id_].deleted) printf("已删除\n") ;
                else
                {
                    for(int i=0 ; i <= count ; i++ )
                    {
                        if(disease[i].id == id_)
                        {
                            disease[i].deleted = 1 ;
    
                            memset(&disease[i].crop , 0 , sizeof(disease[i].crop )) ;
                            memset(&disease[i].name , 0 , sizeof(disease[i].name )) ;
                            memset(&disease[i].symptom , 0 , sizeof(disease[i].symptom )) ;
                            memset(&disease[i].describe , 0 , sizeof(disease[i].describe )) ;
                
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
                                    strcpy(disease[id_].crop , disease[id2].crop);
                                    strcpy(disease[id_].name , disease[id2].name);
                                    strcpy(disease[id_].symptom , disease[id2].symptom);
                                    strcpy(disease[id_].describe , disease[id2].describe);

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