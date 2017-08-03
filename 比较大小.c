/*************************************************************************
	> File Name: 比较大小.c
	> Author: 
	> Mail: 
	> Created Time: 四  8/ 3 11:11:28 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char st1[1000002];
    char st2[1000002];
    while(scanf("%s%s",st1,st2) != EOF)
    {
        char *p=st1;
        int a;
        char *p2=st1,*q2=st2;
        int flag1=0;
        int flag2=0;
        char *p1=st1+strlen(st1)-1;
        char *q=st2;
        char *q1=st2+strlen(st2)-1;
        while(*p2!='\0')
        {
            p2++;
            if(*p2=='.')
            {
                flag1=1;
                break;
            }
        }
        while(*q2!='\0')
        {
            q2++;
            if(*q2=='.')
            {
                flag2=1;
                break;
            }
        }
        while(*p=='0')
        {
            p++;
        }
        while(*p1=='0'&&flag1==1)
        {
            p1[0]='\0';
            p1--;
        }
        if(*p1=='.')
        {
            p1[0]='\0';
        }
        while(*q=='0')
        {
            q++;
        }
        while(*q1=='0'&&flag2==1)
        {
            q1[0]='\0';
            q1--;
        }
        if(*q1=='.')
        {
            q1[0]='\0';
        }
        a = strcmp(p,q);
        if(a==0)
        {
            printf("YES\n");
        }
        if(a!=0){printf("NO\n");}
    }
}
