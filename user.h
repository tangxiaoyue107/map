/**** 菜单 ****/
//火车出行菜单
void trainorplane_train()
{
    int chooseway;
    int i;
    int startindex=-1;
    int endindex=-1;
    char startcity[MAXVTXNUM];
    char endcity[MAXVTXNUM];
    printf("\n-----火车出行菜单-----\n");
    printf("请输入起点城市：");
    scanf(" %s",startcity);
    printf("请输入终点城市：");
    scanf(" %s",endcity);
    //确保起点终点在图里
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
            printf("你输入的起点和终点不在图内，请重新输入起点和终点\n");
            printf("请输入起点城市：");
            scanf(" %s",startcity);
            printf("请输入终点城市：");
            scanf(" %s",endcity);
        }
        else
        {
            break;
        }
    }

    //请选择出行方式
    printf("-----出行方案-----\n");
    printf("0：最少旅行费用\n");
    printf("1：最少旅行时间\n");
    printf("2：最少中转次数\n");
    printf("3：返回上一步\n");
    printf("请选择你要出行的方式（0/1/2/3）：");
    scanf("%d",&chooseway);
    while(1)
    {
        if(chooseway==0)
        {
            min_money(trainGraph,startindex,endindex);
            printf("-----出行方案-----\n");
            printf("0：最少旅行费用\n");
            printf("1：最少旅行时间\n");
            printf("2：最少中转次数\n");
            printf("3：返回上一步\n");
            printf("请选择你要出行的方式（0/1/2/3）：");
            scanf("%d",&chooseway);
        }
        else if(chooseway==1)
        {
            min_time(trainGraph,startindex,endindex);
            printf("-----出行方案-----\n");
            printf("0：最少旅行费用\n");
            printf("1：最少旅行时间\n");
            printf("2：最少中转次数\n");
            printf("3：返回上一步\n");
            printf("请选择你要出行的方式（0/1/2/3）：");
            scanf("%d",&chooseway);
        }
        else if(chooseway ==2)
        {
            min_shu(trainGraph,startindex,endindex);
            printf("-----出行方案-----\n");
            printf("0：最少旅行费用\n");
            printf("1：最少旅行时间\n");
            printf("2：最少中转次数\n");
            printf("3：返回上一步\n");
            printf("请选择你要出行的方式（0/1/2/3）：");
            scanf("%d",&chooseway);
        }
        else if(chooseway ==3)
        {
            break;
        }
        else
        {
            printf("\n输入格式有误，请重新输入：");
            scanf("%d",&chooseway);
        }
    }
}

//飞机出行菜单
void trainorplane_plane()
{
    int chooseway;
    int i;
    int startindex=-1;
    int endindex=-1;
    char startcity[MAXVTXNUM];
    char endcity[MAXVTXNUM];
    printf("\n-----飞机出行菜单-----\n");
    printf("请输入起点城市：");
    scanf(" %s",startcity);
    printf("请输入终点城市：");
    scanf(" %s",endcity);
    //确保起点终点在图里
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
            printf("你输入的起点和终点不在图内，请重新输入起点和终点\n");
            printf("请输入起点城市：");
            scanf(" %s",startcity);
            printf("请输入终点城市：");
            scanf(" %s",endcity);
        }
        else
        {
            break;
        }
    }

    //请选择出行方式
    printf("-----出行方案-----\n");
    printf("0：最少旅行费用\n");
    printf("1：最少旅行时间\n");
    printf("2：最少中转次数\n");
    printf("3：返回上一步\n");
    printf("请选择你要出行的方式（0/1/2/3）：");
    scanf("%d",&chooseway);
    while(1)
    {
        if(chooseway==0)
        {
            min_money(planeGraph,startindex,endindex);
            printf("-----出行方案-----\n");
            printf("0：最少旅行费用\n");
            printf("1：最少旅行时间\n");
            printf("2：最少中转次数\n");
            printf("3：返回上一步\n");
            printf("请选择你要出行的方式（0/1/2/3）：");
            scanf("%d",&chooseway);
        }
        else if(chooseway==1)
        {
            min_time(planeGraph,startindex,endindex);
            printf("-----出行方案-----\n");
            printf("0：最少旅行费用\n");
            printf("1：最少旅行时间\n");
            printf("2：最少中转次数\n");
            printf("3：返回上一步\n");
            printf("请选择你要出行的方式（0/1/2/3）：");
            scanf("%d",&chooseway);
        }
        else if(chooseway ==2)
        {
            min_shu(planeGraph,startindex,endindex);
            printf("-----出行方案-----\n");
            printf("0：最少旅行费用\n");
            printf("1：最少旅行时间\n");
            printf("2：最少中转次数\n");
            printf("3：返回上一步\n");
            printf("请选择你要出行的方式（0/1/2/3）：");
            scanf("%d",&chooseway);
        }
        else if(chooseway ==3)
        {
            break;
        }
        else
        {
            printf("\n输入格式有误，请重新输入：");
            scanf("%d",&chooseway);
        }
    }
}

