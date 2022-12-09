#include<iostream>
#include"JAB.h"
using namespace std;
int main() {
	int v1,v2,v3,v4;
	AMGraph MG;
	cout << "进行创建邻接矩阵"<<endl;
	CreateUDN(MG);

	ALGraph LG;
	cout << "进行创建邻接表" << endl;
	CreateUDG(LG);

	cout << "邻接矩阵深度优先遍历：";
	cin >> v1;
	--v1;
	DFSJ(MG, v1);

	cout << endl;
	cout << "邻接表深度优先遍历：";
	cin >> v2;
	--v2;
	DFSB(LG, v2);

	cout << endl;
	cout << "邻接矩阵广度优先遍历：";
	cin >> v3;
	--v3;
	BFSJ(MG, v3);

	cout << endl;
	cout << "邻接表广度优先遍历：";
	cin >> v4;
	--v4;
	BFSB(LG, v4);


	

}