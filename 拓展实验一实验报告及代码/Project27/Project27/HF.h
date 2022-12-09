#pragma once
#include <string>
using namespace std;
struct HfuTree
{
    char data;
    int wight;
    int parent, Lchild, Rchild;
};

HfuTree* Frequency(string str);
void Select(HfuTree* H, int* n1, int* n2, int Hflag);
HfuTree* CreateHfuTree(HfuTree* H, int Hflag);
int Getlength(HfuTree H[]);
void Print(HfuTree* H, int Hflag);
string Coding(HfuTree* H, int Hflag, string str);
void Decode(HfuTree* H, string str, int Hflag);