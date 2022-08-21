#include<iostream>
using namespace std;

#define MAXSIZE 5
typedef int ELemType;
typedef int Status;

typedef struct
{
	ELemType data[MAXSIZE];
	int length;
}SqList;

Status InitList(SqList &L)
{
	L.length = 0;
	return true;
}

int main()
{
	SqList L;
	InitList(L);
	return 0;
}