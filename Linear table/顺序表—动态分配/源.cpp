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

Status InitList(SeqList& L)
{
	L.data = new ElemType[InitSize];
	L.length = 0;
	L.MAXSIZE = InitSize;
	return true;
}

Status IncreaseSize(SeqList& L,int i)
{
	ElemType* p;
	p = L.data;
	L.data = new ElemType[L.MAXSIZE + i];
	for (int i = 0; i < L.length; i++)
		L.data[i] = p[i];
	//InitSize = InitSize + i;
	L.MAXSIZE = L.MAXSIZE + i;
	delete p;
	return true;
}

int main()
{
	SeqList L;
	InitList(L);
	IncreaseSize(L, 3);
	return 0;
}