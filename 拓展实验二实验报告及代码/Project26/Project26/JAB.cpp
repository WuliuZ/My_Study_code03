#include<iostream>
#include<stdio.h>
#include"JAB.h"
using namespace std;

int flag;
void shorttestPath_DIJ(AMGraph G, int v0,int vt) {
	int n = G.vexnum;	//��������
	bool S[MVNum];	//��¼��v0��vi��·���Ƿ��ѱ�ȷ��Ϊ���
	int Path[MVNum];//��¼��v0��vi�ĵ�ǰ���·����vi��ֱ��ǰ���������
	int D[MVNum];	//��¼��v0��vi�ĵ�ǰ���·������

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

		cout << getPlaceName(G.vexs[v0]) << "��" << getPlaceName(G.vexs[vt]) << "����̾���Ϊ" << D[vt] << "��\n";
}

string getPlaceName(char a) {
	switch (a) {
	case 'A':
		return "����ͼ���";
		break;
	case 'B':
		return "�ڶ���ѧ¥";
		break;
	case 'C':
		return "����ʳ��";
		break;
	case 'D':
		return "��ͼ���";
		break;
	case 'E':
		return "�ſƴ�¥";
		break;
	case 'F':
		return "����Է����";
		break;
	default:
		cout << "error!";
		break;
	}
		

}


int CreateUDN(AMGraph& G) {
	cout << "�������ܶ�������";
	cin >> G.vexnum;			//�ܶ�����
	cout << "�������ܱ�����";
	cin >> G.arcnum;			//�ܱ���
	for (int i = 0;i < G.vexnum;++i) {
		cout << "�������" << i + 1 << "�����㣺";
		cin >> G.vexs[i];  //��¼�¶�����Ϣ
	}
	cout << endl;

	//��ʼ����Ӿ���
	for (int i = 0;i < G.vexnum;i++) {
		for (int j = 0;j < G.vexnum;j++) {
			G.arcs[i][j] = 16382;
		}
	}

	for (int i = 0;i < G.arcnum;i++) {
		char a = 0, b = 0;
		int weight = MAX_INT;
		cout << "������ߵĶ���a,b��ֵ!" << endl;
		cin >> a >> b;
		cout << "������a,b�߶�ӦȨ��!" << endl;
		cin >> weight;
		int v1 = findElemIndex(G, a);
		int v2 = findElemIndex(G, b);//Ѱ�Ҷ�Ӧ�±�
		G.arcs[v1][v2] = weight;
		G.arcs[v2][v1] = G.arcs[v1][v2];
	}


	return 1;
}


//ͨ���ַ���ͼ��Ѱ�����Ӧ�Ķ����±�
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


