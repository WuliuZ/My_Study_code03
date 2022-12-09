#include<iostream>
#include<stdio.h>
#include"JAB.H"
using namespace std;

int main() {
	AMGraph G;
	CreateUDN(G);
	char a = 0, b = 0;
	cout << "请输入您所求最短路径的两点：";
	cin >> a >> b;
	cout << endl;
	int v1 = findElemIndex(G, a), v2 = findElemIndex(G, b);
	shorttestPath_DIJ(G, v1, v2);
}