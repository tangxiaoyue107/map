#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "structure.h"

#include "manage_train.h"
#include "manage_plane.h"

#include "manage.h"
#include "user.h"

/*------管理员菜单-------*/
void manage();//一级选择
void add_del_city();//添加删除城市
void show_filecity();//读入城市
void show_city();//显示city.txt城市
int del_city();//删除城市
int add_city();//添加城市
void writeback_tofile();//写回city.txt
void show_city();
void delcity_deleroute(Graph *G,int cityindex);

void add_del_trainroute();
void writetrain_tofile();
void readtrain_fromfile();
void show_train_route();
void dfs(int i);
void del_train_route();
void add_train_route();

void add_del_planeroute();
void writeplane_tofile();
void readplane_fromfile();
void show_plane_route();
void printdfs(int i);
void del_plane_route();
void add_plane_route();


/*------用户菜单-------*/
void user();
void trainorplane_train();
void trainorplane_plane();
void min_money(Graph G,int startindex,int endindex);//最少花费钱
void printroute(Graph G,int start,int end);//打印路线
EdgeNode *get_weight(Graph G,int start, int end);//获取权值
int get_weight_money(Graph G, int start, int end);//获取钱数的权值
void min_time(Graph G,int startindex,int endindex);//最少花费时间
void min_shu(Graph G,int startindex,int endindex);//最少花费次数

//初始化
void initagain()
{
    writeback_tofile();
    writetrain_tofile();
    writeplane_tofile();
    show_filecity();
    readtrain_fromfile();
    readplane_fromfile();
}

int main()
{
    int choosexitong;

    show_filecity();//读入城市
    readtrain_fromfile();//读入火车路线
    readplane_fromfile();//读入飞机路线

    printf("-----全国交通咨询系统主菜单-----\n");
    printf("0：用户咨询系统\n");
    printf("1：管理系统\n");
    printf("2：退出系统\n");
    printf("请选择（0/1/2）：");
    scanf("%d",&choosexitong);
    while(1)
    {
        if(choosexitong==0)
        {
            user();//用户咨询
            printf("-----全国交通咨询系统主菜单-----\n");
            printf("0：用户咨询系统\n");
            printf("1：管理系统\n");
            printf("2：退出系统\n");
            printf("请选择（0/1/2）：");
            scanf("%d",&choosexitong);
        }
        else if(choosexitong==1)
        {
            manage();//管理员管理
            printf("-----全国交通咨询系统主菜单-----\n");
            printf("0：用户咨询系统\n");
            printf("1：管理系统\n");
            printf("2：退出系统\n");
            printf("请选择（0/1/2）：");
            scanf("%d",&choosexitong);
        }
        else if(choosexitong==2) break; //退出系统
        else//输入有误，重新输入
        {
            printf("\n输入有误请重新输入,请选择（0/1/2）:");
            scanf("%d",&choosexitong);
        }
    }
    printf("欢迎您下次使用");
    writeplane_tofile();
    writetrain_tofile();
    return 0;
}