//用户菜单
void user()
{
    int chooseway;
    printf("\n-----用户咨询菜单-----\n");
    printf("0：火车出行\n");
    printf("1：飞机出行\n");
    printf("2：返回上一步\n");
    printf("请选择你要出行的方式（0/1/2）：");
    scanf("%d",&chooseway);
    while(1)
    {
        if(chooseway==0)
        {
            trainorplane_train();
            printf("\n-----用户咨询菜单-----\n");
            printf("0：火车出行\n");
            printf("1：飞机出行\n");
            printf("2：返回上一步\n");
            printf("请选择你要出行的方式（0/1/2）：");
            scanf("%d",&chooseway);
        }
        else if(chooseway==1)
        {
            trainorplane_plane();
            printf("\n-----用户咨询菜单-----\n");
            printf("0：火车出行\n");
            printf("1：飞机出行\n");
            printf("2：返回上一步\n");
            printf("请选择你要出行的方式（0/1/2）：");
            scanf("%d",&chooseway);

        }
        else if(chooseway ==2)
        {
            break;
        }
        else
        {
            printf("\n输入格式有误，请重新输入：");
            scanf("%d",&chooseway);
        }
    }
}




/**** 具体操作 ****/
//获取钱数的权值
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

//获取权重
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

//最少花费钱
void min_money(Graph G,int startindex,int endindex)
{
    //printf("min_money函数啦\n");
    //printf("%d-----%d\n",startindex,endindex);
    int flag[MAXVTXNUM];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。
    EdgeNode *p;
    EdgeNode *prep;
    int i,k,j,v,min,x,tmp;
    //初始化S与距离向量d
    for (i = 0; i < G.vexNum; i++)
    {
        flag[i] = 0;                    // 顶点i的最短路径还没获取到。
        dist[i] = get_weight_money(G,startindex, i);  // 顶点i的最短路径为"顶点vs"到"顶点i"的权。
        if(dist[i]<FINITY && dist[i]!=0)
            path[i]=startindex;
        else path[i]=-1;
    }
    // 对"顶点vs"自身进行初始化
    flag[startindex] = 1;
    dist[startindex] = 0;
    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G.vexNum; i++)
    {
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
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
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;

        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j <  G.vexNum; j++)
        {
            tmp = get_weight_money(G,k, j);
            tmp = (tmp==FINITY ? FINITY : (min + tmp)); // 防止溢出
            if (flag[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                path[j] = k;
            }
        }
    }

    // 打印dijkstra最短路径的结果
    int st[MAXVTXNUM],pre,top=-1;
    printf("最少旅行费用(%s---->%s): ", G.Adjlist[startindex].cityName,G.Adjlist[endindex].cityName);
    for (i = 0; i < G.vexNum; i++)
    {
        if(strcmp(G.Adjlist[i].cityName ,G.Adjlist[endindex].cityName)==0)
        {
            //耶!找到bug啦！！
            if(dist[i]==FINITY)
            {
                printf("未找到合适路线。请重新选择查询方式。\n");
            }
            else
            {
                printf("%d(元)\n",dist[i]);
                st[++top]=i;
                pre = path[i];
                while(pre!=-1)
                {
                    st[++top]=pre;
                    pre=path[pre];
                }
                printf("出行方案是：\n");
                printf("起点  \t     终点  \t列车号\t\t发车时间（分）\t到达时间（分）\t中途时间（分）\t费用（元）\n");
                while(top>0)
                {
                    printroute(G,st[top],st[top-1]);
                    top--;
                }
            }


        }


    }

}

