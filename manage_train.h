

/****�������****/
//��ӻ�·��
void add_train_route()
{
    //1��mallocȥ����һ��edgenode
    //2�����̶���·�߻�����Ϣ����·�߻�����Ϣ�ŵ�edgenode��
    //3���ж�������Ϣ�����ʼ�����Ƿ���adjlist[i]��
    //4��������ڣ���printf����˵�ļ���û��������У�Ҫ������һ����ӳ���
    //5������ڣ�����ж��г����Ƿ���Ѵ��ڵ�·�߳�ͻ
    //6�������ͻ������ӣ��������ͻ����Ѹտ�ʼ������edgenodeͷ����������
    //7���������ļ���
    int i,j;
    int ivexnow=-1;
    int jvexnow=-1;
    int start_hour,start_min;
    int end_hour,end_min;
    int time;
    int train_money;
    char cityfrom[MAXVTXNUM];
    char cityto[MAXVTXNUM];
    char number[MAXVTXNUM];
    EdgeNode *f= (EdgeNode *)malloc(sizeof(EdgeNode));
    printf("������·�߻�����Ϣ��\n");
    printf("���    �յ�    ����ʱ��  ����ʱ��  �г���  ����\n");
    scanf("%s %s %2d:%2d %2d:%2d %s %d",cityfrom,cityto,&start_hour,&start_min,&end_hour,&end_min,number,&train_money);
    int flag=0;//û��·��
    for (i=0;i<city_whole;i++)
    {
        if (strcmp(trainGraph.Adjlist[i].cityName,cityfrom) == 0)
        {

            ivexnow = trainGraph.Adjlist[i].cityNumber;
            //printf("-------�ҵ���ʼ��������%d",ivexnow);
            for(j=0;j<city_whole;j++)
            {
                if (strcmp(trainGraph.Adjlist[j].cityName,cityto) == 0)
                {

                    jvexnow = trainGraph.Adjlist[j].cityNumber;
                    //printf("--------�ҵ��յ��������%d",jvexnow);
                    break;
                }
            }
            if(j==city_whole)
            {
                printf("����յ���в��ڵ�ͼ��뷵����һ����ӳ��С�");
                break;
            }
            EdgeNode *p=trainGraph.Adjlist[i].firstEdge;
            while(p)//�ж��Ƿ����ظ�
            {
                if(strcmp(trainGraph.Adjlist[p->elem.jvex].cityName,cityto)==0 && strcmp(p->elem.Number,number)==0)
                //�����յ���к��г����ظ�
                {
                    //printf("-------�ظ�����");
                    break;
                }
                p=p->nextEdge;
            }
            if(p!=NULL) printf("���г�·���Ѵ��ڣ�������ӣ�");
            else
            {
                //printf("--------���ظ��G��");
                f->elem.ivex=ivexnow;
                f->elem.jvex=jvexnow;
                //printf("ivex:%d\n",f->elem.ivex);
                //printf("jvex:%d\n",f->elem.jvex);
                f->elem.StartTime = start_hour*60+start_min;
                f->elem.EndTime = end_hour*60+end_min;
                //printf("starttime:%d\n",f->elem.StartTime);
                //printf("endtime:%d\n",f->elem.EndTime);
                f->elem.Time = f->elem.EndTime-f->elem.StartTime;
                //printf("time:%d\n",f->elem.Time);
                strcpy(f->elem.Number,number);
                //printf("number:%s\n",f->elem.Number);
                f->elem.Money =train_money;
                //printf("money:%d\n",f->elem.Money);
                trainGraph.edgeNum++;

                //printf("ͷ���һ��Ǯ���ǣ�%d\n",trainGraph.Adjlist[i].firstEdge->elem.Money);
                f->nextEdge=trainGraph.Adjlist[i].firstEdge;
                trainGraph.Adjlist[i].firstEdge=f;
            }
            show_train_route();
            break;
       }
    }
    if(i==city_whole) printf("�������в��ڵ�ͼ�У��뷵����һ����ӳ��С�");

    initagain();
    //writetrain_tofile();
    //show_train_route();
}

