/****具体操作****/
//添加城市
int add_city()
{
    //1、键盘上读入英文的城市
    //2、循环判断是否存在
    //3、城市放到cityname二维数组是（底端）
    //4、返回数组城市个数
    //1、键盘上读入英文的城市
    //2、循环判断是否存在
    //3、城市放到cityname二维数组是（底端）
    //4、返回数组城市个数
    int i;
    char addname[MAXVTXNUM];
    printf("请输入你要添加的城市名：");
    scanf("%s",addname);
    int flag=0;//是否含有城市
    for (i=0;i<city_whole;i++)
    {
       if (strcmp(CityName[i], addname) == 0)
       {
           printf("此城市已存在!\n");
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

//删除城市
int del_city()
{
    //1、显示文件中含有城市
    //2、选择城市，输入
    //3、删除，保存
    //4、确认是否删除
    char m[MAXVTXNUM];
    char y;
    int i;
    int city_index;
    int flag=0;
    show_city();//显示已有城市
    printf("目前已有的城市如上：请输入你要删除城市的名字：");
    scanf("%s",m);
    while(1)//找到城市的具体位置
    {
        for (i=0;i<city_whole;i++)
        {
            if(strcmp(CityName[i], m) == 0)
            {
                //printf("找到啦,%d",i);
                city_index=i;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("您输入的城市不存在，请重新输入：");
            scanf("%s",m);
        }
        else
        {
            break;
        }
    }
    printf("\n你确定要删除这个城市么(y/n)：");
    scanf(" %c",&y);
    while(1)
    {
        if(y=='y'||y=='Y')
        {
            for (i=city_index;i<city_whole;i++)
            {
                strcpy(CityName[i],CityName[i+1]);
            }
            //删除路线
            delcity_deleroute(&trainGraph,city_index);
            delcity_deleroute(&planeGraph,city_index);
            city_whole--;
            printf("删除成功。");
            break;
        }
        else if(y=='n'||y=='N')
        {
            printf("不");
            break;
        }
        else
        {
            printf("输入有误请重新输入:");
            scanf(" %c",&y);
        }
    }

    initagain();


    return city_whole;
}

//删除城市时删除所有路线
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
            //printf("找到G.Adjlist[%d].cityindex啦为%d！名字是%s\n",i,cityindex,G->Adjlist[i].cityName);
            p = G->Adjlist[i].firstEdge;
            while(p)
            {
                G->edgeNum--;
                p=p->nextEdge;
            }
            //printf("路线还有%d条",G->edgeNum);
            G->Adjlist[i].cityNumber=-1;
        }
        else
        {
            p = G->Adjlist[i].firstEdge;
            pre = NULL;
            while(p!=NULL)
            {
                //printf("p不为NULL！\n");
                if(p->elem.jvex==cityindex)
                {
                    //printf("找到jvex为cityindex!");
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



/****打印****/
//显示cityname中已含有城市
void show_city()
{
    //1、遍历cityname二维数组里面的城市
    int i;
    for (i=0;i<city_whole;i++)
    {
        printf("%s\n",CityName[i]);
    }
}



/****读入读回****/
//从文件中读入含有城市
void show_filecity()
{
    FILE *fp;
    int i;
    fp = fopen("city.txt","r");
    if (!fp)
    {
        printf("找不到文件！\n");
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

//读回文件中
void writeback_tofile()
{
  //1、个数
  //2、城市
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
  else printf("保存失败！");

}



/****菜单****/
//添加删除显示城市！
void add_del_city()
{
    int choose2;
    printf("\n-----管理员编辑菜单-----\n");
    printf("0:添加城市\n");
    printf("1:删除城市\n");
    printf("2:返回上一步\n");
    printf("3:显示文件中已含有城市\n");
    printf("请选择（0/1/2/3）：");
    scanf("%d",&choose2);
    while(1)
    {
        if(choose2==0)
        {
            city_whole = add_city();
            printf("\n-----管理员编辑菜单-----\n");
            printf("0:添加城市\n");
            printf("1:删除城市\n");
            printf("2:返回上一步\n");
            printf("3:显示文件中已含有城市\n");
            printf("请选择（0/1/2/3）：");
            scanf("%d",&choose2);
        }
        else if(choose2==1)
        {
            city_whole = del_city();
            printf("\n-----管理员编辑菜单-----\n");
            printf("0:添加城市\n");
            printf("1:删除城市\n");
            printf("2:返回上一步\n");
            printf("3:显示文件中已含有城市\n");
            printf("请选择（0/1/2/3）：");
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
            printf("\n-----管理员编辑菜单-----\n");
            printf("0:添加城市\n");
            printf("1:删除城市\n");
            printf("2:返回上一步\n");
            printf("3:显示文件中已含有城市\n");
            printf("请选择（0/1/2/3）：");
            scanf("%d",&choose2);
        }
        else
        {
            printf("\n输入格式有误，请重新输入：");
            scanf("%d",&choose2);
        }
    }

}


//管理员初始选择菜单
void manage()
{
    int choose1;
    printf("\n-----管理员编辑菜单-----\n");
    printf("0：添加删除城市\n");
    printf("1：添加删除列车路线\n");
    printf("2：添加删除飞机路线\n");
    printf("3：返回上一步\n");
    printf("请选择（0/1/2/3）：");
    scanf("%d",&choose1);
    while(1)
    {
        if(choose1==0)
        {
            add_del_city();
            printf("\n-----管理员编辑菜单-----\n");
            printf("0：添加删除城市\n");
            printf("1：添加删除列车路线\n");
            printf("2：添加删除飞机路线\n");
            printf("3：返回上一步\n");
            printf("请选择（0/1/2/3）：");
            scanf("%d",&choose1);
        }
        else if(choose1==1)
        {
            add_del_trainroute();
            printf("\n-----管理员编辑菜单-----\n");
            printf("0：添加删除城市\n");
            printf("1：添加删除列车路线\n");
            printf("2：添加删除飞机路线\n");
            printf("3：返回上一步\n");
            printf("请选择（0/1/2/3）：");
            scanf("%d",&choose1);

        }
        else if(choose1 ==2)
        {
            add_del_planeroute();
            printf("\n-----管理员编辑菜单-----\n");
            printf("0：添加删除城市\n");
            printf("1：添加删除列车路线\n");
            printf("2：添加删除飞机路线\n");
            printf("3：返回上一步\n");
            printf("请选择（0/1/2/3）：");
            scanf("%d",&choose1);
        }
        else if(choose1==3)
        {
            break;
        }
        else
        {
            printf("\n输入格式有误，请重新输入：");
            scanf("%d",&choose1);
        }
    }

}
