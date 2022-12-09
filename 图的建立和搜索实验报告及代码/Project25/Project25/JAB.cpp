#include<iostream>
#include<stdio.h>
#include"JAB.h"
using namespace std;
#define MVNum 10

int InitSQueue(SQueue& S, int size) {
	S.base = new int[size];				//动态分配空间并赋予地址
	if (!S.base) { cout << "分配内存失败"; }		//判断是否分配成功
	S.front = 0;
	S.rear = 0;
	return 0;
}
//初始化循环队列

bool Empty(SQueue& S) {
	return S.front == S.rear;
}
//判空

int Enter(SQueue& S, int e) {

	S.base[S.rear] = e;
	S.rear++;
	//cout << "入队成功！";
	return 0;
}
//入队

int Out(SQueue& S, int& e) {
	if (Empty(S)) { cout << "已空"; }
	e = S.base[S.front];		//保存头元素
	S.front++;
	//cout << e << "已成功出列";		//输出头元素
	return 0;
}
//出队

void RunSQ(SQueue& S) {
	if (Empty(S)) { cout << "队列为空"; }
	int a = S.front;
	while (a <= (S.rear - 1)) {
		cout << S.base[a] << ",";
		a++;
	}
}
//遍历


int Length(SQueue& S) {
	if (Empty(S)) { cout << "长度为0！"; }		//判空
	return S.front - S.rear;
}
//求长

void Clear(SQueue& S)
{
	S.rear = S.front;
	cout << "清空成功" << endl;
}
//清空队列

void Destroy(SQueue& S)
{
	free(S.base);
	S.front = S.rear = 0;
	//cout << "销毁成功" << endl;
}
//销毁队列

int Top(SQueue& S) {
	if (!Empty(S)) {
		return S.base[S.front];
	}
	return 0;
	//判断队列非空，返回头元素
}
//取头元素


//查找下标
int LocateVexJ(AMGraph& G, int v) {
	int Locate = -1;
	for (int i = 0;i < MVNum;i++) {
		if (v == G.vexs[i]) {
			Locate = i;
			break;
		}
	}
	return Locate;
}
int LocateVexB(ALGraph& G, int v) {
	int Locate = -1;
	for (int i = 0;i < MVNum;i++) {
		if (v == G.vertices[i].data) {
			Locate = i;
		}
	}
	return Locate;
}

//初始化邻接矩阵
int CreateUDN(AMGraph& G) {
	cout << "请输入总顶点数：";
	cin >> G.vNum;			//总顶点数
	cout << "请输入总边数：";
	cin >> G.aNum;			//总边数
	for (int i = 0;i < G.vNum;++i) {
		cout << "请输入第" << i + 1 << "个顶点：";
		cin >> G.vexs[i];  //记录下顶点信息
	}
	cout << endl;
	//构造矩阵
	cout << "注意请只输入边！" << endl;
	for (int j = 0;j < G.aNum;++j) {
		int v1, v2, w;
		int m, n;

		cout << "请输入前顶点：";
		cin >> v1;
		cout << "请输入后顶点：";
		cin >> v2;				//输入了两个顶点v1和v2
		cout  << "是否连通？（1为是，0为否）：" ;
		cin >> w;
		cout << endl;
		m = LocateVexJ(G, v1);
		n = LocateVexJ(G, v2);		//确定v1v2在G里的位置
		G.arcs[m][n] = w;		//赋值为1表示连通
		G.arcs[n][m] = G.arcs[m][n];	//达到对称
	}


	return 1;
}

//初始化邻接表
int CreateUDG(ALGraph& G) {
	cout << "请输入总顶点数：";
	cin >> G.vexnum;
	cout << "请输入总边数：";
	cin >> G.arcnum;
	//构造表头节点表
	for (int i = 0;i < G.vexnum;++i) {
		cout << "请输入第" << i + 1 << "个顶点：";
		cin >> G.vertices[i].data;		//输入顶点值
		G.vertices[i].firstarc = NULL;	//指针赋空
	}
	//构造邻接表
	for (int k = 0;k < G.arcnum;++k) {
		int v1, v2;
		int m, n;
		cout << "请输入前顶点：";
		cin >> v1;
		cout << "请输入后顶点：";
		cin >> v2;
		//确定v1v2的位置
		cout << endl;
		m = LocateVexB(G, v1);
		n = LocateVexB(G, v2);
		ArcNode* p1 = new ArcNode;	//生成边节点
		p1->adjvex = n;				//邻接的序号为n
		p1->nextArc = G.vertices[m].firstarc;
		G.vertices[m].firstarc = p1;
	}
	return 1;
}

