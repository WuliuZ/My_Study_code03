#include<iostream>
#include"JAB.h"
using namespace std;
int main() {
	int v1,v2,v3,v4;
	AMGraph MG;
	cout << "���д����ڽӾ���"<<endl;
	CreateUDN(MG);

	ALGraph LG;
	cout << "���д����ڽӱ�" << endl;
	CreateUDG(LG);

	cout << "�ڽӾ���������ȱ�����";
	cin >> v1;
	--v1;
	DFSJ(MG, v1);

	cout << endl;
	cout << "�ڽӱ�������ȱ�����";
	cin >> v2;
	--v2;
	DFSB(LG, v2);

	cout << endl;
	cout << "�ڽӾ��������ȱ�����";
	cin >> v3;
	--v3;
	BFSJ(MG, v3);

	cout << endl;
	cout << "�ڽӱ������ȱ�����";
	cin >> v4;
	--v4;
	BFSB(LG, v4);


	

}