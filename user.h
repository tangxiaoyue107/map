/**** �˵� ****/
//�𳵳��в˵�
void trainorplane_train()
{
    int chooseway;
    int i;
    int startindex=-1;
    int endindex=-1;
    char startcity[MAXVTXNUM];
    char endcity[MAXVTXNUM];
    printf("\n-----�𳵳��в˵�-----\n");
    printf("�����������У�");
    scanf(" %s",startcity);
    printf("�������յ���У�");
    scanf(" %s",endcity);
    //ȷ������յ���ͼ��
    while(1)
    {
        for (i=0;i<city_whole;i++)
        {
            if(strcmp(trainGraph.Adjlist[i].cityName, startcity) == 0)
            {
                startindex = trainGraph.Adjlist[i].cityNumber;
                break;
            }
        }

        for (i=0;i<city_whole;i++)
        {
            if(strcmp(trainGraph.Adjlist[i].cityName, endcity) == 0)
            {
                endindex = trainGraph.Adjlist[i].cityNumber;
                break;
            }
        }

        if(startindex==-1 || endindex==-1 )
        {
            printf("������������յ㲻��ͼ�ڣ����������������յ�\n");
            printf("�����������У�");
            scanf(" %s",startcity);
            printf("�������յ���У�");
            scanf(" %s",endcity);
        }
        else
        {
            break;
        }
    }

    //��ѡ����з�ʽ
    printf("-----���з���-----\n");
    printf("0���������з���\n");
    printf("1����������ʱ��\n");
    printf("2��������ת����\n");
    printf("3��������һ��\n");
    printf("��ѡ����Ҫ���еķ�ʽ��0/1/2/3����");
    scanf("%d",&chooseway);
    while(1)
    {
        if(chooseway==0)
        {
            min_money(trainGraph,startindex,endindex);
            printf("-----���з���-----\n");
            printf("0���������з���\n");
            printf("1����������ʱ��\n");
            printf("2��������ת����\n");
            printf("3��������һ��\n");
            printf("��ѡ����Ҫ���еķ�ʽ��0/1/2/3����");
            scanf("%d",&chooseway);
        }
        else if(chooseway==1)
        {
            min_time(trainGraph,startindex,endindex);
            printf("-----���з���-----\n");
            printf("0���������з���\n");
            printf("1����������ʱ��\n");
            printf("2��������ת����\n");
            printf("3��������һ��\n");
            printf("��ѡ����Ҫ���еķ�ʽ��0/1/2/3����");
            scanf("%d",&chooseway);
        }
        else if(chooseway ==2)
        {
            min_shu(trainGraph,startindex,endindex);
            printf("-----���з���-----\n");
            printf("0���������з���\n");
            printf("1����������ʱ��\n");
            printf("2��������ת����\n");
            printf("3��������һ��\n");
            printf("��ѡ����Ҫ���еķ�ʽ��0/1/2/3����");
            scanf("%d",&chooseway);
        }
        else if(chooseway ==3)
        {
            break;
        }
        else
        {
            printf("\n�����ʽ�������������룺");
            scanf("%d",&chooseway);
        }
    }
}

