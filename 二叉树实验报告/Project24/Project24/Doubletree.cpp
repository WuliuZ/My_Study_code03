#include <iostream>
#include"Doubletree.h"
using namespace std;
//�����ڵ�
void CreateTree(tree*& t)
{
	t = (tree*)malloc(sizeof(tree));
	int e;
	cout << "������洢��ֵ,��0����" << endl;
	cin >> e;
	if (e == 0)
	{
		t = NULL;
		return;
	}
	t->data = e;
	cout << "���봴������" << endl;
	CreateTree(t->Lnext);
	cout << "���봴������" << endl;
	CreateTree(t->Rnext);
	cout << "�������" << endl;
	return;
}
//ǰ�����

void Qian(tree* t)
{
	if (t == NULL)
	{
		return;
	}
	cout << t->data << " ";
	Qian(t->Lnext);
	Qian(t->Rnext);
	return;
}
//�������

void Zhong(tree* t)
{
	if (t == NULL)
	{
		return;
	}
	Zhong(t->Lnext);
	cout << t->data << " ";
	Zhong(t->Rnext);
	return;
}
//�������

void Hou(tree* t)
{
	if (t == NULL)
	{
		return;
	}
	Hou(t->Lnext);
	Hou(t->Rnext);
	cout << t->data << " ";
	return;
}
//��ȼ���

int ShenDu(tree* t)
{
	if (t == NULL)
	{
		return 0;
	}
	int L = ShenDu(t->Lnext);
	int R = ShenDu(t->Rnext);
	if (L >= R)
	{
		return L + 1;
	}
	else if (R > L)
	{
		return R + 1;
	}
}
//�ڵ�

int JieDian(tree* t)
{
	if (t == NULL)
	{
		return 0;
	}
	int m = JieDian(t->Lnext);
	m += JieDian(t->Rnext);
	return m + 1;
}
//Ҷ�ڵ�

int LeafPTree(tree* t)
{
	if (t == NULL)
	{
		return 0;
	}
	int m = LeafPTree(t->Lnext);
	m += LeafPTree(t->Rnext);
	if (t->Lnext == NULL && t->Rnext == NULL)
	{
		m = 1;
	}
	return m;
}
//��Ϊһ�Ľڵ���

int DTree(tree* t)
{
	if (t == NULL)
	{
		return 0;
	}
	int m = DTree(t->Lnext);
	m += DTree(t->Rnext);
	if ((t->Lnext != NULL && t->Rnext == NULL) || (t->Lnext == NULL && t->Rnext != NULL))
	{
		m = 1;
	}
	return m;
}
//��������֦

void Exchange(tree* t)
{
	tree* p = t->Lnext;
	t->Lnext = t->Rnext;
	t->Rnext = p;
}
//��ȫ��������֦

void AllExchange(tree* t)
{
	if (t == NULL)
	{
		return;
	}
	tree* p = t->Lnext;
	t->Lnext = t->Rnext;
	t->Rnext = p;
	AllExchange(t->Lnext);
	AllExchange(t->Rnext);
}
//����֦��֦��֦��......�ٽ���

tree* Copy(tree* S,tree* s) {
	if (S == NULL) {
		cout << "ԭ��Ϊ��" << endl;
		return NULL;
	}
	s->data = S->data;
	s->Lnext = S->Lnext;
	s->Rnext = S->Rnext;
	Copy(S->Lnext, s->Lnext);
	Copy(S->Rnext, s->Rnext);
}
//������

void Destroy(tree* S) {
	S->data = 0;
	free (S);
	Destroy(S->Lnext);
	Destroy(S->Rnext);
}
//�ݹ�������