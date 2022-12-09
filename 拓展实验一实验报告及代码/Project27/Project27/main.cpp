#include <iostream>
#include "HF.h"
#include <string>
using namespace std;
int main()
{
    string str2[10]{ "1","1","1" ,"1" ,"1" ,"1" ,"1" ,"1" ,"1" ,"1" };
    int i = 0;
    while (str2[i] != "0")
    {
        i++;
        cin >> str2[i];
    }
    for (int j = 1; j < i; j++)
    {
        HfuTree* H = Frequency(str2[j]);
        int Hflag = Getlength(H);
        H = CreateHfuTree(H, Hflag);
        Print(H, Hflag);
        string str1 = Coding(H, Hflag, str2[j]);
        Decode(H, str1, Hflag);
    }
}