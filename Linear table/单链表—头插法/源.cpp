#include<iostream>
using namespace std;

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;
//注意区分LNode和*LinkList的区别，以及注意next定义的方式
//通常用LinkList定义单链表，强调定义的是某个链表的头指针；
//用LNode*定义指向单链表中任意结点的指针变量（数据元素的指针）提高可读性

Status InitLList(LinkList& L)
{
	L = new LNode;
	L->next = NULL;
	return true;
}
//L为头指针，为L动态分配一个空间并使L->next指向空即初始化一个带头结点的空链表

Status CreateLList_Head(LinkList& L, ElemType x)
{
	LNode* p;
	p = new LNode;
	p->data = x;
	p->next = L->next;
	L->next = p;
	if (L->next == NULL)
		return false;
	return true;
}
//头插法创建单链表要考虑是否有头结点，有头结点则首元结点和后续操作一致，无则不一致
//且头插法创建单链表为倒序，需要考虑输入顺序

Status LocateLList(LinkList& L, int k)
{
	LNode* p = L;
	int i = 0;
	while (p && i < k-1)
	{
		p = p->next;
		i++;
	}
	cout << p->data << endl;
	if (p == NULL || i == k)
		return false;
	return true;
}
//查找操作，链表只能顺序查找，从头指针开始往后遍历，查找当前元素，O(n)
//p也可以从L>next开始，但会麻烦一些

Status InsertLList(LinkList& L, ElemType x, int k)
{
	LNode* p = L, * q;
	q = new LNode;
	int i = 0;
	while (p && i < k - 1)
	{
		p = p->next;
		i++;
	}
	if (!p || i == k)
		return false;
	q->data = x;
	q->next = p->next;
	p->next = q;
	return true;
}
//单链表的插入同样需要先查找前驱结点，然后再进行指针的修改
//在此情况下，一定要记得先使q->next=p->next，否则将会使q->next指向q自身
//由于链表随取随用分配空间的特性，插入元素不需要考虑是否已满

Status DeleteLList(LinkList& L, ElemType& x,int k)
{
	if (L->next == NULL)
		return false;
	LNode* p = L, * q;
	int i = 0;
	while (p && i < k - 1)
	{
		p = p->next;
		i++;
	}
	//找到前驱结点
	if (p == NULL || i == k)
		return false;
	q = p->next;
	x = q->data;
	p->next = q->next;
	delete q;
	return true;
}
//单链表的删除首先需要找到前驱结点，再对所需删除的位置进行指针修改
//需要判断单链表是否为空

Status OutPutL(LinkList L)
{
	if (L->next == NULL)
		return false;
	LNode* p = L->next;
	while (p)
	{
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;
	return true;
}

Status DestroyLList(LinkList& L)
{
	int x = -1;
	if (!L->next)
		DeleteLList(L, x, 1);
	delete L;
	L = NULL;
	return true;
}
//链表动态分配，先将所有元素删除后再delete L即可

int main()
{
	LinkList L;
	InitLList(L);
	CreateLList_Head(L, 7); CreateLList_Head(L, 5); CreateLList_Head(L, 3);
	OutPutL(L);
	int x = -1;
	if (DeleteLList(L, x, 2))
		cout << x << endl;
	else
		return false;
	InsertLList(L, 2, 2);
	OutPutL(L);
	DestroyLList(L);
	OutPutL(L);
	return 0;
}