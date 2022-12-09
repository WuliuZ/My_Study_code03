#pragma once
#ifndef DOUBLETREE
#define DOUBLETREE
struct tree
{
	int data;
	tree* Lnext;
	tree* Rnext;
};
void CreateTree(tree*& t);
void Qian(tree* t);
void Zhong(tree* t);
void Hou(tree* t);
int ShenDu(tree* t);
int JieDian(tree* t);
int LeafPTree(tree* t);
int DTree(tree* t);
void Exchange(tree* t);
void AllExchange(tree* t);
tree* Copy(tree* S, tree* s);
void Destroy(tree* S);
#endif