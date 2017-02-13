// DS_ShunXuTable.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define ElemType int

#define MaxSize 5
char arr[MaxSize];
int len;


typedef struct 
{
	ElemType * elem;
	int length;
	int listsize;
}Sqlist;

void initSqlist(Sqlist *L)
{
	L->elem = new ElemType[MaxSize]();
	if (!L->elem)
	{
		exit(1);
	}
	L->length = 0;
	L->listsize = MaxSize;
}

void printSqlist(Sqlist *L)
{
	for (int i = 0; i < L->listsize; i++)
	{
		printf("%d\t", L->elem[i]);
	}
	printf("\n");
}

void InsertElem(ElemType list[], int &n, int index, ElemType item)
{
	//一个顺序表，能插入的位置是 1~n+1
	if (index == MaxSize || index<1 || index>n+1)
	{
		exit(0);
	}
	for (int i = n-1; i >= index-1; i--)
	{
		list[i + 1] = list[i];
	}
	list[index - 1] = item;
	n++;
}

int main()
{	
	Sqlist * list = new Sqlist;
	
	initSqlist(list);
	printSqlist(list);

	ElemType list2[MaxSize];
	int list2len = 0;
	InsertElem(list2, list2len, 1, 90);
	InsertElem(list2, list2len, 1, 30);
	InsertElem(list2, list2len, 1, 40);
	InsertElem(list2, list2len, 1, 10);
	InsertElem(list2, list2len, 1, 80);

	printf("len = %d\n", list2len);
	for (int i = 0; i < list2len; i++)
	{
		printf("%d\t", list2[i]);
	}

	system("pause");
	return 0;
}

