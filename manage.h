/****�������****/
//��ӳ���
int add_city()
{
    //1�������϶���Ӣ�ĵĳ���
    //2��ѭ���ж��Ƿ����
    //3�����зŵ�cityname��ά�����ǣ��׶ˣ�
    //4������������и���
    //1�������϶���Ӣ�ĵĳ���
    //2��ѭ���ж��Ƿ����
    //3�����зŵ�cityname��ά�����ǣ��׶ˣ�
    //4������������и���
    int i;
    char addname[MAXVTXNUM];
    printf("��������Ҫ��ӵĳ�������");
    scanf("%s",addname);
    int flag=0;//�Ƿ��г���
    for (i=0;i<city_whole;i++)
    {
       if (strcmp(CityName[i], addname) == 0)
       {
           printf("�˳����Ѵ���!\n");
           flag==1;
           break;
       }
    }
    if(flag==0)
    {
        strcpy(CityName[city_whole],addname);
        city_whole++;
        //trainGraph.vexNum++;
        //planeGraph.vexNum++;
    }
    initagain();
    return city_whole;
}

//ɾ������
int del_city()
{
    //1����ʾ�ļ��к��г���
    //2��ѡ����У�����
    //3��ɾ��������
    //4��ȷ���Ƿ�ɾ��
    char m[MAXVTXNUM];
    char y;
    int i;
    int city_index;
    int flag=0;
    show_city();//��ʾ���г���
    printf("Ŀǰ���еĳ������ϣ���������Ҫɾ�����е����֣�");
    scanf("%s",m);
    while(1)//�ҵ����еľ���λ��
    {
        for (i=0;i<city_whole;i++)
        {
            if(strcmp(CityName[i], m) == 0)
            {
                //printf("�ҵ���,%d",i);
                city_index=i;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("������ĳ��в����ڣ����������룺");
            scanf("%s",m);
        }
        else
        {
            break;
        }
    }
    printf("\n��ȷ��Ҫɾ���������ô(y/n)��");
    scanf(" %c",&y);
    while(1)
    {
        if(y=='y'||y=='Y')
        {
            for (i=city_index;i<city_whole;i++)
            {
                strcpy(CityName[i],CityName[i+1]);
            }
            //ɾ��·��
            delcity_deleroute(&trainGraph,city_index);
            delcity_deleroute(&planeGraph,city_index);
            city_whole--;
            printf("ɾ���ɹ���");
            break;
        }
        else if(y=='n'||y=='N')
        {
            printf("��");
            break;
        }
        else
        {
            printf("������������������:");
            scanf(" %c",&y);
        }
    }

    initagain();


    return city_whole;
}

//ɾ������ʱɾ������·��
void delcity_deleroute(Graph *G,int cityindex)
{
    int i,j;
    int times = city_whole;
    EdgeNode *p,*pre,*freep;
    for(i=0;i<times;i++)
    {
        //printf("i=%d\n",i);
        if(G->Adjlist[i].cityNumber==cityindex)
        {
            //printf("�ҵ�G.Adjlist[%d].cityindex��Ϊ%d��������%s\n",i,cityindex,G->Adjlist[i].cityName);
            p = G->Adjlist[i].firstEdge;
            while(p)
            {
                G->edgeNum--;
                p=p->nextEdge;
            }
            //printf("·�߻���%d��",G->edgeNum);
            G->Adjlist[i].cityNumber=-1;
        }
        else
        {
            p = G->Adjlist[i].firstEdge;
            pre = NULL;
            while(p!=NULL)
            {
                //printf("p��ΪNULL��\n");
                if(p->elem.jvex==cityindex)
                {
                    //printf("�ҵ�jvexΪcityindex!");
                    freep = p;
                    if(pre==NULL) G->Adjlist[i].firstEdge = p->nextEdge;
                    else pre->nextEdge = p->nextEdge;
                    G->edgeNum--;
                    p=p->nextEdge;
                    free(freep);
                }
                else
                {
                    pre=p;
                    p=p->nextEdge;
                }
            }
        }
    }
}



/****��ӡ****/
//��ʾcityname���Ѻ��г���
void show_city()
{
    //1������cityname��ά��������ĳ���
    int i;
    for (i=0;i<city_whole;i++)
    {
        printf("%s\n",CityName[i]);
    }
}



/****�������****/
//���ļ��ж��뺬�г���
void show_filecity()
{
    FILE *fp;
    int i;
    fp = fopen("city.txt","r");
    if (!fp)
    {
        printf("�Ҳ����ļ���\n");
    }
    else
    {
        fscanf(fp,"%d",&city_whole);
        //printf("%d\n",city_whole);
        for (i=0;i<city_whole;i++)
        {
            fscanf(fp,"%s",CityName[i]);
            //printf("%s\n",CityName[i]);
        }
        fclose(fp);
    }
}

//�����ļ���
void writeback_tofile()
{
  //1������
  //2������
  FILE *fp;
  int i;
  fp = fopen("city.txt","wt");
  if(fp!=NULL)
  {
    fprintf(fp,"%d\n",city_whole);
    for(i=0;i<city_whole;i++)
    {
        fprintf(fp,"%s\n",CityName[i]);
    }
    fclose(fp);
  }
  else printf("����ʧ�ܣ�");

}



/****�˵�****/
//���ɾ����ʾ���У�
void add_del_city()
{
    int choose2;
    printf("\n-----����Ա�༭�˵�-----\n");
    printf("0:��ӳ���\n");
    printf("1:ɾ������\n");
    printf("2:������һ��\n");
    printf("3:��ʾ�ļ����Ѻ��г���\n");
    printf("��ѡ��0/1/2/3����");
    scanf("%d",&choose2);
    while(1)
    {
        if(choose2==0)
        {
            city_whole = add_city();
            printf("\n-----����Ա�༭�˵�-----\n");
            printf("0:��ӳ���\n");
            printf("1:ɾ������\n");
            printf("2:������һ��\n");
            printf("3:��ʾ�ļ����Ѻ��г���\n");
            printf("��ѡ��0/1/2/3����");
            scanf("%d",&choose2);
        }
        else if(choose2==1)
        {
            city_whole = del_city();
            printf("\n-----����Ա�༭�˵�-----\n");
            printf("0:��ӳ���\n");
            printf("1:ɾ������\n");
            printf("2:������һ��\n");
            printf("3:��ʾ�ļ����Ѻ��г���\n");
            printf("��ѡ��0/1/2/3����");
            scanf("%d",&choose2);
        }
        else if(choose2==2)
        {
            writeback_tofile();
            break;
        }
        else if(choose2==3)
        {
            show_city();
            printf("\n-----����Ա�༭�˵�-----\n");
            printf("0:��ӳ���\n");
            printf("1:ɾ������\n");
            printf("2:������һ��\n");
            printf("3:��ʾ�ļ����Ѻ��г���\n");
            printf("��ѡ��0/1/2/3����");
            scanf("%d",&choose2);
        }
        else
        {
            printf("\n�����ʽ�������������룺");
            scanf("%d",&choose2);
        }
    }

}


//����Ա��ʼѡ��˵�
void manage()
{
    int choose1;
    printf("\n-----����Ա�༭�˵�-----\n");
    printf("0�����ɾ������\n");
    printf("1�����ɾ���г�·��\n");
    printf("2�����ɾ���ɻ�·��\n");
    printf("3��������һ��\n");
    printf("��ѡ��0/1/2/3����");
    scanf("%d",&choose1);
    while(1)
    {
        if(choose1==0)
        {
            add_del_city();
            printf("\n-----����Ա�༭�˵�-----\n");
            printf("0�����ɾ������\n");
            printf("1�����ɾ���г�·��\n");
            printf("2�����ɾ���ɻ�·��\n");
            printf("3��������һ��\n");
            printf("��ѡ��0/1/2/3����");
            scanf("%d",&choose1);
        }
        else if(choose1==1)
        {
            add_del_trainroute();
            printf("\n-----����Ա�༭�˵�-----\n");
            printf("0�����ɾ������\n");
            printf("1�����ɾ���г�·��\n");
            printf("2�����ɾ���ɻ�·��\n");
            printf("3��������һ��\n");
            printf("��ѡ��0/1/2/3����");
            scanf("%d",&choose1);

        }
        else if(choose1 ==2)
        {
            add_del_planeroute();
            printf("\n-----����Ա�༭�˵�-----\n");
            printf("0�����ɾ������\n");
            printf("1�����ɾ���г�·��\n");
            printf("2�����ɾ���ɻ�·��\n");
            printf("3��������һ��\n");
            printf("��ѡ��0/1/2/3����");
            scanf("%d",&choose1);
        }
        else if(choose1==3)
        {
            break;
        }
        else
        {
            printf("\n�����ʽ�������������룺");
            scanf("%d",&choose1);
        }
    }

}