//ɾ����·��
void del_train_route()
{
    char start_city[MAXVTXNUM],end_city[MAXVTXNUM],number[MAXVTXNUM];
    int flag=0,i;
    printf("��ѡ����Ҫɾ���Ļ�·�ߵ���㣺");
    scanf("%s",start_city);
    printf("\n��ѡ����Ҫɾ���Ļ�·�ߵ��յ㣺");
    scanf("%s",end_city);
    printf("\n��ѡ����Ҫɾ�����г��ţ�");
    scanf("%s",number);
    for(i=0;i<city_whole;i++)
    {
        if(strcmp(trainGraph.Adjlist[i].cityName,start_city)==0)//�ҵ���ʼ�����Ƿ����
        {
            EdgeNode *p=trainGraph.Adjlist[i].firstEdge;
            EdgeNode *pre=NULL;
            while(p)
            {
                if(strcmp(trainGraph.Adjlist[p->elem.jvex].cityName,end_city)==0 && strcmp(p->elem.Number,number)==0)
                //if(strcmp(trainGraph.Adjlist[p->elem->jvex],end_city)==0)
                    //�յ��Ƿ���������У��г����Ƿ��Ǻ�
                {
                    if(pre==NULL)//����ǵ�һ��
                    {
                        trainGraph.Adjlist[i].firstEdge = p->nextEdge;
                        free(p);
                    }
                    else
                    {
                        pre->nextEdge = p->nextEdge;
                        free(p);
                    }
                    trainGraph.edgeNum--;
                    flag=1;
                    break;
                }
                pre=p;
                p=p->nextEdge;
            }
            if(flag==1) break;
        }

    }
    if(flag==0) printf("ϵͳ�ļ���û����Ҫɾ����·��");
    initagain();
}



/****��ӡ****/
//�����ӡ
void dfs(int i)
{
    EdgeNode *p;
    p = trainGraph.Adjlist[i].firstEdge;
    while(p)
    {
        printf("%-10s",trainGraph.Adjlist[i].cityName);
        printf("%-10s\t",trainGraph.Adjlist[p->elem.jvex].cityName);
        printf("%-5s\t\t",p->elem.Number);
        printf("%02d:%02d\t\t",p->elem.StartTime/60,p->elem.StartTime%60);
        printf("%02d:%02d\t\t",p->elem.EndTime/60,p->elem.EndTime%60);
        printf("%d\t\t",p->elem.Time);
        printf("%d��Ԫ��\n",p->elem.Money);
        p=p->nextEdge;
    }

}
//��ʾ��·��
void show_train_route()
{
    int i;
    printf("���  \t    �յ�  \t�г���\t\t����ʱ�䣨�֣�\t����ʱ�䣨�֣�\t��;ʱ�䣨�֣�\t���ã�Ԫ��\n");
    for(i=0;i<trainGraph.vexNum;i++)
    {
        trainGraph.Flag[i]=0;
    }
    for(i=0;i<trainGraph.vexNum;i++)
    {
        if(trainGraph.Adjlist[i].cityNumber==-1) continue;
        else dfs(i);
    }
}



/****�������****/
//���ļ������·��
void readtrain_fromfile()
{
    FILE *fp;
    int i,j;
    int ivexnow=-1;
    int jvexnow=-1;
    int start_hour,start_min;
    int end_hour,end_min;
    char cityfrom[MAXVTXNUM];
    char cityto[MAXVTXNUM];
    EdgeNode *s;
    fp = fopen("train.txt","r");
    if (!fp)
    {
        printf("�Ҳ����ļ���\n");
    }
    else
    {
        trainGraph.vexNum = city_whole;
        //printf("trainvex:%d\n",trainGraph.vexNum);
        fscanf(fp,"%d",&trainGraph.edgeNum);
        //printf("______%d",trainGraph.edgeNum);
        //trainGraph.vexNum=city_whole;
        //printf("_______%d",city_whole);
        for(i=0;i<trainGraph.vexNum;i++)
        {

            strcpy(trainGraph.Adjlist[i].cityName,CityName[i]);
            //printf("%s\n",trainGraph.Adjlist[i].cityName);
            trainGraph.Adjlist[i].cityNumber = i;
            trainGraph.Adjlist[i].firstEdge=NULL;
        }

        for (i=0;i<trainGraph.edgeNum;i++)
        {
            fscanf(fp,"%s",cityfrom);
            fscanf(fp,"%s",cityto);
            //printf("from:%s\t",cityfrom);
            //printf("to:%s",cityto);
            for(j=0;j<trainGraph.vexNum;j++)
            {
                //printf("(1):%s",trainGraph.Adjlist[i].cityName);
                //printf("    from:%s\n",cityfrom);
                if(strcmp(trainGraph.Adjlist[j].cityName,cityfrom)==0)
                {
                    ivexnow = trainGraph.Adjlist[j].cityNumber;
                    //printf("%d\n",ivexnow);
                }
                if(strcmp(trainGraph.Adjlist[j].cityName,cityto)==0)
                {
                    jvexnow = trainGraph.Adjlist[j].cityNumber;
                    //printf("%d\n",jvexnow);
                }
            }
            if(ivexnow!=-1 && jvexnow!=-1)
            {
                s = (EdgeNode *)malloc(sizeof(EdgeNode));
                s->elem.ivex=ivexnow;
                s->elem.jvex=jvexnow;
                fscanf(fp,"%d:%d",&start_hour,&start_min);
                //printf("start_hour:%d  start_min:%d\n",start_hour,start_min);
                s->elem.StartTime = start_hour*60+start_min;
                fscanf(fp,"%d:%d",&end_hour,&end_min);
                //printf("end_hour:%d  end_min:%d\n",end_hour,end_min);
                s->elem.EndTime = end_hour*60+end_min;
                s->elem.Time = s->elem.EndTime-s->elem.StartTime;
                //printf("%d\t",s->elem.StartTime);
                //printf("%d",s->elem.EndTime);

                fscanf(fp," %d",&s->elem.Money);
                //printf("Money:%d",s->elem.Money);
                fscanf(fp,"%s",s->elem.Number);
                //printf("�г��ţ�%s",s->elem.Number);
                s->nextEdge = trainGraph.Adjlist[ivexnow].firstEdge;
                trainGraph.Adjlist[ivexnow].firstEdge = s;
            }
            else printf("��ʼ������city.txt�в����ڣ�������ӳ���\n");
        }
        fclose(fp);
    }
}

