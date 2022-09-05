#include<iostream>
using namespace std;

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

Status InitLList(LinkList& L)
{
	L = new LNode;
	L = NULL;
	return true;
}
//初始化一个不带头结点的空链表

/*Status CreateLList_Head(LinkList& L, ElemType x)
{
	LNode* p;
	p = new LNode;
	p->data = x;
	p->next = L;
	L = p;
	return true;
}*/
//头插法直接创建单链表，和带头节点区别在于L指针的指向

Status CreateLList_Head(LinkList& L)
{
	LNode* p;
	p = new LNode;
	cout << "请输入元素(以9999结束)：";
	cin >> p->data;
	if (p->data != 9999)
	{
		p->next = L;
		L = p;
		CreateLList_Head(L);
	}
	return true;
}
//不带头结点递归头插法创建单链表，递归出口为p->data=9999
//先使p->next指向L，然后再将L指针移动指向p，满足单链表的逻辑关系，不需考虑首元结点

Status OutPutL(LinkList L)
{
	if (L == NULL)
		return false;
	LNode* p = L;
	while (p)
	{
		cout << p->data << '\t';
		p = p->next;
	}//与带头结点的不同之处，先输出数据，因为此时的p=L，是首元结点
	return true;
}

int main()
{
	LinkList L;
	InitLList(L);
	CreateLList_Head(L);
	/*CreateLList_Head(L, 3); CreateLList_Head(L, 5); CreateLList_Head(L, 7);*/
	OutPutL(L);
	return 0;
}