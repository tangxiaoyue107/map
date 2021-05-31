#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "structure.h"

#include "manage_train.h"
#include "manage_plane.h"

#include "manage.h"
#include "user.h"

/*------����Ա�˵�-------*/
void manage();//һ��ѡ��
void add_del_city();//���ɾ������
void show_filecity();//�������
void show_city();//��ʾcity.txt����
int del_city();//ɾ������
int add_city();//��ӳ���
void writeback_tofile();//д��city.txt
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


/*------�û��˵�-------*/
void user();
void trainorplane_train();
void trainorplane_plane();
void min_money(Graph G,int startindex,int endindex);//���ٻ���Ǯ
void printroute(Graph G,int start,int end);//��ӡ·��
EdgeNode *get_weight(Graph G,int start, int end);//��ȡȨֵ
int get_weight_money(Graph G, int start, int end);//��ȡǮ����Ȩֵ
void min_time(Graph G,int startindex,int endindex);//���ٻ���ʱ��
void min_shu(Graph G,int startindex,int endindex);//���ٻ��Ѵ���

//��ʼ��
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

    show_filecity();//�������
    readtrain_fromfile();//�����·��
    readplane_fromfile();//����ɻ�·��

    printf("-----ȫ����ͨ��ѯϵͳ���˵�-----\n");
    printf("0���û���ѯϵͳ\n");
    printf("1������ϵͳ\n");
    printf("2���˳�ϵͳ\n");
    printf("��ѡ��0/1/2����");
    scanf("%d",&choosexitong);
    while(1)
    {
        if(choosexitong==0)
        {
            user();//�û���ѯ
            printf("-----ȫ����ͨ��ѯϵͳ���˵�-----\n");
            printf("0���û���ѯϵͳ\n");
            printf("1������ϵͳ\n");
            printf("2���˳�ϵͳ\n");
            printf("��ѡ��0/1/2����");
            scanf("%d",&choosexitong);
        }
        else if(choosexitong==1)
        {
            manage();//����Ա����
            printf("-----ȫ����ͨ��ѯϵͳ���˵�-----\n");
            printf("0���û���ѯϵͳ\n");
            printf("1������ϵͳ\n");
            printf("2���˳�ϵͳ\n");
            printf("��ѡ��0/1/2����");
            scanf("%d",&choosexitong);
        }
        else if(choosexitong==2) break; //�˳�ϵͳ
        else//����������������
        {
            printf("\n������������������,��ѡ��0/1/2��:");
            scanf("%d",&choosexitong);
        }
    }
    printf("��ӭ���´�ʹ��");
    writeplane_tofile();
    writetrain_tofile();
    return 0;
}
