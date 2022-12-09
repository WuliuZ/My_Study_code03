#include <iostream>
#include"Doubletree.h"
using namespace std;

void main()
{
	//tree* s = new tree;
	tree* s = (tree*)malloc(sizeof(tree));
	tree* a;		 //声明


	cout << "注意：输入数字必须为整数！"<<endl;
	CreateTree(a);
	cout << "前序遍历" << endl;
	Qian(a);
	cout << endl;//分行
	cout << "中序遍历" << endl;
	Zhong(a);
	cout << endl;
	cout << "后序遍历" << endl;
	Hou(a);
	cout << endl;


	cout << "深度为" << ShenDu(a) << endl;

	cout << "节点数为" << JieDian(a) << endl;

	cout << "叶节点数为" << LeafPTree(a) << endl;

	cout << "度为一的节点数为" << DTree(a) << endl;

	int select;		//选择判断
	int flag1 = 1;
	cout << "1、交换左右枝  2、完全交换左右枝  3、复制二叉树  4、销毁二叉树 0、退出" << endl;
	cin >> select;
	while (flag1)
	{
		switch (select)
		{
		case 1:
			system("CLS");//清屏操作
			cout << "交换左右枝" << endl;
			Exchange(a);
			cout << "前序遍历" << endl;
			Qian(a);
			cout << endl;
			cout << "中序遍历" << endl;
			Zhong(a);
			cout << endl;
			cout << "后序遍历" << endl;
			Hou(a);
			cout << endl;
			cout << "层序遍历" << endl;
			Layer(a, JieDian(a));
			cout << "深度为" << ShenDu(a) << endl;
			cout << "节点数为" << JieDian(a) << endl;
			cout << "叶节点数为" << LeafPTree(a) << endl;
			cout << "度为一的节点数为" << DTree(a) << endl;
			break;
		case 2:
			system("CLS");//清屏操作
			cout << "完全交换左右枝" << endl;
			AllExchange(a);
			cout << "前序遍历" << endl;
			Qian(a);
			cout << endl;
			cout << "中序遍历" << endl;
			Zhong(a);
			cout << endl;
			cout << "后序遍历" << endl;
			Hou(a);
			cout << endl;
			cout << "层序遍历" << endl;
			Layer(a, JieDian(a));
			cout << "深度为" << ShenDu(a) << endl;
			cout << "节点数为" << JieDian(a) << endl;
			cout << "叶节点数为" << LeafPTree(a) << endl;
			cout << "度为一的节点数为" << DTree(a) << endl;
			break;
		case 3:
			Copy(a, s);
			system("CLS");//清屏操作
			cout << "前序遍历" << endl;
			Qian(s);
			cout << endl;
			cout << "中序遍历" << endl;
			Zhong(s);
			cout << endl;
			cout << "后序遍历" << endl;
			Hou(s);
			cout << endl;
			cout << "层序遍历" << endl;
			Layer(a, JieDian(a));
			cout << "深度为" << ShenDu(s) << endl;
			cout << "节点数为" << JieDian(s) << endl;
			cout << "叶节点数为" << LeafPTree(s) << endl;
			cout << "度为一的节点数为" << DTree(s) << endl;
			break;
		case 4:
			Destroy(a);
			cout << "销毁完毕！";
		default:
			cout << "退出" << endl;
			break;
		}
		cout << "按0退出" << endl;
		cin >> flag1;
	}
}