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
	L->next = NULL;
	return true;
}

Status CreateLList_Tail(LinkList& L)
{
	LNode* p, * r;
	r = L;
	int x;
	cout << "元素数量：";
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		p = new LNode;
		cout << "元素：";
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
	return true;
}
//尾插法创建单链表，需要多设置一个尾指针用来始终指向表尾元素
//用尾指针的指针指向来体现逻辑关系，输入顺序与输出顺序相同
//且由于一开始需要定义r并初始化r指向L，因此不能使用递归或者直接输入值的方式创建
//由于每次插入都是表尾元素，因此使p->next指向NULL，而后再修改r指针的指向即可

//虽然创建链表定义了尾指针r，
//但尾指针r不像L可算作全局变量，没法在每一个基本操作都指向尾结点
//于是事实上，插入删除，查找等操作与头插法单链表没有区别
//尾插法单链表唯一的区别在于创建时和头插法单链表有些许不同

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
	return true;
}

int main()
{
	LinkList L;
	InitLList(L);
	CreateLList_Tail(L);
	OutPutL(L);
	return 0;
}