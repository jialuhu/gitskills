//
//  main.c
//  DFS
//
//  Created by Jialu  Hu on 2017/8/1.
//  Copyright © 2017年 Jialu  Hu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int visit[21]={0};
int prime[38]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};
int ring[21]={0};
void DFS(int k, int n)
{
    // printf("k=%d\n",k);
     int i=0;
     if((k-1==n)&&prime[ring[n]+1])
     {
          printf("1\t");
          int i=0;
          for(i=2;i<=n;i++)
          {
               printf("%d\t",ring[i]);
          }
          exit(0);
     }
     else
     {
            //printf("jingru\n");
          for(i=2;i<=n;i++)
          {
               //printf("jingru3\n");
               if((!visit[i])&&(prime[ring[k-1]+i]))
               {
                    //printf("hello\n");
                    visit[i]=1;
                    ring[k]=i;
                    printf("ring=%d",ring[k]);
                    DFS(k+1,n);
                    visit[i]=0;
               }
          }
     }
}

int main()
{
    int n;
    //int ring[21]={0};
    printf("please input the n:\n");
    scanf("%d",&n);
    if(n==1)
    {
        printf("1\n");
    }
    else
    {
        visit[1]=1;
        ring[1]=1;
        DFS(2,n);
    }
    
    
}
