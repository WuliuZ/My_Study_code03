#include<iostream>
#include<stdio.h>
#include"JAB.h"
using namespace std;
#define MVNum 10

int InitSQueue(SQueue& S, int size) {
	S.base = new int[size];				//��̬����ռ䲢�����ַ
	if (!S.base) { cout << "�����ڴ�ʧ��"; }		//�ж��Ƿ����ɹ�
	S.front = 0;
	S.rear = 0;
	return 0;
}
//��ʼ��ѭ������

bool Empty(SQueue& S) {
	return S.front == S.rear;
}
//�п�

int Enter(SQueue& S, int e) {

	S.base[S.rear] = e;
	S.rear++;
	//cout << "��ӳɹ���";
	return 0;
}
//���

int Out(SQueue& S, int& e) {
	if (Empty(S)) { cout << "�ѿ�"; }
	e = S.base[S.front];		//����ͷԪ��
	S.front++;
	//cout << e << "�ѳɹ�����";		//���ͷԪ��
	return 0;
}
//����

void RunSQ(SQueue& S) {
	if (Empty(S)) { cout << "����Ϊ��"; }
	int a = S.front;
	while (a <= (S.rear - 1)) {
		cout << S.base[a] << ",";
		a++;
	}
}
//����


int Length(SQueue& S) {
	if (Empty(S)) { cout << "����Ϊ0��"; }		//�п�
	return S.front - S.rear;
}
//��

void Clear(SQueue& S)
{
	S.rear = S.front;
	cout << "��ճɹ�" << endl;
}
//��ն���

void Destroy(SQueue& S)
{
	free(S.base);
	S.front = S.rear = 0;
	//cout << "���ٳɹ�" << endl;
}
//���ٶ���

int Top(SQueue& S) {
	if (!Empty(S)) {
		return S.base[S.front];
	}
	return 0;
	//�ж϶��зǿգ�����ͷԪ��
}
//ȡͷԪ��


//�����±�
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

//��ʼ���ڽӾ���
int CreateUDN(AMGraph& G) {
	cout << "�������ܶ�������";
	cin >> G.vNum;			//�ܶ�����
	cout << "�������ܱ�����";
	cin >> G.aNum;			//�ܱ���
	for (int i = 0;i < G.vNum;++i) {
		cout << "�������" << i + 1 << "�����㣺";
		cin >> G.vexs[i];  //��¼�¶�����Ϣ
	}
	cout << endl;
	//�������
	cout << "ע����ֻ����ߣ�" << endl;
	for (int j = 0;j < G.aNum;++j) {
		int v1, v2, w;
		int m, n;

		cout << "������ǰ���㣺";
		cin >> v1;
		cout << "������󶥵㣺";
		cin >> v2;				//��������������v1��v2
		cout  << "�Ƿ���ͨ����1Ϊ�ǣ�0Ϊ�񣩣�" ;
		cin >> w;
		cout << endl;
		m = LocateVexJ(G, v1);
		n = LocateVexJ(G, v2);		//ȷ��v1v2��G���λ��
		G.arcs[m][n] = w;		//��ֵΪ1��ʾ��ͨ
		G.arcs[n][m] = G.arcs[m][n];	//�ﵽ�Գ�
	}


	return 1;
}

//��ʼ���ڽӱ�
int CreateUDG(ALGraph& G) {
	cout << "�������ܶ�������";
	cin >> G.vexnum;
	cout << "�������ܱ�����";
	cin >> G.arcnum;
	//�����ͷ�ڵ��
	for (int i = 0;i < G.vexnum;++i) {
		cout << "�������" << i + 1 << "�����㣺";
		cin >> G.vertices[i].data;		//���붥��ֵ
		G.vertices[i].firstarc = NULL;	//ָ�븳��
	}
	//�����ڽӱ�
	for (int k = 0;k < G.arcnum;++k) {
		int v1, v2;
		int m, n;
		cout << "������ǰ���㣺";
		cin >> v1;
		cout << "������󶥵㣺";
		cin >> v2;
		//ȷ��v1v2��λ��
		cout << endl;
		m = LocateVexB(G, v1);
		n = LocateVexB(G, v2);
		ArcNode* p1 = new ArcNode;	//���ɱ߽ڵ�
		p1->adjvex = n;				//�ڽӵ����Ϊn
		p1->nextArc = G.vertices[m].firstarc;
		G.vertices[m].firstarc = p1;
	}
	return 1;
}

//����
//���ص�v������ĵ�һ���ڽӵ�,���򷵻�-1
int FirstAdjVexJ(AMGraph G, int v) {
	int output = -1;//������

	//for�����ҵ���v���ڵ���һ�����һ���ڽӵ�
	for (int i = 0;i < MVNum;i++) {
		if (G.arcs[v][i] == 1) {
			output = i;
			break;
		}
	}
	return output;
}
//����v�����w����һ���ڽӵ㣬���򷵻�-1
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

//��
//���ص�v������ĵ�һ���ڽӵ�,���򷵻�-1
int FirstAdjVexB(ALGraph G, int v) {
	return G.vertices[v].firstarc && G.vertices[v].firstarc->adjvex != NULL ? G.vertices[v].firstarc->adjvex : -1;
}
//����v�����w����һ���ڽӵ㣬���򷵻�-1
int NextAdjVexB(ALGraph G, int v, int w) {
	ArcNode* temp = G.vertices[v].firstarc;
	while (temp->nextArc && temp->nextArc->adjvex != w) {
		temp = temp->nextArc;
	}
	return temp->nextArc ? temp->nextArc->adjvex : -1;
}

//�ڽӾ����������
bool visited[MVNum];		//��������
void DFSJ(AMGraph G, int v) {
	cout << G.vexs[v];		//���ʵ�v���ڵ�
	visited[v] = true;			//����v����ʶΪtrue
	for (int w = FirstAdjVexJ(G, v);w >= 0;w = NextAdjVexJ(G, v, w)) {
		if (!visited[w]) {
			DFSJ(G, w);
		}
	}

}
//�ڽӱ��������
void DFSB(ALGraph G, int v) {
	bool visited1[MVNum] = { 0 };
	cout << G.vertices[v].data;		//���ʵ�v���ڵ�
	visited1[v] = true;			//����v����ʶΪtrue
	for (int w = FirstAdjVexB(G, v);w >= 0;w = NextAdjVexB(G, v, w)) {
		if (!visited1[w]) {
			DFSB(G, w);
		}
	}

}


//�ڽӾ���������
void BFSJ(AMGraph G, int v) {
	bool visited1[MVNum] = {0};
	cout << G.vexs[v];
	visited1[v] = true;
	SQueue Q;
	InitSQueue(Q, MVNum);	//���г�ʼ��
	
	
	Enter(Q, v);	//���
	int u = 0;		//��Ŷ�ͷ
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
//�ڽӱ�������
void BFSB(ALGraph G, int v) {
	bool visited1[MVNum] = {0};
	SQueue Q;	
	InitSQueue(Q, MVNum);	//���г�ʼ��
	cout << G.vertices[v].data;
	visited1[v] = true;
	Enter(Q, v);	//���
	int u = 0;		//��Ŷ�ͷ
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