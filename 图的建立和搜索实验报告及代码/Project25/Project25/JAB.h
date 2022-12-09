#pragma once
#include <iostream>
using namespace std;
#define MVNum 10

typedef int DataType;	//ͼ���洢����Ϊint

//�ڽӾ���
typedef struct {
	DataType vexs[MVNum];	//int���͵����飬�����
	int arcs[MVNum][MVNum];		//��ά���飬����
	int vNum, aNum;	//��¼��ǰ����ͱ���
}AMGraph;		//��Ӿ���AMGraph

//�߽��
typedef struct ArcNode {
	int adjvex; //�ñ���ָ��ö���λ��
	struct ArcNode* nextArc; //ָ��ָ������ΪArcNode����һ���߽��
}ArcNode;

//��ͷ�ڵ�
typedef struct VNode {
	DataType data; //����
	ArcNode* firstarc; //ָ��߽ڵ�
}VNode, AdjList[MVNum];

//�ڽӱ�
typedef struct {
	AdjList vertices;//��Ŷ��������
	int vexnum, arcnum;//ͼ��ǰ�Ķ������ͱ���
}ALGraph;

struct SQueue {
	int front;		//����Ԫ��
	int rear;	//β��Ԫ��
	int* base;//�洢��ַ

};
//���нṹ����

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