//�����ݶ����ļ�
void writetrain_tofile()
{
    FILE *fp;
    int i;
    EdgeNode *p;
    fp = fopen("train.txt","wt");
    if(fp!=NULL)
    {
        fprintf(fp,"%d\n",trainGraph.edgeNum);
        for(i=0;i<city_whole;i++)
        {
            if(trainGraph.Adjlist[i].firstEdge!=NULL && trainGraph.Adjlist[i].cityNumber!=-1)
            {
                //printf("%s������·�ߣ�",trainGraph.Adjlist[i].cityName);
                p=trainGraph.Adjlist[i].firstEdge;
                while(p)
                {
                    fprintf(fp,"%s",trainGraph.Adjlist[i].cityName);
                    fprintf(fp," ");
                    fprintf(fp,"%s",trainGraph.Adjlist[p->elem.jvex].cityName);
                    fprintf(fp," ");
                    fprintf(fp,"%2d:%2d",p->elem.StartTime/60,p->elem.StartTime%60);
                    fprintf(fp," ");
                    fprintf(fp,"%2d:%2d",p->elem.EndTime/60,p->elem.EndTime%60);
                    fprintf(fp," ");
                    fprintf(fp,"%d",p->elem.Money);
                    fprintf(fp," ");
                    fprintf(fp,"%s",p->elem.Number);
                    fprintf(fp,"\n");
                    p=p->nextEdge;
                }
            }
        }
        fclose(fp);
    }
    //fclose(fp);
    else printf("����ʧ�ܣ�");

}




/****�˵�****/
//���ɾ���г�·�ߣ�
void add_del_trainroute()
{
    int choose;
    printf("\n-----���ɾ���г�·��-----��\n");
    printf("0:����г�·��\n");
    printf("1:ɾ���г�·��\n");
    printf("2:��ʾ�����г�·��\n");
    printf("3:������һ��\n");
    printf("��������Ҫѡ��ģ�0/1/2/3����");
    scanf("%d",&choose);
    while(1)
    {
        if(choose==0)
        {
            add_train_route();
            printf("\n-----���ɾ���г�·��-----��\n");
            printf("0:����г�·��\n");
            printf("1:ɾ���г�·��\n");
            printf("2:��ʾ�г�����·��\n");
            printf("3:������һ��\n");
            printf("��������Ҫѡ��ģ�0/1/2/3����");
            scanf("%d",&choose);
        }
        else if(choose==1)
        {
            del_train_route();
            printf("\n-----���ɾ���г�·��-----��\n");
            printf("0:����г�·��\n");
            printf("1:ɾ���г�·��\n");
            printf("2:��ʾ�г�����·��\n");
            printf("3:������һ��\n");
            printf("��������Ҫѡ��ģ�0/1/2/3����");
            scanf("%d",&choose);

        }
        else if (choose==2)
        {
            show_train_route();
            printf("\n-----���ɾ���г�·��-----��\n");
            printf("0:����г�·��\n");
            printf("1:ɾ���г�·��\n");
            printf("2:��ʾ�г�����·��\n");
            printf("3:������һ��\n");
            printf("��������Ҫѡ��ģ�0/1/2/3����");
            scanf("%d",&choose);

        }
        else if(choose==3)
        {
            break;
        }
        else
        {
            printf("�����ʽ����ȷ������������");
            scanf("%d",&choose);
        }
    }
}
