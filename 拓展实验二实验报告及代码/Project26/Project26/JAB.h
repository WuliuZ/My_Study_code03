#pragma once
#pragma once
#include <iostream>
using namespace std;
#define MVNum 10
#define MAX_INT 16382

typedef char DataType;	//ͼ���洢����Ϊint

//�ڽӾ���
typedef struct {
	DataType vexs[MVNum];	//char���͵����飬����
	int arcs[MVNum][MVNum];		//��ά���飬����
	int vexnum, arcnum;	//��¼��ǰ����ͱ���
}AMGraph;		//��Ӿ���AMGraph

int findElemIndex(AMGraph& G, char v);
int CreateUDN(AMGraph& G);
void shorttestPath_DIJ(AMGraph G, int v0, int vt);
string getPlaceName(char a);