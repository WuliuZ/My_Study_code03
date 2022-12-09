#include <iostream>
#include <string>
#include "HF.h"
using namespace std;

//Ƶ��
HfuTree* Frequency(string str)
{
    int Hflag = 1;
    int flag, min, a = 0;
    HfuTree* H = (HfuTree*)malloc(sizeof(HfuTree));
    for (int i = 0; i < str.length(); i++)
    {
        flag = 1;
        min = 999999999;
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j])
            {
                flag++;
            }
            else
            {
                if (min >= j)
                {
                    min = j;
                }
            }
            if (j == str.length() - 1)
            {
                cout << str[i] << ":" << flag << " ";
                H[Hflag].data = str[i];
                H[Hflag].wight = flag;
                H[Hflag].parent = 0;
                H[Hflag].Lchild = 0;
                H[Hflag].Rchild = 0;
                Hflag++;
                H[Hflag].wight = 0;
                H[Hflag].parent = 0;
                H[Hflag].Lchild = 0;
                H[Hflag].Rchild = 0;
                i = min - 1;
            }
        }
    }
    cout << endl;
    return H;
}

//ѡ����С������
void Select(HfuTree* H, int* n1, int* n2, int Hflag)
{
    int min1 = 99999;
    int min2 = 99999;
    for (int i = 1; i < Hflag + 1; i++)
    {
        if (H[i].wight < min1 && H[i].parent == 0)
        {
            min1 = H[i].wight;
            *n1 = i;
        }
    }
    for (int i = 1; i < Hflag + 1; i++)
    {
        if (H[i].wight < min2 && H[i].parent == 0 && i != *n1)
        {
            min2 = H[i].wight;
            *n2 = i;
        }
    }
}

//������������
HfuTree* CreateHfuTree(HfuTree* H, int Hflag)
{
    int* n1 = (int*)malloc(sizeof(int));
    int* n2 = (int*)malloc(sizeof(int));
    int sum = Hflag;
    for (int i = Hflag + 1; i < 2 * (sum); i++)
    {
        Select(H, n1, n2, Hflag);
        H[i].data = '0';
        H[i].wight = H[*n1].wight + H[*n2].wight;
        H[i].Lchild = *n1;
        H[i].Rchild = *n2;
        H[i].parent = 0;
        H[*n1].parent = i;
        H[*n2].parent = i;
        Hflag++;
    }
    return H;
}

//�󳤶�
int Getlength(HfuTree H[])
{
    int sum = 0;
    for (int i = 1; H[i].wight != 0; i++)
    {
        sum += sizeof(H[i]);
    }
    sum = sum / sizeof(H[1]);
    return sum;
}

//��ӡ����
void Print(HfuTree* H, int Hflag)
{
    for (int i = 1; i < 2 * (Hflag); i++)
    {
        cout << i << " " << H[i].wight << " " << H[i].parent << " " << H[i].Lchild << " " << H[i].Rchild << endl;
    }
}

//���б���
string Coding(HfuTree* H, int Hflag, string str)
{
    int sum = 0;//����a�±�
    int nowset = 2 * Hflag - 1;//��ǰλ��
    char* a = new char[(2 * Hflag + 1) / 2];//����0 1
    int* key = new int[2 * Hflag];//��־
    string* Str1 = new string[(2 * Hflag - 1) * str.length() / 2];
    for (int i = 0; i < (2 * Hflag + 1) / 2; i++)
    {
        a[i] = '0';
    }
    for (int i = 0; i < 2 * Hflag; i++)
    {
        key[i] = 0;
    }
    while (key[2 * Hflag - 1] == 0)
    {
        while ((H[nowset].Lchild != 0 && (key[H[nowset].Lchild] == 0 || key[H[nowset].Rchild] == 0)) || (H[nowset].Rchild != 0 && (key[H[nowset].Lchild] == 0 || key[H[nowset].Rchild] == 0)))
        {
            if (H[nowset].Lchild != 0 && key[H[nowset].Lchild] == 0)//�������Ӳ�δ������
            {
                a[sum] = '0';
                sum++;
                nowset = H[nowset].Lchild;
            }
            else if (H[nowset].Rchild != 0 && key[H[nowset].Rchild] == 0)//�������Ӳ�δ������
            {
                a[sum] = '1';
                sum++;
                nowset = H[nowset].Rchild;
            }
        }
        if (H[nowset].data != '0')
        {
            cout << H[nowset].data << ":";
            for (int i = 0; i < sum; i++)
            {
                cout << a[i];
                Str1[nowset] += a[i];//�������
            }
            cout << " ";
        }
        key[nowset] = 1;
        nowset = H[nowset].parent;
        sum--;
    }
    cout << endl;
    string str2 = "9";
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < 2 * Hflag; j++)
        {
            if (str[i] == H[j].data)//����dataλ���ҵ���Ӧ����
            {
                cout << Str1[j];
                str2 += Str1[j];
            }
        }
    }
    cout << endl;
    return str2;
}

//����
void Decode(HfuTree* H, string str, int Hflag)
{
    int nowset = 2 * Hflag - 1;//�Ӷ��˿�ʼ
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == '1')
        {
            nowset = H[nowset].Rchild;
        }
        else if (str[i] == '0')
        {
            nowset = H[nowset].Lchild;
        }
        if (H[nowset].Lchild == 0 && H[nowset].Rchild == 0)//û��������ʱ��ӡ
        {
            cout << H[nowset].data;
            nowset = 2 * Hflag - 1;
        }
    }
    cout << endl;
}