//最少花费时间
void min_time(Graph G,int startindex,int endindex)
{
    //printf("min_time函数啦\n");
    //printf("%d-----%d\n",startindex,endindex);
    int flag[MAXVTXNUM];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。
    EdgeNode *listnow,*listafter;//当前获取边的权重
    EdgeNode *p;
    EdgeNode *prep;
    int jiange;
    int i,k,j,v,min,x,tmp,afterstart,nowend,m;
    //初始化S与距离向量d
    for (i = 0; i < G.vexNum; i++)
    {
        //printf("i=%d------%s\n",i,G.Adjlist[i].cityName);
        flag[i] = 0;                    // 顶点i的最短路径还没获取到。
        listnow = get_weight(G,startindex, i);
        if(listnow!=NULL)
        {
            dist[i] = listnow->elem.EndTime-listnow->elem.StartTime;  // 顶点i的最短路径为"顶点vs"到"顶点i"的权。
        }
        else dist[i] = FINITY;


        if(dist[i]<FINITY)
            path[i]=startindex;
        else path[i]=-1;
    }
    // 对"顶点vs"自身进行初始化
    flag[startindex] = 1;
    dist[startindex] = 0;


    //打印看看
    /*for(i=0;i<G.vexNum;i++)
    {
        printf("dist[%d]=%d----",i,dist[i]);
        printf("path[%d]=%d\n",i,path[i]);
    }*/


    for (i = 1; i < G.vexNum; i++)
    {
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        min = FINITY;

        for (j = 0; j < G.vexNum; j++)
        {
            if(path[j]!=-1 && !flag[j])
            {
                listnow = get_weight(G,path[j],j);
                if(path[path[j]]==-1)//开始选第二个最近城市
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
                //printf("换啦！j=%d---min=%d\n",j,min);
                k = j;
            }
        }

       // printf("k=%d------min=%d\n\n",k,min);


        if(min>=FINITY)
        {
            continue;
        }

        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;

        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j < G.vexNum; j++)
        {
            listafter = get_weight(G,k,j);
            listnow = get_weight(G,path[k],k);

            if(listafter==NULL)
            {
                //printf("不变\n");

            }
            else
            {
                nowend = listnow->elem.EndTime;
                afterstart = listafter->elem.StartTime;

                //printf("\n1111111111nowend[%d]=%d---",j,nowend);
                //printf("11111111111afterstart[%d]=%d\n",j,afterstart);

                jiange = afterstart-nowend;//间隔等待


                tmp = listafter->elem.Time;//中途时间


                //printf("tmp:%d\n",tmp);
                //printf("jiange:%d\n",jiange);
                //printf("min:%d\n",min);

                if(dist[j]==-1) tmp = min + tmp+jiange;
                else tmp = min + tmp+jiange;
                //tmp = min + tmp+jiange; // 防止溢出
                //printf("tmp=%d\n",tmp);
                if (flag[j] == 0 && (tmp  < dist[j]) && jiange>=0)
                {
                    dist[j] = tmp;
                    path[j] = k;
                    //printf("dist[%d]=%d----",j,tmp);
                    //printf("path[%d]=%d\n",j,k);
                }
            }
            //打印看看
            //printf("打印！！\n");
            for(m=0;m<G.vexNum;m++)
            {
                //printf("dist[%d]=%d----",m,dist[m]);
                //printf("path[%d]=%d\n",m,path[m]);
            }
        }
    }



    // 打印dijkstra最短时间的结果
    int st[MAXVTXNUM],pre,top=-1;
    printf("最少旅行时间(%s---->%s): ", G.Adjlist[startindex].cityName,G.Adjlist[endindex].cityName);
    for (i = 0; i < G.vexNum; i++)
    {
        if(strcmp(G.Adjlist[i].cityName ,G.Adjlist[endindex].cityName)==0)
        {
            //耶!找到bug啦！！
            if(dist[i]>=FINITY)
            {
                printf("未找到合适路线。请重新选择查询方式。\n");
            }
            else
            {
                printf("%d(分钟)\n",dist[i]);
                st[++top]=i;
                pre = path[i];
                while(pre!=-1)
                {
                    st[++top]=pre;
                    pre=path[pre];
                }
                printf("出行方案是：\n");
                printf("起点  \t     终点  \t列车号\t\t发车时间（分）\t到达时间（分）\t中途时间（分）\t费用（元）\n");
                while(top>0)
                {
                    printroute(G,st[top],st[top-1]);
                    top--;
                }
            }


        }


    }
}

//最少花费次数
void min_shu(Graph G,int startindex,int endindex)
{
    printf("暂未开放！敬情期待！\n");
}



/**** 打印 ****/
//打印路线
void printroute(Graph G,int start,int end)
{
    EdgeNode *node;

    if (start==end)
        printf("无路线");

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
            printf("%d（元）\n",node->elem.Money);
            break;
        }
        node = node->nextEdge;
    }
}
