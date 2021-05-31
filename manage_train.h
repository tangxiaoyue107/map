

/****具体操作****/
//添加火车路线
void add_train_route()
{
    //1、malloc去创建一个edgenode
    //2、键盘读入路线基本信息，把路线基本信息放到edgenode里
    //3、判断输入信息里的起始城市是否在adjlist[i]里
    //4、如果不在，则printf告诉说文件中没有这个城市，要返回上一级添加城市
    //5、如果在，你就判断列车号是否和已存在的路线冲突
    //6、如果冲突则不能添加，如果不冲突，则把刚开始创建的edgenode头插入链表中
    //7、保存入文件中
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
    printf("请输入路线基本信息：\n");
    printf("起点    终点    发车时间  到达时间  列车号  费用\n");
    scanf("%s %s %2d:%2d %2d:%2d %s %d",cityfrom,cityto,&start_hour,&start_min,&end_hour,&end_min,number,&train_money);
    int flag=0;//没有路线
    for (i=0;i<city_whole;i++)
    {
        if (strcmp(trainGraph.Adjlist[i].cityName,cityfrom) == 0)
        {

            ivexnow = trainGraph.Adjlist[i].cityNumber;
            //printf("-------找到起始城市啦！%d",ivexnow);
            for(j=0;j<city_whole;j++)
            {
                if (strcmp(trainGraph.Adjlist[j].cityName,cityto) == 0)
                {

                    jvexnow = trainGraph.Adjlist[j].cityNumber;
                    //printf("--------找到终点城市啦！%d",jvexnow);
                    break;
                }
            }
            if(j==city_whole)
            {
                printf("你的终点城市不在地图里，请返回上一步添加城市。");
                break;
            }
            EdgeNode *p=trainGraph.Adjlist[i].firstEdge;
            while(p)//判断是否有重复
            {
                if(strcmp(trainGraph.Adjlist[p->elem.jvex].cityName,cityto)==0 && strcmp(p->elem.Number,number)==0)
                //存在终点城市和列车号重复
                {
                    //printf("-------重复啦！");
                    break;
                }
                p=p->nextEdge;
            }
            if(p!=NULL) printf("该列车路线已存在，不能添加！");
            else
            {
                //printf("--------不重复欸！");
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

                //printf("头插第一个钱数是：%d\n",trainGraph.Adjlist[i].firstEdge->elem.Money);
                f->nextEdge=trainGraph.Adjlist[i].firstEdge;
                trainGraph.Adjlist[i].firstEdge=f;
            }
            show_train_route();
            break;
       }
    }
    if(i==city_whole) printf("该起点城市不在地图中，请返回上一步添加城市。");

    initagain();
    //writetrain_tofile();
    //show_train_route();
}

//删除火车路线
void del_train_route()
{
    char start_city[MAXVTXNUM],end_city[MAXVTXNUM],number[MAXVTXNUM];
    int flag=0,i;
    printf("请选择你要删除的火车路线的起点：");
    scanf("%s",start_city);
    printf("\n请选择你要删除的火车路线的终点：");
    scanf("%s",end_city);
    printf("\n请选择你要删除的列车号：");
    scanf("%s",number);
    for(i=0;i<city_whole;i++)
    {
        if(strcmp(trainGraph.Adjlist[i].cityName,start_city)==0)//找到起始城市是否存在
        {
            EdgeNode *p=trainGraph.Adjlist[i].firstEdge;
            EdgeNode *pre=NULL;
            while(p)
            {
                if(strcmp(trainGraph.Adjlist[p->elem.jvex].cityName,end_city)==0 && strcmp(p->elem.Number,number)==0)
                //if(strcmp(trainGraph.Adjlist[p->elem->jvex],end_city)==0)
                    //终点是否存在链表中，列车号是否吻合
                {
                    if(pre==NULL)//如果是第一个
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
    if(flag==0) printf("系统文件中没有你要删除的路线");
    initagain();
}



/****打印****/
//链表打印
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
        printf("%d（元）\n",p->elem.Money);
        p=p->nextEdge;
    }

}
//显示火车路线
void show_train_route()
{
    int i;
    printf("起点  \t    终点  \t列车号\t\t发车时间（分）\t到达时间（分）\t中途时间（分）\t费用（元）\n");
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



/****读入读回****/
//从文件读入火车路线
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
        printf("找不到文件！\n");
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
                //printf("列车号：%s",s->elem.Number);
                s->nextEdge = trainGraph.Adjlist[ivexnow].firstEdge;
                trainGraph.Adjlist[ivexnow].firstEdge = s;
            }
            else printf("起始城市在city.txt中不存在，请先添加城市\n");
        }
        fclose(fp);
    }
}

//将数据读回文件
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
                //printf("%s城市有路线！",trainGraph.Adjlist[i].cityName);
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
    else printf("保存失败！");

}




/****菜单****/
//添加删除列车路线！
void add_del_trainroute()
{
    int choose;
    printf("\n-----添加删除列车路线-----！\n");
    printf("0:添加列车路线\n");
    printf("1:删除列车路线\n");
    printf("2:显示已有列车路线\n");
    printf("3:返回上一步\n");
    printf("请输入你要选择的（0/1/2/3）：");
    scanf("%d",&choose);
    while(1)
    {
        if(choose==0)
        {
            add_train_route();
            printf("\n-----添加删除列车路线-----！\n");
            printf("0:添加列车路线\n");
            printf("1:删除列车路线\n");
            printf("2:显示列车已有路线\n");
            printf("3:返回上一步\n");
            printf("请输入你要选择的（0/1/2/3）：");
            scanf("%d",&choose);
        }
        else if(choose==1)
        {
            del_train_route();
            printf("\n-----添加删除列车路线-----！\n");
            printf("0:添加列车路线\n");
            printf("1:删除列车路线\n");
            printf("2:显示列车已有路线\n");
            printf("3:返回上一步\n");
            printf("请输入你要选择的（0/1/2/3）：");
            scanf("%d",&choose);

        }
        else if (choose==2)
        {
            show_train_route();
            printf("\n-----添加删除列车路线-----！\n");
            printf("0:添加列车路线\n");
            printf("1:删除列车路线\n");
            printf("2:显示列车已有路线\n");
            printf("3:返回上一步\n");
            printf("请输入你要选择的（0/1/2/3）：");
            scanf("%d",&choose);

        }
        else if(choose==3)
        {
            break;
        }
        else
        {
            printf("输入格式不正确，请重新输入");
            scanf("%d",&choose);
        }
    }
}
