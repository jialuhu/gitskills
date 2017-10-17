/*************************************************************************
	> File Name: 气球.c
	> Author: 
	> Mail: 
	> Created Time: 一  8/ 7 15:36:59 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    //char *color[1000];
    char C[1000][15];
    int st[1000]={0};
    int n;
    while((scanf("%d",&n)!=EOF)&&n!=0)
    {
        int i;
        int sum=0;
        int max=1;
        int max_f=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",C[i]);
            C[i][strlen(C[i])]='\0';
           // color[i]=(char *)C[i];

        }
       // color[i]=NULL;
        for(i=0;i<n-1;i++)
        {
            sum = 0;
            for(int j=i+1;j<n;j++)
            {
               if(strcmp(C[i],C[j])==0)
                {
                    sum++;
                }
            }
            if(max<=sum)
            {
                max_f = i;
                max = sum;
            }
            else{
                continue;
            }
        }
        printf("%s\n",C[max_f]);
    }
}
