#define MAXVTXNUM 25
#define FINITY 5000
/************ ���㡢�ߺ�ͼ���� **********************************/
// ��������μ��������Ϣ ������Ϣ
typedef struct
{
    int ivex; // ��ʼ���
    int jvex; // �յ��
    char Number[10]; // ���κ�
    int Money; // ����
    int StartTime; // ��ʼʱ�䣨�룩
    int EndTime; // ��ֹʱ�䣨�룩
    int Time; // ��;ʱ�䣨�룩
}EdgeInfo;


typedef struct node // �ߵ���Ϣ �����
{
    EdgeInfo elem;
    struct node *nextEdge;
}EdgeNode; // �ߵĽ�����ͣ�ָ��ߵ�ָ��



// ������Ϣ ͷ���
typedef struct
{
    char cityName[10];//��������
    int cityNumber;//��������
    EdgeNode *firstEdge; // ָ���һ�������ö���ıߵ�ָ��
}Vnode;


// ͼ�Ľṹ
typedef struct
{
    Vnode Adjlist[MAXVTXNUM];// �ڽӱ�
    int vexNum, edgeNum; // ͼ�еĶ������ͱ���
    int Flag[MAXVTXNUM]; // ��־�Ƿ���ͼ�еĶ��� ,0 ��ʾ���� ,1 ��ʾ��
}Graph; // ͼ����

int dist[MAXVTXNUM];
int path[MAXVTXNUM];

int city_whole;
char CityName[MAXVTXNUM][MAXVTXNUM];
Graph trainGraph;
Graph planeGraph;
