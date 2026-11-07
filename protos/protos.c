//关于状态机的实现demo

#include<stdio.h>
#include<string.h>

#define MAX_STR 128 //每个篮子的最大容量
#define MAX_FIELDS 10 //最多允许切几个篮子

int main(void){
//虚拟数据（假设从文件中读出的五行）
const char *cases[] = {
    "PD001,敌敌畏，白菜，高毒",     //普通情况
    "PD002,\"有,逗号\",\"描述\"",   //引号内带逗号
    "PD003,,\"\"",  //空字段
    "PD004,农药A",  //字段少
    "PD005,a,b,c,d,e,f,g,h,i,j,k",//结束标志
    NULL
};

//循环处理每一行模拟数据
for(int k = 0 ; cases[k]!=NULL ; k++)
{
    printf("\n--- 正在处理第 %d 行 ---\n" , k+1) ;
    printf("原始数据: %s\n" , cases[k] ) ;

    //把模拟数据拷贝到可修改的数组
    char buf[512] ;
    strcpy(buf , cases[k]);

    //准备篮子"二维数组"和计数器
    char field[MAX_FIELDS][MAX_STR] ;
    int fi = 0 ;    //定位篮子
    int ci = 0 ;    //定位篮子内的字符
    int in_quote = 0 ;  //开关,通过判断逗号是否在双引号内,区分是否是用于分割的逗号
    char *p = buf ;     //用于扫描数组的指针(buf在等号右边，自动退化成&buf[0])

    //切词逻辑，从左到右扫描
    while(*p != '\0' && fi < MAX_FIELDS){

        //规则1:遇到双引号，拨动开关，并且跳过双引号本身
        if(*p == '"'){
            in_quote = !in_quote ;//拨动开关，0变1，1变0
            p++ ;
            continue ;
        }

        //规则2:遇到逗号，并且不在引号里面，说明篮子满了，要进入下一个篮子
        if(*p == ',' && in_quote == 0){
            field[fi][ci] = '\0' ; //给篮子封口(加字符串结束符)
            fi ++ ;     //换个新篮子
            ci = 0 ;    //新篮子的计数器清零
            p++ ;   //指针往后挪动一格
            continue ;
        }

        //规则3:遇到换行符(\r 或 \n),说明这行彻底看完了，直接退出切词
        if(*p == '\r' || *p == '\n')
        {
            break ;
        }

        field[fi][ci] = *p ;
        ci++ ;
        p++ ;

       

    }

       //封口最后一个篮子。最后一个字符串后面是没有逗号的，循环会直接结束，最后一个词还没有封口
        if(ci > 0 || fi > 0){
            field[fi][ci] = '\0' ;
            fi++ ;//篮子总数加一
        }

         //打印出测试结果
        printf("切出字段数:%d\n", fi);
        for(int i = 0 ; i < fi ; i++){
            printf("[%d] = \"%s\"\n" , i , field[i]);

        }


}


    return 0 ;
}