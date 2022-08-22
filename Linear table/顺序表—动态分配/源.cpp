#include<iostream>
using namespace std;

#define InitSize 5
typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType* data;
	int length, MAXSIZE;
}SeqList;
//定义data指针来表示顺序表，以及length表示表长
//MAXSIZE必不可少—动态分配增加时需要将最大长度增加，InitSize固定数值无法改变

Status InitList(SeqList& L)
{
	L.data = new ElemType[InitSize];
	L.length = 0;
	L.MAXSIZE = InitSize;
	return true;
}
//初始化动态分配，表长置为0，使MAXSIZE为最大长度

Status IncreaseSize(SeqList& L,int i)
{
	ElemType* p = L.data;
	L.data = new ElemType[L.MAXSIZE + i];
	for (int i = 0; i < L.length; i++)
		L.data[i] = p[i];
	//InitSize = InitSize + i;InitSize固定无法更改
	L.MAXSIZE = L.MAXSIZE + i;
	delete p;
	return true;
}
//增加动态数组长度，需要数次移动已有元素，并更改最大长度

int main()
{
	SeqList L;
	InitList(L);
	IncreaseSize(L, 3);
	return 0;
}