//�ɻ����в˵�
void trainorplane_plane()
{
    int chooseway;
    int i;
    int startindex=-1;
    int endindex=-1;
    char startcity[MAXVTXNUM];
    char endcity[MAXVTXNUM];
    printf("\n-----�ɻ����в˵�-----\n");
    printf("�����������У�");
    scanf(" %s",startcity);
    printf("�������յ���У�");
    scanf(" %s",endcity);
    //ȷ������յ���ͼ��
    while(1)
    {
        for (i=0;i<city_whole;i++)
        {
            if(strcmp(planeGraph.Adjlist[i].cityName, startcity) == 0)
            {
                startindex = planeGraph.Adjlist[i].cityNumber;
                break;
            }
        }

        for (i=0;i<city_whole;i++)
        {
            if(strcmp(planeGraph.Adjlist[i].cityName, endcity) == 0)
            {
                endindex = planeGraph.Adjlist[i].cityNumber;
                break;
            }
        }

        if(startindex==-1 || endindex==-1 )
        {
            printf("������������յ㲻��ͼ�ڣ����������������յ�\n");
            printf("�����������У�");
            scanf(" %s",startcity);
            printf("�������յ���У�");
            scanf(" %s",endcity);
        }
        else
        {
            break;
        }
    }

    //��ѡ����з�ʽ
    printf("-----���з���-----\n");
    printf("0���������з���\n");
    printf("1����������ʱ��\n");
    printf("2��������ת����\n");
    printf("3��������һ��\n");
    printf("��ѡ����Ҫ���еķ�ʽ��0/1/2/3����");
    scanf("%d",&chooseway);
    while(1)
    {
        if(chooseway==0)
        {
            min_money(planeGraph,startindex,endindex);
            printf("-----���з���-----\n");
            printf("0���������з���\n");
            printf("1����������ʱ��\n");
            printf("2��������ת����\n");
            printf("3��������һ��\n");
            printf("��ѡ����Ҫ���еķ�ʽ��0/1/2/3����");
            scanf("%d",&chooseway);
        }
        else if(chooseway==1)
        {
            min_time(planeGraph,startindex,endindex);
            printf("-----���з���-----\n");
            printf("0���������з���\n");
            printf("1����������ʱ��\n");
            printf("2��������ת����\n");
            printf("3��������һ��\n");
            printf("��ѡ����Ҫ���еķ�ʽ��0/1/2/3����");
            scanf("%d",&chooseway);
        }
        else if(chooseway ==2)
        {
            min_shu(planeGraph,startindex,endindex);
            printf("-----���з���-----\n");
            printf("0���������з���\n");
            printf("1����������ʱ��\n");
            printf("2��������ת����\n");
            printf("3��������һ��\n");
            printf("��ѡ����Ҫ���еķ�ʽ��0/1/2/3����");
            scanf("%d",&chooseway);
        }
        else if(chooseway ==3)
        {
            break;
        }
        else
        {
            printf("\n�����ʽ�������������룺");
            scanf("%d",&chooseway);
        }
    }
}

//�û��˵�
void user()
{
    int chooseway;
    printf("\n-----�û���ѯ�˵�-----\n");
    printf("0���𳵳���\n");
    printf("1���ɻ�����\n");
    printf("2��������һ��\n");
    printf("��ѡ����Ҫ���еķ�ʽ��0/1/2����");
    scanf("%d",&chooseway);
    while(1)
    {
        if(chooseway==0)
        {
            trainorplane_train();
            printf("\n-----�û���ѯ�˵�-----\n");
            printf("0���𳵳���\n");
            printf("1���ɻ�����\n");
            printf("2��������һ��\n");
            printf("��ѡ����Ҫ���еķ�ʽ��0/1/2����");
            scanf("%d",&chooseway);
        }
        else if(chooseway==1)
        {
            trainorplane_plane();
            printf("\n-----�û���ѯ�˵�-----\n");
            printf("0���𳵳���\n");
            printf("1���ɻ�����\n");
            printf("2��������һ��\n");
            printf("��ѡ����Ҫ���еķ�ʽ��0/1/2����");
            scanf("%d",&chooseway);

        }
        else if(chooseway ==2)
        {
            break;
        }
        else
        {
            printf("\n�����ʽ�������������룺");
            scanf("%d",&chooseway);
        }
    }
}




/**** ������� ****/
//��ȡǮ����Ȩֵ
int get_weight_money(Graph G, int start, int end)
{
    EdgeNode *node;

    if (start==end)
        return 0;

    node = G.Adjlist[start].firstEdge;
    while (node!=NULL)
    {
        if (end==node->elem.jvex)
            return node->elem.Money;
        node = node->nextEdge;
    }
    return FINITY;
}

//��ȡȨ��
EdgeNode *get_weight(Graph G,int start, int end)
{
    EdgeNode *node;

    if (start==end)
        return NULL;

    node = G.Adjlist[start].firstEdge;
    while (node!=NULL)
    {
        if (end==node->elem.jvex)
            return node;
        node = node->nextEdge;
    }
    return NULL;
}

