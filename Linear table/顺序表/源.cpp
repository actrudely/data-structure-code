#include<iostream>
using namespace std;

#define MAXSIZE 5
typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;
//类型定义，定义一长度为MAXSZIE数组长度的数组空间，以及length表示长度

Status InitList(SqList &L)
{
	L.length = 0;
	return true;
}
//初始化，由于data为静态分配，不需判断！data，直接将表长置为0即可初始化

Status SqCreateList(SqList& L, ElemType x)
{
	if (L.length == MAXSIZE)
		return false;
	L.data[L.length] = x;
	L.length++;
	return true;
}
//按顺序插入元素，赋值后要表长+1
//跟栈的插入操作类似(非空时length指针始终指向表尾元素上一个位置)

Status InsertList(SqList& L, ElemType x, int i)
{
	if (L.length == MAXSIZE)
		return false;
	if (i<1 || i>L.length)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = x;
	L.length++;
	return true;
}
//按位插入元素，顺序表正常插入需要将其后的所有元素后移一个位置并表长+1

Status DeleteList(SqList& L, ElemType& x, int i)
{
	if (L.length == 0)
		return false;
	if (i<1 || i > L.length)
		return false;
	x = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}
//按位删除元素，将i位序即i-1数组下标元素删除并将之后的所有元素前移一个位置，表长-1

ElemType LocateElem(SqList L, int i)
{
	if (L.length != 0)
		return L.data[i - 1];
}
//按位查找，表长不为0，直接返回L.data[i-1]即可
//以上按位基本操作可以体现顺序表的随机存取性，但插入删除都需要前移后移，Q(n)

Status GetElem(SqList L, ElemType x)
{
	if (L.length == 0)
		return false;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == x)
			cout << i << '\t';
	}
	cout << endl;
	return true;
}
//按值查找,可能为多个,返回位序

Status DestroyList(SqList& L)
{
	if (L.length != 0)
		L.length = 0;
	return true;
}
//销毁操作，由于是静态分配，只需将length置为0，即可，系统将自动销毁

Status OutPutList(SqList L)
{
	if (L.length == 0)
		return NULL;
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << '\t';
	cout << endl;
	return true;
}
//显示线性表全部元素，用来检验操作是否成功

int main()
{
	SqList L;
	InitList(L);
	SqCreateList(L, 3); SqCreateList(L, 5);
	InsertList(L, 3, 2);
	OutPutList(L);
	int x = -1;
	if (DeleteList(L, x, 2))
		cout << x << endl;
	else
		return false;
	OutPutList(L);
	GetElem(L, 3);
	cout << LocateElem(L, 1) << endl;
	DestroyList(L);
	return 0;
}