#include<iostream>
#include<stdio.h>
#include"JAB.h"
using namespace std;

int flag;
void shorttestPath_DIJ(AMGraph G, int v0,int vt) {
	int n = G.vexnum;	//顶点数量
	bool S[MVNum];	//记录从v0到vi的路径是否已被确定为最短
	int Path[MVNum];//记录从v0到vi的当前最短路径上vi的直接前驱顶点序号
	int D[MVNum];	//记录从v0到vi的当前最短路径长度

	for (int i = 0;i < n;i++) {
		S[i] = false;
		D[i] = G.arcs[v0][i];
		if (D[i] < MAX_INT) {
			Path[i] = v0;
		}
		else {
			Path[i] = -1;
		}
	}
	S[v0] = true;
	D[v0] = 0;

	for (int k = 0;k < n;k++) {
		int v = -1;
		if (k == v0) {
			continue;
		}
		int min = MAX_INT;
		for (int i = 0;i < n;i++) {
			if (!S[i] && D[i] < min) {
				v = i;
				min = D[i];
			}
		}
		S[v] = true;
		for (int i = 0;i < n;i++) {
			if (!S[i] && (D[v] + G.arcs[v][i] < D[i])) {
				D[i] = D[v] + G.arcs[v][i];
				Path[i] = v;
			}
		}
	}

	cout << D[vt] << endl;

	flag = D[vt];
	int v = vt;
	int a[MVNum];
	int num = 0;
	do {
		a[num]	 = v;
		v = Path[v];
		num++;
		if (v == v0) {
			a[num] = v;
			num++;
			break;
		}
	} while (true);

	for (int i = num - 1;i >= 0;i--) {
		cout << G.vexs[a[i]];
		if (i != 0) {
			cout << "---->";
		}
	}
	cout << endl;
	for (int i = num - 1;i >= 0;i--) {
		cout << G.vexs[a[i]]<<":"<< getPlaceName(G.vexs[a[i]])<<"  ";

	}
	cout << endl;
		for (int i = num - 1;i >= 0;i--) {
			cout << getPlaceName(G.vexs[a[i]]);
			if (i != 0) {
				cout << "---->";
			}
		}
	cout << endl;

		cout << getPlaceName(G.vexs[v0]) << "到" << getPlaceName(G.vexs[vt]) << "的最短距离为" << D[vt] << "米\n";
}

string getPlaceName(char a) {
	switch (a) {
	case 'A':
		return "数字图书馆";
		break;
	case 'B':
		return "第二教学楼";
		break;
	case 'C':
		return "中心食堂";
		break;
	case 'D':
		return "老图书馆";
		break;
	case 'E':
		return "信科大楼";
		break;
	case 'F':
		return "宁静苑二舍";
		break;
	default:
		cout << "error!";
		break;
	}
		

}


int CreateUDN(AMGraph& G) {
	cout << "请输入总顶点数：";
	cin >> G.vexnum;			//总顶点数
	cout << "请输入总边数：";
	cin >> G.arcnum;			//总边数
	for (int i = 0;i < G.vexnum;++i) {
		cout << "请输入第" << i + 1 << "个顶点：";
		cin >> G.vexs[i];  //记录下顶点信息
	}
	cout << endl;

	//初始化领接矩阵
	for (int i = 0;i < G.vexnum;i++) {
		for (int j = 0;j < G.vexnum;j++) {
			G.arcs[i][j] = 16382;
		}
	}

	for (int i = 0;i < G.arcnum;i++) {
		char a = 0, b = 0;
		int weight = MAX_INT;
		cout << "请输入边的顶点a,b的值!" << endl;
		cin >> a >> b;
		cout << "请输入a,b边对应权重!" << endl;
		cin >> weight;
		int v1 = findElemIndex(G, a);
		int v2 = findElemIndex(G, b);//寻找对应下标
		G.arcs[v1][v2] = weight;
		G.arcs[v2][v1] = G.arcs[v1][v2];
	}


	return 1;
}


//通过字符在图中寻找相对应的顶点下标
int findElemIndex(AMGraph& G, char v) {
	int Locate = -1;
	for (int i = 0;i < MVNum;i++) {
		if (v == G.vexs[i]) {
			Locate = i;
			break;
		}
	}
	return Locate;
}


