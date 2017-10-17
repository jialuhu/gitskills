/*************************************************************************
	> File Name: stacknode.c
	> Author: 
	> Mail: 
	> Created Time: 六 10/14 11:24:13 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char OPerateor[8]={'+','-','*','/','(',')','^','#'};
typedef struct stacknumber  //数字栈
{
    int a;
    struct stacknumber *next;
}node;

typedef struct stackchar  //运算符栈
{
    char ch;
    struct stackchar *next;
}operator;

/*数字入栈操作*/
node *number_push(node *top, int b)
{
    node *p;
    if((p = (node *)malloc(sizeof(node)))==NULL)
    {
        return NULL;
    }
    p->a = b;
    p->next = top->next;
    top->next = p;
    return top;
}

/*数字出栈操作*/
int number_pop(node *top)
{
node *p;
int b;
if(top->next ==NULL)
{
    return 0;
}
p = top->next;
top->next = p->next;
b = p->a;
free(p);
return b;
}
/*取出数字栈顶元素*/
int pop_top(node *top)
{
node *p = top->next;
int b=0;
if(top->next ==NULL)
{
    return 0;
}
b = p->a;
return b;
}
/*运算符入栈操作*/
operator *char_push(operator *top, char c)
{
operator *p;
p = (operator *)malloc(sizeof(operator));
p->ch = c;
p->next = top -> next;
top->next = p;
return top;
}

/*运算符出栈操作*/
char char_pop(operator *top)
{
char ch;
operator *p;
if(top->next == NULL)
{
    return 0;
}
p = top->next;
top->next = p->next;
ch = p->ch;
free(p);
return ch;
}
/*取出操作符栈顶元素*/
char char_poptop(operator *ope)
{
operator *p = ope->next;
char ch;
if(ope->next == NULL)
{
    return 0;
}
ch = p->ch;
return ch;
}
int juge(char ch)//判断时是否是操作符号
{
for(int i=0; i<8; i++)
{
    if(ch==OPerateor[i])
    {
        return 1;
    }
}
return 0;
}
int sum(char ch,int a,int b)
{
//printf("a=%d\tb=%d\n",a,b);
int s=0;
switch(ch)
{
    case '+': return(a+b);
    case '-': return(a-b);
    case '/': return(a/b);
    case '*': return(a*b);
    default: printf("运算符格式错误\n"); return 0;
}
}
int compare(char ch,operator *ope,node *number)
{
int s=0;
char a = ch;//当前元素
//printf("传入的为:%c\n",a);
if(a=='+'||a=='-')
{
    char c=char_poptop(ope);//取出栈顶元素比较
    if(c=='('||c=='#')//入运算符栈
    {
        return 1;
        //char_push(ope,a);
    }
    else{
            return -1;
        }
}
if(a=='*'||a=='/')
{
    char c=char_poptop(ope);
    //printf("得到的栈顶元素:%c\n",c);
    if(c=='*'||c=='/'||c==')')
    {
        return -1;
    }
    else{
        return 1;
    }        
}
if(a=='(') return 1; //char_push(ope,a);
if(a==')') 
{
    char c=char_poptop(ope);
    if(c!='(')
    {
        return -1;
    }
    else{
            return 0;
       }
}
if(a=='#')
{
    char c=char_poptop(ope);
 //   printf("此处栈顶元素:%c\n",c);
    if(c!='#'){
        return -1;
    }
    char b=char_poptop(ope);
    if(b=='#'){
        return 0;
    }      
}
    return -2;
}
void menu()
{
system("clear -l");
printf("--------------------------------------------\n");
printf("---------------算术表达式求值---------------\n");
printf("----------请按照提示输入要求值的式子--------\n");
printf("--------------------------------------------\n");
}
int main()
{
int tags = 0; //控制循环
node *number;
int len = 0;  //控制string格式输出
operator *ope=NULL;  //操作符的头指针
number=(node *)malloc(sizeof(node));
number->next = NULL; //初始化，指向一个明确的地址
ope = (operator *)malloc(sizeof(operator));
ope->next = NULL;
char st[128]={0};//string
char ch='#';
char cp[2]={'#','\0'};
do{
    menu();
    setbuf(stdin,NULL);//清空键盘缓存区
    printf("请输入要计算的式子:\n");
    scanf("%[^\n]",st);//scanf扫描集
    strcat(st,cp);//把#连接到string后面
    len = strlen(st);
    st[len+1]='\0';//加入结束符
    //len = strlen(st);

    /*让#压入运算符栈顶*/
    ope = char_push(ope,ch);
    int a = 0;
    char sr[12];
    char c='0';
    c = char_poptop(ope);
    char *p = st;
    char st1[128]={0};
    int S=0;
    while(p[0]!='#'||char_poptop(ope)!='#')
    {
    //  printf("p[0]=%c\tchar_poptop:%c\n",p[0],char_poptop(ope));
        memset(st1,0,128);
        if(!juge(p[0])) //该操作符不是运算符
        {
            int i=0;
            do{
                st1[i] = *p;
                p++;
                i++;
            }while(juge(p[0])==0&&p[0]!='#');
            st1[i+1] = '\0';
            a = atoi(st1);//将数字字符转化成整型数字
            number_push(number,a);//压入数字栈中·
     /*   printf("a=%d\n",a);
        printf("p=%s\n",p);*/
        }
        else
        {
            char b=0;
            b = p[0];
        //printf("b=%c\n",b);
            S = compare(b,ope,number);
            switch(S)
            {
                case 1://高于压栈
                {
                    char_push(ope,b);
                    p++;
                    break;
                }
                case 0://等于弹出栈顶元素
                {
                    char_pop(ope);
                    p++;
                    break;
                }
                case -1://小于拿出两个数字，一个运算符
                {
                    int a1,b1,s;
                    char b=char_pop(ope);
                    b1 = number_pop(number);
                    a1 = number_pop(number);
                    s = sum(b,a1,b1);
                    number_push(number,s);
                    break;
                }
            }
        }
}
    st[len-1] = '\0';
    S = pop_top(number);
    printf("%s=%d\n",st,S);
    printf("是否继续进行求值,继续请输入1，退出输入0:\n");
    scanf("%d",&tags);
    }while(tags);
}

