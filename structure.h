#define MAXVTXNUM 25
#define FINITY 5000
/************ 顶点、边和图类型 **********************************/
// 定义各车次及航班的信息 弧的信息
typedef struct
{
    int ivex; // 起始点号
    int jvex; // 终点号
    char Number[10]; // 车次号
    int Money; // 费用
    int StartTime; // 起始时间（秒）
    int EndTime; // 终止时间（秒）
    int Time; // 中途时间（秒）
}EdgeInfo;


typedef struct node // 边的信息 弧结点
{
    EdgeInfo elem;
    struct node *nextEdge;
}EdgeNode; // 边的结点类型，指向边的指针



// 城市信息 头结点
typedef struct
{
    char cityName[10];//城市名字
    int cityNumber;//？？？？
    EdgeNode *firstEdge; // 指向的一条依附该顶点的边的指针
}Vnode;


// 图的结构
typedef struct
{
    Vnode Adjlist[MAXVTXNUM];// 邻接表
    int vexNum, edgeNum; // 图中的顶点数和边数
    int Flag[MAXVTXNUM]; // 标志是否是图中的顶点 ,0 表示不是 ,1 表示是
}Graph; // 图类型

int dist[MAXVTXNUM];
int path[MAXVTXNUM];

int city_whole;
char CityName[MAXVTXNUM][MAXVTXNUM];
Graph trainGraph;
Graph planeGraph;
