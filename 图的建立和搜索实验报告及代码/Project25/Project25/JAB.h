#pragma once
#include <iostream>
using namespace std;
#define MVNum 10

typedef int DataType;	//图所存储类型为int

//邻接矩阵
typedef struct {
	DataType vexs[MVNum];	//int类型的数组，顶点表
	int arcs[MVNum][MVNum];		//二维数组，矩阵
	int vNum, aNum;	//记录当前顶点和边数
}AMGraph;		//领接矩阵AMGraph

//边结点
typedef struct ArcNode {
	int adjvex; //该边所指向得顶点位置
	struct ArcNode* nextArc; //指针指向类型为ArcNode得下一个边结点
}ArcNode;

//表头节点
typedef struct VNode {
	DataType data; //数据
	ArcNode* firstarc; //指向边节点
}VNode, AdjList[MVNum];

//邻接表
typedef struct {
	AdjList vertices;//存放顶点的数组
	int vexnum, arcnum;//图当前的顶点数和边数
}ALGraph;

struct SQueue {
	int front;		//顶部元素
	int rear;	//尾部元素
	int* base;//存储地址

};
//队列结构定义

int InitSQueue(SQueue& S, int size);
bool Empty(SQueue& S);
int Enter(SQueue& S, int e);
int Out(SQueue& S, int& e);
void RunSQ(SQueue& S);
int Length(SQueue& S);
void Clear(SQueue& S);
void Destroy(SQueue& S);
int Top(SQueue& S);

int LocateVexJ(AMGraph& G, int v) ;
int LocateVexB(ALGraph& G, int v);
int CreateUDN(AMGraph& G);
int CreateUDG(ALGraph& G);
int FirstAdjVexJ(AMGraph G, int v);
int NextAdjVexJ(AMGraph G, int v, int w);
int FirstAdjVexB(ALGraph G, int v);
int NextAdjVexB(ALGraph G, int v, int w);
void DFSJ(AMGraph G, int v);
void DFSB(ALGraph G, int v);
void BFSJ(AMGraph G, int v);
void BFSB(ALGraph G, int v);