#include<iostream>
using namespace std;

#define InitSize 5
typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType* data;
	int length, maxsize;
}SeqList;
//定义data指针来表示顺序表，以及length表示表长
//maxsize必不可少—动态分配增加时需要增加最大长度
//而InitSize已经定义好了固定数值，无法改变，因此需要一个另外的maxsize表示最大长度

Status InitList(SeqList& L)
{
	L.data = new ElemType[InitSize];
	L.length = 0;
	L.maxsize = InitSize;
	return true;
}
//初始化动态分配InitSize个空间，表长置为0，使maxsize为最大长度

Status CreateList(SeqList& L, ElemType x)
{
	if (L.length == L.maxsize)
		return false;
	L.data[L.length] = x;
	L.length++;
	return true;
}
//按顺序添加数据元素，每添加一个元素，表长加一

Status AddSize(SeqList& L,int i)
{
	ElemType* p = L.data;
	L.data = new ElemType[InitSize + i];
	for (int j = 0; j < L.length; j++)
		L.data[j] = p[j];
	L.maxsize = L.maxsize + i;
	return true;
}
//将L.data的所有元素暂存在p中，并重新给L.data动态分配InitSize+i的空间
//随后在将p中的元素移回L.data，更改最大长度
//增加动态数组长度，需要数次移动已有元素，使得效率大大降低，数组元素较多更低
//注意最后需要更改的是最大长度，才能最终表示动态增加空间成功

Status OutPut(SeqList L)
{
	if (L.length == 0)
		return false;
	for (int i = 0; i < L.length; i++)
		cout << L.data[i] << '\t';
	cout << endl;
	return true;
}

int main()
{
	SeqList L;
	InitList(L);
	CreateList(L, 3); CreateList(L, 5); CreateList(L, 7); CreateList(L, 1); 
	CreateList(L, 9); //到这个添加元素后，已经使顺序表满了
	CreateList(L, 7);//由于空间不足，这个元素无法插入顺序表中，也就是溢出
	OutPut(L);
	if (AddSize(L, 3))
		cout << L.maxsize << endl;//经验证，动态分配增加数组空间成功
	CreateList(L, 7);//增加动态数组空间之后，该元素成功插入顺序表中
	OutPut(L);
	return 0;
}