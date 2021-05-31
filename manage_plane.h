

/****�������****/

//��ӷɻ�·��
void add_plane_route()
{
    int i,j;
    int ivexnow=-1;
    int jvexnow=-1;
    int start_hour,start_min;
    int end_hour,end_min;
    int time;
    int plane_money;
    char cityfrom[MAXVTXNUM];
    char cityto[MAXVTXNUM];
    char number[MAXVTXNUM];
    EdgeNode *f= (EdgeNode *)malloc(sizeof(EdgeNode));
    printf("������·�߻�����Ϣ��\n");
    printf("���    �յ�    ����ʱ��  ����ʱ��  �ɻ���  ����\n");
    scanf("%s %s %2d:%2d %2d:%2d %s %d",cityfrom,cityto,&start_hour,&start_min,&end_hour,&end_min,number,&plane_money);
    int flag=0;//û��·��
    for (i=0;i<city_whole;i++)
    {
        if (strcmp(planeGraph.Adjlist[i].cityName,cityfrom) == 0)
        {

            ivexnow = planeGraph.Adjlist[i].cityNumber;
            //printf("-------�ҵ���ʼ��������%d",ivexnow);
            for(j=0;j<city_whole;j++)
            {
                if (strcmp(planeGraph.Adjlist[j].cityName,cityto) == 0)
                {

                    jvexnow = planeGraph.Adjlist[j].cityNumber;
                    //printf("--------�ҵ��յ��������%d",jvexnow);
                    break;
                }
            }
            if(j==city_whole)
            {
                printf("����յ���в��ڵ�ͼ��뷵����һ����ӳ��С�");
                break;
            }
            EdgeNode *p=planeGraph.Adjlist[i].firstEdge;
            while(p)//�ж��Ƿ����ظ�
            {
                if(strcmp(planeGraph.Adjlist[p->elem.jvex].cityName,cityto)==0 && strcmp(p->elem.Number,number)==0)
                //�����յ���кͷɻ����ظ�
                {
                    //printf("-------�ظ�����");
                    break;
                }
                p=p->nextEdge;
            }
            if(p!=NULL) printf("�ú���·���Ѵ��ڣ�������ӣ�");
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
                f->elem.Money =plane_money;
                //printf("money:%d\n",f->elem.Money);
                planeGraph.edgeNum++;

                //printf("ͷ���һ��Ǯ���ǣ�%d\n",planeGraph.Adjlist[i].firstEdge->elem.Money);
                f->nextEdge=planeGraph.Adjlist[i].firstEdge;
                planeGraph.Adjlist[i].firstEdge=f;
            }
            show_plane_route();
            break;
       }
    }
    if(i==city_whole) printf("�������в��ڵ�ͼ�У��뷵����һ����ӳ��С�");
    initagain();

}
//ɾ���ɻ�·��
void del_plane_route()
{

    char start_city[MAXVTXNUM],end_city[MAXVTXNUM],number[MAXVTXNUM];
    int flag=0,i;
    printf("��ѡ����Ҫɾ���ķɻ�·�ߵ���㣺");
    scanf("%s",start_city);
    printf("\n��ѡ����Ҫɾ���ķɻ�·�ߵ��յ㣺");
    scanf("%s",end_city);
    printf("\n��ѡ����Ҫɾ���ĺ���ţ�");
    scanf("%s",number);
    for(i=0;i<city_whole;i++)
    {
        if(strcmp(planeGraph.Adjlist[i].cityName,start_city)==0)//�ҵ���ʼ�����Ƿ����
        {
            EdgeNode *p=planeGraph.Adjlist[i].firstEdge;
            EdgeNode *pre=NULL;
            while(p)
            {
                if(strcmp(planeGraph.Adjlist[p->elem.jvex].cityName,end_city)==0 && strcmp(p->elem.Number,number)==0)
                //if(strcmp(planeGraph.Adjlist[p->elem->jvex],end_city)==0)
                    //�յ��Ƿ���������У��ɻ����Ƿ��Ǻ�
                {
                    if(pre==NULL)//����ǵ�һ��
                    {
                        planeGraph.Adjlist[i].firstEdge = p->nextEdge;
                        free(p);
                    }
                    else
                    {
                        pre->nextEdge = p->nextEdge;
                        free(p);
                    }
                    planeGraph.edgeNum--;
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
    //writeplane_tofile();
    initagain();
}


/****��ӡ****/
//�����ӡ
void printdfs(int i)
{
    EdgeNode *p;
    p = planeGraph.Adjlist[i].firstEdge;
    while(p)
    {
        printf("%-10s   ",planeGraph.Adjlist[i].cityName);
        printf("%-10s\t",planeGraph.Adjlist[p->elem.jvex].cityName);
        printf("%-6s\t\t",p->elem.Number);
        printf("%02d:%02d\t\t",p->elem.StartTime/60,p->elem.StartTime%60);
        printf("%02d:%02d\t\t",p->elem.EndTime/60,p->elem.EndTime%60);
        printf("%d\t\t",p->elem.Time);
        printf("%d��Ԫ��\n",p->elem.Money);
        p=p->nextEdge;
    }

}
//��ʾ�ɻ�·��
void show_plane_route()
{
    int i;
    printf("���  \t      �յ�  \t�����\t\t����ʱ�䣨�֣�\t����ʱ�䣨�֣�\t��;ʱ�䣨�֣�\t���ã�Ԫ��\n");
    for(i=0;i<planeGraph.vexNum;i++)
    {
        planeGraph.Flag[i]=0;
    }
    for(i=0;i<planeGraph.vexNum;i++)
    {
        if(planeGraph.Adjlist[i].cityNumber==-1) continue;
        printdfs(i);
    }
}





/****�������****/
//���ļ�����ɻ�·��
void readplane_fromfile()
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
    fp = fopen("plane.txt","r");
    if (!fp)
    {
        printf("�Ҳ����ļ���\n");
    }
    else
    {
        //printf("111");
        planeGraph.vexNum = city_whole;
        fscanf(fp,"%d",&planeGraph.edgeNum);
        //printf("______%d",planeGraph.edgeNum);
        //planeGraph.vexNum=city_whole;
        //printf("_______%d",city_whole);
        for(i=0;i<planeGraph.vexNum;i++)
        {

            strcpy(planeGraph.Adjlist[i].cityName,CityName[i]);
            //printf("%s\n",planeGraph.Adjlist[i].cityName);
            planeGraph.Adjlist[i].cityNumber = i;
            planeGraph.Adjlist[i].firstEdge=NULL;
        }
        //printf("____%d",planeGraph.edgeNum);
        for (i=0;i<planeGraph.edgeNum;i++)
        {
            fscanf(fp,"%s",cityfrom);
            fscanf(fp,"%s",cityto);
            //printf("from:%s\t",cityfrom);
            //printf("to:%s",cityto);
            for(j=0;j<planeGraph.vexNum;j++)
            {
                //printf("(1):%s",planeGraph.Adjlist[i].cityName);
                //printf("    from:%s\n",cityfrom);
                if(strcmp(planeGraph.Adjlist[j].cityName,cityfrom)==0)
                {
                    ivexnow = planeGraph.Adjlist[j].cityNumber;
                    //printf("%d\n",ivexnow);
                }
                if(strcmp(planeGraph.Adjlist[j].cityName,cityto)==0)
                {
                    jvexnow = planeGraph.Adjlist[j].cityNumber;
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
                //printf("����ţ�%s",s->elem.Number);
                s->nextEdge = planeGraph.Adjlist[ivexnow].firstEdge;
                planeGraph.Adjlist[ivexnow].firstEdge = s;
            }
            else printf("��ʼ������city.txt�в����ڣ�������ӳ���\n");
        }
        fclose(fp);
    }
}

//�����ݶ����ļ�
void writeplane_tofile()
{
    FILE *fp;
    int i;
    EdgeNode *p;
    fp = fopen("plane.txt","wt");
    if(fp!=NULL)
    {
        fprintf(fp,"%d\n",planeGraph.edgeNum);
        for(i=0;i<city_whole;i++)
        {
            if(planeGraph.Adjlist[i].firstEdge!=NULL && planeGraph.Adjlist[i].cityNumber!=-1)
            {
                //printf("%s������·�ߣ�",planeGraph.Adjlist[i].cityName);
                p=planeGraph.Adjlist[i].firstEdge;
                while(p)
                {
                    fprintf(fp,"%s",planeGraph.Adjlist[i].cityName);
                    fprintf(fp," ");
                    fprintf(fp,"%s",planeGraph.Adjlist[p->elem.jvex].cityName);
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
//���ɾ���ɻ�·�ߣ�
void add_del_planeroute()
{
    int choose;
    printf("\n-----���ɾ���ɻ�·��-----��\n");
    printf("0:���·��\n");
    printf("1:ɾ��·��\n");
    printf("2:��ʾ����·��\n");
    printf("3:������һ��\n");
    printf("��������Ҫѡ��ģ�0/1/2/3����");
    scanf("%d",&choose);
    while(1)
    {
        if(choose==0)
        {
            add_plane_route();
            printf("\n-----���ɾ���ɻ�·��-----��\n");
            printf("0:���·��\n");
            printf("1:ɾ��·��\n");
            printf("2:��ʾ����·��\n");
            printf("3:������һ��\n");
            printf("��������Ҫѡ��ģ�0/1/2/3����");
            scanf("%d",&choose);
        }
        else if(choose==1)
        {
            del_plane_route();
            printf("\n-----���ɾ���ɻ�·��-----��\n");
            printf("0:���·��\n");
            printf("1:ɾ��·��\n");
            printf("2:��ʾ����·��\n");
            printf("3:������һ��\n");
            printf("��������Ҫѡ��ģ�0/1/2/3����");
            scanf("%d",&choose);

        }
        else if (choose==2)
        {
            show_plane_route();
            printf("\n-----���ɾ���ɻ�·��-----��\n");
            printf("0:���·��\n");
            printf("1:ɾ��·��\n");
            printf("2:��ʾ����·��\n");
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
