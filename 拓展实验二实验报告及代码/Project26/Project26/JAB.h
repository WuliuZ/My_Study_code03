#pragma once
#pragma once
#include <iostream>
using namespace std;
#define MVNum 10
#define MAX_INT 16382

typedef char DataType;	//图所存储类型为int

//邻接矩阵
typedef struct {
	DataType vexs[MVNum];	//char类型的数组，边名
	int arcs[MVNum][MVNum];		//二维数组，矩阵
	int vexnum, arcnum;	//记录当前顶点和边数
}AMGraph;		//领接矩阵AMGraph

int findElemIndex(AMGraph& G, char v);
int CreateUDN(AMGraph& G);
void shorttestPath_DIJ(AMGraph G, int v0, int vt);
string getPlaceName(char a);