//矩阵
//返回第v个顶点的第一个邻接点,无则返回-1
int FirstAdjVexJ(AMGraph G, int v) {
	int output = -1;//输出结果

	//for遍历找到第v个节点那一行里第一个邻接点
	for (int i = 0;i < MVNum;i++) {
		if (G.arcs[v][i] == 1) {
			output = i;
			break;
		}
	}
	return output;
}
//返回v相对于w的下一个邻接点，无则返回-1
int NextAdjVexJ(AMGraph G, int v, int w) {
	int output = -1;

	for (int i = w + 1;i < MVNum;i++) {
		if (G.arcs[v][i] == 1) {
			output = i;
			break;
		}
	}
	return output;
}

//表
//返回第v个顶点的第一个邻接点,无则返回-1
int FirstAdjVexB(ALGraph G, int v) {
	return G.vertices[v].firstarc && G.vertices[v].firstarc->adjvex != NULL ? G.vertices[v].firstarc->adjvex : -1;
}
//返回v相对于w的下一个邻接点，无则返回-1
int NextAdjVexB(ALGraph G, int v, int w) {
	ArcNode* temp = G.vertices[v].firstarc;
	while (temp->nextArc && temp->nextArc->adjvex != w) {
		temp = temp->nextArc;
	}
	return temp->nextArc ? temp->nextArc->adjvex : -1;
}

//邻接矩阵深度优先
bool visited[MVNum];		//标致数组
void DFSJ(AMGraph G, int v) {
	cout << G.vexs[v];		//访问第v个节点
	visited[v] = true;			//将第v个标识为true
	for (int w = FirstAdjVexJ(G, v);w >= 0;w = NextAdjVexJ(G, v, w)) {
		if (!visited[w]) {
			DFSJ(G, w);
		}
	}

}
//邻接表深度优先
void DFSB(ALGraph G, int v) {
	bool visited1[MVNum] = { 0 };
	cout << G.vertices[v].data;		//访问第v个节点
	visited1[v] = true;			//将第v个标识为true
	for (int w = FirstAdjVexB(G, v);w >= 0;w = NextAdjVexB(G, v, w)) {
		if (!visited1[w]) {
			DFSB(G, w);
		}
	}

}


//邻接矩阵广度优先
void BFSJ(AMGraph G, int v) {
	bool visited1[MVNum] = {0};
	cout << G.vexs[v];
	visited1[v] = true;
	SQueue Q;
	InitSQueue(Q, MVNum);	//队列初始化
	
	
	Enter(Q, v);	//入队
	int u = 0;		//存放队头
	while (!Empty(Q)) {
		Out(Q,u);
		for (int w = FirstAdjVexJ(G,u);w >= 0;w = NextAdjVexJ(G, u, w)) {
			if (!visited1[w]) {
				cout << G.vexs[w];
				visited1[w] = true;
				Enter(Q, w);
			}
		}
	}
	Destroy(Q);
}
//邻接表广度优先
void BFSB(ALGraph G, int v) {
	bool visited1[MVNum] = {0};
	SQueue Q;	
	InitSQueue(Q, MVNum);	//队列初始化
	cout << G.vertices[v].data;
	visited1[v] = true;
	Enter(Q, v);	//入队
	int u = 0;		//存放队头
	while (!Empty(Q)) {
		Out(Q,u);
		for (int w = FirstAdjVexB(G, u);w >= 0;w = NextAdjVexB(G, u, w)) {
			if (!visited1[w]) {
				cout << G.vertices[w].data;
				visited1[w] = true;
				Enter(Q, w);
			}
		}
	}
	Destroy(Q);
}