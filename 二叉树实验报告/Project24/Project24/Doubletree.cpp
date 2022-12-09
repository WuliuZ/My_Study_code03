#include <iostream>
#include"Doubletree.h"
using namespace std;
//创建节点
void CreateTree(tree*& t)
{
	t = (tree*)malloc(sizeof(tree));
	int e;
	cout << "请输入存储的值,按0结束" << endl;
	cin >> e;
	if (e == 0)
	{
		t = NULL;
		return;
	}
	t->data = e;
	cout << "进入创建左子" << endl;
	CreateTree(t->Lnext);
	cout << "进入创建右子" << endl;
	CreateTree(t->Rnext);
	cout << "创建完成" << endl;
	return;
}
//前序遍历

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
//中序遍历

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
//后序遍历

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
//深度计算

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
//节点

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
//叶节点

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
//度为一的节点数

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
//交换左右枝

void Exchange(tree* t)
{
	tree* p = t->Lnext;
	t->Lnext = t->Rnext;
	t->Rnext = p;
}
//完全交换左右枝

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
//左右枝的枝的枝的......再交换

tree* Copy(tree* S,tree* s) {
	if (S == NULL) {
		cout << "原树为空" << endl;
		return NULL;
	}
	s->data = S->data;
	s->Lnext = S->Lnext;
	s->Rnext = S->Rnext;
	Copy(S->Lnext, s->Lnext);
	Copy(S->Rnext, s->Rnext);
}
//复制树

void Destroy(tree* S) {
	S->data = 0;
	free (S);
	Destroy(S->Lnext);
	Destroy(S->Rnext);
}
//递归销毁树