#include "Node.h"
void Init(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* createNode(int data)
{
	NODE* p = new NODE;
	if (p == NULL)
		return NULL; // khong du bo nho de cap phat
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

// them node p vào sau node q
NODE* insertAfterQ(LIST& l, NODE* p, NODE* q)
{
	if (q == NULL)
		return NULL;
	if (q == l.pTail) // q la node cuoi thi addtail
		p = addTail(l, p->data);
	else
	{
		p->pNext = q->pNext;
		q->pNext = p;
	}
	return p;
}

//them node p truoc node q
NODE* InsertBeforeQ(LIST& l, NODE* p, NODE* q)
{
	if (q == NULL)
		return NULL;
	if (q == l.pHead) // Nếu q đúng là NODE đầu thì gọi hàm AddHead có sẵn
	{
		p = addFirst(l, p->data);
	}
	else
	{
		// Sau khi chạy vòng for thì NODE z sẽ chạy tới trước NODE q
		for (NODE* i = l.pHead; i->pNext != q; i = i->pNext)
		{
			i->pNext = p;
			p->pNext = q;
		}
	}
	return p;
}
//// hàm xóa 1 node nằm sau node q trong danh sách
void deleteAfterQ(LIST& l, NODE* q)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == q->data)
		{
			NODE* g = k->pNext;
			k->pNext = g->pNext;
			delete g;
		}
	}
}

void deleteList(LIST& l)
{

	NODE* k = NULL;
	while (l.pHead != NULL)
	{
		k = l.pHead;
		l.pHead = l.pHead->pNext;
		delete k;
	}
}

void deleteHead(LIST& l)
{
	if (l.pHead != NULL)
	{
		NODE* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
	return;
}

void deleteTail(LIST& l)
{
	if (l.pHead == NULL)
	{
		return;
	}
	if (l.pHead->pNext == NULL)
	{
		deleteHead(l);
		return;
	}
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == l.pTail)
		{
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k;
			return;
		}
	}
}

int getHead(LIST l)
{
	if (l.pHead == NULL)
		return NULL;
	return l.pHead->data;
}
int getTail(LIST l)
{
	if (l.pHead == NULL)
		return NULL;
	return l.pTail->data;
}

// lay ptu bat ky

int Get(LIST l, int index)
{
	int k = 0;
	NODE* p = l.pHead;
	while (p->pNext != NULL && k != index)
	{
		++k;
		p = p->pNext;
	}
	return p->data;
}

NODE* Search(LIST l, int key)
{
	if (l.pHead == NULL)
		return NULL;

	NODE* p = createNode(key);
	for (NODE* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (key == i->data)
		{
			return p;
		}
	}
	return NULL;
}

int listLen(LIST l)
{
	int count = 0;
	for (NODE* i = l.pHead; i != NULL; i = i->pNext)
	{
		count++;
	}
	return count;
}
//bai 3 ==========================
// nối 2 list lại với nhau
LIST Noi(LIST l1, LIST l2)
{
	LIST l3;
	if (l1.pHead == NULL && l2.pHead != NULL)
		l3 = l2;
	if (l1.pHead != NULL && l2.pHead == NULL)
		l3 = l1;
	if (l1.pHead != NULL && l2.pHead != NULL)
	{
		l3 = l1;
		for (NODE* i = l2.pHead; i != NULL; i = i->pNext)
		{
			addTail(l3, i->data);
		}
	}

	return l3;
}
