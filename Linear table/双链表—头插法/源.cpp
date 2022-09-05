#include<iostream>
using namespace std;

typedef int ElemType;
typedef int Status;

typedef struct DNode
{
	ElemType data;
	int length;
	struct DNode* next, * prior;
}DNode, * DLinkList;

Status InitDList(DLinkList& L)
{
	L = new DNode;
	L->length = 0;
	L->next = NULL;
	L->prior = NULL;
	return true;
}
//由于是双链表，因此需要定义前驱和后继两个指针，并有头结点，则是L两指针都指向NULL
//创建一个带头结点的空双链表，即双链表判空为L->next,L->prior指向NULL

Status CreateDList_Head(DLinkList& L, ElemType x)
{
	DNode* p;
	p = new DNode;
	p->data = x;
	p->next = L->next;
	L->next = p;
	if (L->length == 0)
		p->prior = L;
	else
		p->next->prior = p;
	return true;
}
//与头插法单链表创建唯一不同的是，需要修改p->prior指针的指向，双链表特性

DNode* LocateDList(DLinkList L, int k)
{
	DNode* p = L, * q;
	int i = 0;
	while (p && i < k)
	{
		p = p->next;
		i++;
	}
	return p;
}
//DNode*能够返回指针变量，按位查找。若为ElemType,则返回的是值

Status InsertDList(DLinkList& L, ElemType x, int k)
{
	if (L->next == NULL)
		return false;
	DNode* p, * q;
	p = LocateDList(L, k - 1);
	if (!p)
		return false;
	q = new DNode;
	q->data = x;
	q->next = p->next;
	p->next = q;
	q->prior = p;
	return true;
}
//比单链表多了q->prior指针的指向修改,插入不需要考虑是否为最后一个
//不需考虑是否next为NULL而无法修改NULL的prior指针

Status DeleteDList(DLinkList& L, ElemType& x, int k)
{
	DNode* p, * q;
	p = LocateDList(L, k - 1);
	if (!p)
		return false;
	q = new DNode;
	q = p->next;
	x = q->data;
	if (!q->next)
	{
		p->next = q->next;
	}
	else
	{
		q->next->prior = p;
		p->next = q->next;
	}
	return true;
}
//需要修改q->next->prior指针的指向，删除需要考虑是否删除的最后一个
//若删除最后一个，则next指针指向的是NULL，NULL不需修改前驱指针，需分情况

Status OutPutD(DLinkList& L)
{
	if (L->next == NULL)
		return false;
	DNode* p=L->next;
	while (p)
	{
		cout << p->data << '\t';
		p =p->next;
	}
	cout << endl;
	return true;
}

int main()
{
	DLinkList L;
	InitDList(L);
	CreateDList_Head(L, 5); CreateDList_Head(L, 3); CreateDList_Head(L, 1);
	OutPutD(L);
	InsertDList(L, 7, 1);
	OutPutD(L);
	int x = -1;
	if (DeleteDList(L, x, 4))
		cout << x << endl;
	else
		return false;
	OutPutD(L);
	return 0;
}