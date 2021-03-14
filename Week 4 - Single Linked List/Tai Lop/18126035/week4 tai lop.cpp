//MSSV:18126035
//Bai Tap Tren Lop: -them data vao dau dslk
//				- them data vao cuoi dslk


#include<iostream>
using namespace std;

struct NODE {		
	int data;
	NODE* pNext;
};

struct LIST {
	NODE* pHead;
	NODE* pTail;
};

// khoi tao dslk rong
void Init(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* createNode(int data)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;		// khong du bo nho de cap phat
	p->data = data;
	p->pNext = NULL;
	return p;
}
void Output(LIST l)
{
	for (NODE* i = l.pHead; i != NULL; i = i->pNext)
	{
		cout << i->data << "  ";
	}
}
NODE* addFirst(LIST& l, int data)
{
	NODE* p = createNode(data);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
	return p;

	
}
NODE* addTail(LIST& l, int data)
{	
	NODE* p = createNode(data);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
	return p;
}
int main()
{
	LIST l;
	Init(l);
	NODE* p;

	addFirst(l,20);
	addTail(l, 199);
	addFirst(l, -999);
	addTail(l, 0);

	Output(l);
	return 0;
}