//���ٻ���Ǯ
void min_money(Graph G,int startindex,int endindex)
{
    //printf("min_money������\n");
    //printf("%d-----%d\n",startindex,endindex);
    int flag[MAXVTXNUM];      // flag[i]=1��ʾ"����vs"��"����i"�����·���ѳɹ���ȡ��
    EdgeNode *p;
    EdgeNode *prep;
    int i,k,j,v,min,x,tmp;
    //��ʼ��S���������d
    for (i = 0; i < G.vexNum; i++)
    {
        flag[i] = 0;                    // ����i�����·����û��ȡ����
        dist[i] = get_weight_money(G,startindex, i);  // ����i�����·��Ϊ"����vs"��"����i"��Ȩ��
        if(dist[i]<FINITY && dist[i]!=0)
            path[i]=startindex;
        else path[i]=-1;
    }
    // ��"����vs"������г�ʼ��
    flag[startindex] = 1;
    dist[startindex] = 0;
    // ����G.vexnum-1�Σ�ÿ���ҳ�һ����������·����
    for (i = 1; i < G.vexNum; i++)
    {
        // Ѱ�ҵ�ǰ��С��·����
        // ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(k)��
        min = FINITY;
        for (j = 0; j < G.vexNum; j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }
        //printf("\n%s------%d\n",G.Adjlist[k].cityName,min);


        if(min==FINITY)
        {
            continue;
        }
        // ���"����k"Ϊ�Ѿ���ȡ�����·��
        flag[k] = 1;

        // ������ǰ���·����ǰ������
        // �������Ѿ�"����k�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
        for (j = 0; j <  G.vexNum; j++)
        {
            tmp = get_weight_money(G,k, j);
            tmp = (tmp==FINITY ? FINITY : (min + tmp)); // ��ֹ���
            if (flag[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                path[j] = k;
            }
        }
    }

    // ��ӡdijkstra���·���Ľ��
    int st[MAXVTXNUM],pre,top=-1;
    printf("�������з���(%s---->%s): ", G.Adjlist[startindex].cityName,G.Adjlist[endindex].cityName);
    for (i = 0; i < G.vexNum; i++)
    {
        if(strcmp(G.Adjlist[i].cityName ,G.Adjlist[endindex].cityName)==0)
        {
            //Ү!�ҵ�bug������
            if(dist[i]==FINITY)
            {
                printf("δ�ҵ�����·�ߡ�������ѡ���ѯ��ʽ��\n");
            }
            else
            {
                printf("%d(Ԫ)\n",dist[i]);
                st[++top]=i;
                pre = path[i];
                while(pre!=-1)
                {
                    st[++top]=pre;
                    pre=path[pre];
                }
                printf("���з����ǣ�\n");
                printf("���  \t     �յ�  \t�г���\t\t����ʱ�䣨�֣�\t����ʱ�䣨�֣�\t��;ʱ�䣨�֣�\t���ã�Ԫ��\n");
                while(top>0)
                {
                    printroute(G,st[top],st[top-1]);
                    top--;
                }
            }


        }


    }

}

//���ٻ���ʱ��
void min_time(Graph G,int startindex,int endindex)
{
    //printf("min_time������\n");
    //printf("%d-----%d\n",startindex,endindex);
    int flag[MAXVTXNUM];      // flag[i]=1��ʾ"����vs"��"����i"�����·���ѳɹ���ȡ��
    EdgeNode *listnow,*listafter;//��ǰ��ȡ�ߵ�Ȩ��
    EdgeNode *p;
    EdgeNode *prep;
    int jiange;
    int i,k,j,v,min,x,tmp,afterstart,nowend,m;
    //��ʼ��S���������d
    for (i = 0; i < G.vexNum; i++)
    {
        //printf("i=%d------%s\n",i,G.Adjlist[i].cityName);
        flag[i] = 0;                    // ����i�����·����û��ȡ����
        listnow = get_weight(G,startindex, i);
        if(listnow!=NULL)
        {
            dist[i] = listnow->elem.EndTime-listnow->elem.StartTime;  // ����i�����·��Ϊ"����vs"��"����i"��Ȩ��
        }
        else dist[i] = FINITY;


        if(dist[i]<FINITY)
            path[i]=startindex;
        else path[i]=-1;
    }
    // ��"����vs"������г�ʼ��
    flag[startindex] = 1;
    dist[startindex] = 0;


    //��ӡ����
    /*for(i=0;i<G.vexNum;i++)
    {
        printf("dist[%d]=%d----",i,dist[i]);
        printf("path[%d]=%d\n",i,path[i]);
    }*/


    for (i = 1; i < G.vexNum; i++)
    {
        // Ѱ�ҵ�ǰ��С��·����
        // ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(k)��
        min = FINITY;

        for (j = 0; j < G.vexNum; j++)
        {
            if(path[j]!=-1 && !flag[j])
            {
                listnow = get_weight(G,path[j],j);
                if(path[path[j]]==-1)//��ʼѡ�ڶ����������
                {
                    afterstart=0;
                    nowend=0;
                }
                else
                {
                    listafter = get_weight(G,path[j],j);
                    listnow = get_weight(G,path[path[j]],path[j]);
                    afterstart = listafter->elem.StartTime;
                    nowend = listnow->elem.EndTime;
                }

                //printf("%s-----%s\n",G.Adjlist[listnow->elem.ivex].cityName,G.Adjlist[listnow->elem.jvex].cityName);
                //printf("\nnowend[%d]=%d---",j,nowend);
                //printf("afterstart[%d]=%d\n",j,afterstart);
            }
            else
            {
                afterstart=FINITY;
                nowend = 0;
                //printf("nowend[%d]=%d---",j,nowend);
                //printf("afterstart[%d]=%d\n",j,afterstart);
            }

            //printf("dist[%d]:%d\n",j,dist[j]);
            if (flag[j]==0 && dist[j]< min && afterstart>=nowend)
            {

                //printf("afterstart:%d---------nowend:%d\n",afterstart,nowend);
                //printf("dist[%d]=%d\n",j,dist[j]);
                min = dist[j];
                //printf("������j=%d---min=%d\n",j,min);
                k = j;
            }
        }

       // printf("k=%d------min=%d\n\n",k,min);


        if(min>=FINITY)
        {
            continue;
        }

        // ���"����k"Ϊ�Ѿ���ȡ�����·��
        flag[k] = 1;

        // ������ǰ���·����ǰ������
        // �������Ѿ�"����k�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
        for (j = 0; j < G.vexNum; j++)
        {
            listafter = get_weight(G,k,j);
            listnow = get_weight(G,path[k],k);

            if(listafter==NULL)
            {
                //printf("����\n");

            }
            else
            {
                nowend = listnow->elem.EndTime;
                afterstart = listafter->elem.StartTime;

                //printf("\n1111111111nowend[%d]=%d---",j,nowend);
                //printf("11111111111afterstart[%d]=%d\n",j,afterstart);

                jiange = afterstart-nowend;//����ȴ�


                tmp = listafter->elem.Time;//��;ʱ��


                //printf("tmp:%d\n",tmp);
                //printf("jiange:%d\n",jiange);
                //printf("min:%d\n",min);

                if(dist[j]==-1) tmp = min + tmp+jiange;
                else tmp = min + tmp+jiange;
                //tmp = min + tmp+jiange; // ��ֹ���
                //printf("tmp=%d\n",tmp);
                if (flag[j] == 0 && (tmp  < dist[j]) && jiange>=0)
                {
                    dist[j] = tmp;
                    path[j] = k;
                    //printf("dist[%d]=%d----",j,tmp);
                    //printf("path[%d]=%d\n",j,k);
                }
            }
            //��ӡ����
            //printf("��ӡ����\n");
            for(m=0;m<G.vexNum;m++)
            {
                //printf("dist[%d]=%d----",m,dist[m]);
                //printf("path[%d]=%d\n",m,path[m]);
            }
        }
    }



    // ��ӡdijkstra���ʱ��Ľ��
    int st[MAXVTXNUM],pre,top=-1;
    printf("��������ʱ��(%s---->%s): ", G.Adjlist[startindex].cityName,G.Adjlist[endindex].cityName);
    for (i = 0; i < G.vexNum; i++)
    {
        if(strcmp(G.Adjlist[i].cityName ,G.Adjlist[endindex].cityName)==0)
        {
            //Ү!�ҵ�bug������
            if(dist[i]>=FINITY)
            {
                printf("δ�ҵ�����·�ߡ�������ѡ���ѯ��ʽ��\n");
            }
            else
            {
                printf("%d(����)\n",dist[i]);
                st[++top]=i;
                pre = path[i];
                while(pre!=-1)
                {
                    st[++top]=pre;
                    pre=path[pre];
                }
                printf("���з����ǣ�\n");
                printf("���  \t     �յ�  \t�г���\t\t����ʱ�䣨�֣�\t����ʱ�䣨�֣�\t��;ʱ�䣨�֣�\t���ã�Ԫ��\n");
                while(top>0)
                {
                    printroute(G,st[top],st[top-1]);
                    top--;
                }
            }


        }


    }
}

//���ٻ��Ѵ���
void min_shu(Graph G,int startindex,int endindex)
{
    printf("��δ���ţ������ڴ���\n");
}



/**** ��ӡ ****/
//��ӡ·��
void printroute(Graph G,int start,int end)
{
    EdgeNode *node;

    if (start==end)
        printf("��·��");

    node = G.Adjlist[start].firstEdge;
    while (node!=NULL)
    {
        if (end==node->elem.jvex)
        {
            printf("%-10s   ",trainGraph.Adjlist[start].cityName);
            printf("%-10s\t",trainGraph.Adjlist[end].cityName);
            printf("%-7s\t\t",node->elem.Number);
            printf("%02d:%02d\t\t",node->elem.StartTime/60,node->elem.StartTime%60);
            printf("%02d:%02d\t\t",node->elem.EndTime/60,node->elem.EndTime%60);
            printf("%d\t\t",node->elem.Time);
            printf("%d��Ԫ��\n",node->elem.Money);
            break;
        }
        node = node->nextEdge;
    }
}
