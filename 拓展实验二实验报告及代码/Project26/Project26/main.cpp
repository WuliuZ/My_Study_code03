#include<iostream>
#include<stdio.h>
#include"JAB.H"
using namespace std;

int main() {
	AMGraph G;
	CreateUDN(G);
	char a = 0, b = 0;
	cout << "���������������·�������㣺";
	cin >> a >> b;
	cout << endl;
	int v1 = findElemIndex(G, a), v2 = findElemIndex(G, b);
	shorttestPath_DIJ(G, v1, v2);
}