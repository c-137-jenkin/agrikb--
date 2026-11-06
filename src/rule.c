#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LIMIT 3
#define MAX_CHAR1 120
#define MAX_CHAR2 200



int main (void)
{
struct Rule 
{
    int id ;
    char condition[MAX_CHAR2] ;//什么情况下这条规则会激活
    char action[MAX_CHAR2] ;//一旦触发了条件，应该采取什么级别措施
    char text[MAX_CHAR1] ;//输出给用户的警告
    char priority[20] ;//优先级
    int deleted ;//软删除
};

int count=0 ;

struct Rule rule[100] ;

char line[64] ;
char*judge = NULL ;


    printf("********************\n------规则管理------\n********************\n\n");
    printf("1.添加 2.列表/通过优先级整理 3.删除 0.返回(输入回车直接返回)\n ");
int choice1 ;
do
{

choice1 = 0 ;
char extra ;
judge = fgets(line , 64 , stdin );
line[strcspn(line , "\n\r")] = '\0';
int t = sscanf(line , "%d%s" , &choice1,&extra) ;
if(t!=1)
{
    printf("输入错误，请误输入字母或不输入\n") ;
    choice1 = 1 ;
    continue;
}

if(choice1>3 || choice1<0) 
{
  printf("无效输入，请输入0~3之间的数字\n");
  continue ;
  choice1 = 1 ;
}

if(!judge) 
{
  printf("已强制结束程序\n") ;
  break ; 
}

struct Rule d ;
{
    /* data */
};

switch (choice1)
{
    case 1:{int p ; char extra ; int ret ;
            count++ ;
            d.id = count ;
        
            printf("请输入触发条件:\n") ;
            fgets(d.condition , MAX_CHAR2 , stdin ) ;
            d.condition[strcspn(d.condition,"\n\r")] = '\0' ;

            printf("请输入应当采取的措施:\n") ;
            fgets(d.action , MAX_CHAR2 , stdin ) ;
            d.action[strcspn(d.action,"\n\r")] = '\0' ;
    
            printf("请输入应当输出给用户的警告:\n") ;
            fgets(d.text , MAX_CHAR2 , stdin ) ;
            d.text[strcspn(d.text,"\n\r")] = '\0' ;

            do{
            printf("请输入优先级 1 或 2 或 3 : \n 注意!1优先于2优先于3\n");
            fgets(d.priority,20,stdin) ;
            d.priority[strcspn(d.priority,"\n\r")] = '\0';//去回车
            ret =  sscanf(d.priority,"%d%c",&p,&extra);
              }while(p<1 || p>3 || ret!=1);//将输入的值控制在·整数类型1~3之间
            
            d.deleted = 1 ;
            printf("保存成功！id为%d\n\n",d.id);

            rule[count] = d ;//结构体数组从1下标开始
           }break ;

    case 2:{int i = 0 ; int n = 1;
        for( ; n<count ; n++){
            for(i=1 ; i<count ; i++){

                if(atoi(rule[i].priority)>=atoi(rule[i+1].priority ))/*rule[i]是结构体，而rule[i].priority是char类型数组
                                                                       表达式中数组名自动退化，变成指向第一个字符的指针，所以要用atoi翻译成整数*/
                {   struct Rule temp ;
                    temp = rule[i] ;
                    rule[i] = rule[i+1];
                    rule[i+1] = temp ;
                }

                                  }
                              }//双循环实现气泡排序

        i = 1 ;
        printf("%-4s %-20s %-20s %-40s %-2s\n","ID","激活条件","采取措施","警告","优先级");
        
        
            for(; i<=count ; i++)
                {   
                    if(rule[i].deleted==1){ 
                        printf( "%-4d %-20s %-20s %-40s %-2s\n",
                            rule[i].id,
                            rule[i].condition, 
                            rule[i].action, 
                            rule[i].text,
                            rule[i].priority );
                                            }

                }
                             
    
    
           } break ;

    case 3:printf("test3\n") ; 
    {int d ; int i = 1 ;
        printf("请输入您要删除的id:\n"); scanf("%d", &d );
        getchar();
        for(;i<=count;i++)
        {
            if(rule[i].id == d ){rule[i].deleted=0;}
        }
        printf("删除成功！");
    }break ;



}


}while(choice1!=0) ;
   

return 0 ;

}