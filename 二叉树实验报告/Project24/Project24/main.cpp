#include <iostream>
#include"Doubletree.h"
using namespace std;

void main()
{
	//tree* s = new tree;
	tree* s = (tree*)malloc(sizeof(tree));
	tree* a;		 //����


	cout << "ע�⣺�������ֱ���Ϊ������"<<endl;
	CreateTree(a);
	cout << "ǰ�����" << endl;
	Qian(a);
	cout << endl;//����
	cout << "�������" << endl;
	Zhong(a);
	cout << endl;
	cout << "�������" << endl;
	Hou(a);
	cout << endl;


	cout << "���Ϊ" << ShenDu(a) << endl;

	cout << "�ڵ���Ϊ" << JieDian(a) << endl;

	cout << "Ҷ�ڵ���Ϊ" << LeafPTree(a) << endl;

	cout << "��Ϊһ�Ľڵ���Ϊ" << DTree(a) << endl;

	int select;		//ѡ���ж�
	int flag1 = 1;
	cout << "1����������֦  2����ȫ��������֦  3�����ƶ�����  4�����ٶ����� 0���˳�" << endl;
	cin >> select;
	while (flag1)
	{
		switch (select)
		{
		case 1:
			system("CLS");//��������
			cout << "��������֦" << endl;
			Exchange(a);
			cout << "ǰ�����" << endl;
			Qian(a);
			cout << endl;
			cout << "�������" << endl;
			Zhong(a);
			cout << endl;
			cout << "�������" << endl;
			Hou(a);
			cout << endl;
			cout << "�������" << endl;
			Layer(a, JieDian(a));
			cout << "���Ϊ" << ShenDu(a) << endl;
			cout << "�ڵ���Ϊ" << JieDian(a) << endl;
			cout << "Ҷ�ڵ���Ϊ" << LeafPTree(a) << endl;
			cout << "��Ϊһ�Ľڵ���Ϊ" << DTree(a) << endl;
			break;
		case 2:
			system("CLS");//��������
			cout << "��ȫ��������֦" << endl;
			AllExchange(a);
			cout << "ǰ�����" << endl;
			Qian(a);
			cout << endl;
			cout << "�������" << endl;
			Zhong(a);
			cout << endl;
			cout << "�������" << endl;
			Hou(a);
			cout << endl;
			cout << "�������" << endl;
			Layer(a, JieDian(a));
			cout << "���Ϊ" << ShenDu(a) << endl;
			cout << "�ڵ���Ϊ" << JieDian(a) << endl;
			cout << "Ҷ�ڵ���Ϊ" << LeafPTree(a) << endl;
			cout << "��Ϊһ�Ľڵ���Ϊ" << DTree(a) << endl;
			break;
		case 3:
			Copy(a, s);
			system("CLS");//��������
			cout << "ǰ�����" << endl;
			Qian(s);
			cout << endl;
			cout << "�������" << endl;
			Zhong(s);
			cout << endl;
			cout << "�������" << endl;
			Hou(s);
			cout << endl;
			cout << "�������" << endl;
			Layer(a, JieDian(a));
			cout << "���Ϊ" << ShenDu(s) << endl;
			cout << "�ڵ���Ϊ" << JieDian(s) << endl;
			cout << "Ҷ�ڵ���Ϊ" << LeafPTree(s) << endl;
			cout << "��Ϊһ�Ľڵ���Ϊ" << DTree(s) << endl;
			break;
		case 4:
			Destroy(a);
			cout << "������ϣ�";
		default:
			cout << "�˳�" << endl;
			break;
		}
		cout << "��0�˳�" << endl;
		cin >> flag1;
	}
}