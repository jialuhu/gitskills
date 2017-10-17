/*************************************************************************
	> File Name: maze.c
	> Author:jialuhu 
	> Mail: 
	> Created Time: 一 10/16 22:57:13 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define N 20
#define M 20

int n,m;
int map[N][M] = {0};
int visit[N][M] = {0};
int trend[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};//四个方向
int flag;

void dfs(int x,int y)
{
    int k=0;
    visit[x][y] = 1;
    if(map[x][y]==2)
    {
        flag = 1;
        return;
    }
    for(int i=0; i<4; i++)
    {
        int tx;
        int ty;
        tx = trend[i][0]+x;
        ty = trend[i][1]+y;
        if(tx>=0 && ty>=0 && tx<n && ty<m && visit[tx][ty]==0 && map[tx][ty]!=0)
        {
            dfs(tx,ty);
        }
        else{
                k++;
        }
    }
    if(k==4){
        visit[x][y] = 0;
    }
}
int prin()
{
    int choice = 0;
    system("clear -l");
    printf("---------欢迎来到迷宫--------\n");
    printf("-------1、迷宫路径求解-------\n");
    printf("-------2、退出该程序---------\n");
    printf("please input the choice:\n");
    scanf("%d",&choice);
    return choice;
}

int menu()
{
    int tag=1;
    //while(tag)
    //{
        memset(map,0,400);
        int choice= 0;
        choice = prin();
        switch(choice)
        {
            case 1:
            {
                flag = 0;
                system("clear -l");
                /*自定义迷宫地图*/
                printf("请输入几行几列矩阵迷宫:\n");
                scanf("%d%d",&n,&m);
                printf("请手动输入迷宫具体内容，1代表通过，0代表障碍,2代表终点(默认起点为1,在(0,0)位置):\n");
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        scanf("%d",&map[i][j]);
                        if(map[i][j]!=0&&map[i][j]!=1&&map[i][j]!=2)//非法操作处理
                        {
                            printf("输入格式错误，您将退回上层页面\n");
                            sleep(2);
                            return menu();
                        }
                    }
                }
                /*打印迷宫*/
                printf("打印地图:\n");
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        printf("%d\t",map[i][j]);
                    }
                    printf("\n");
                }
                visit[0][0] = 1;//标记第一个位置　
                dfs(0,0);
                if(flag == 1){
                    printf("打印路径：\n");
                    for(int i=0; i<n; i++)
                    {
                        for(int j=0; j<m; j++)
                        {
                            if(visit[i][j]==1)
                            {
                                printf("(%d,%d)\t",i,j);
                            }
                        }
                    }
                }
                else{
                    printf("该迷宫没有出路\n");
                }
                printf("\n");
                /*printf("是否继续，继续请输入1，不继续请输入0:\n");
                scanf("%d\n",&tag);
                if(tag==1)
                {
                    return menu();
                }*/
                break;
            }
            case 2:// 退出程序
            {
                return 0;
            }
            default:
            {
                printf("输入格式错误.3秒后将重新回到主菜单\n");
                sleep(3);
                return menu();
            }
        }

   // }
    return 0;
}
int main()
{
    int tag = 1;
    do{
        memset(map,0,400);
        memset(visit,0,400);
       // memset(,0,400);
        //memset(map,0,400);
        flag = 0;
        menu();
        printf("是否继续，继续请输入1，结束请输入0:\n");
        scanf("%d",&tag);
    }while(tag);
    return 0;
}

