#include "DSLK_Doi.h"

void Init(List& l)
{
    l.head = NULL; 
    l.tail = NULL; 
}

bool isEmpty(List l) 
{
    if (l.head == NULL)
        return true;
    return false;
}
Node* creatNode(int x) 
{ 
	Node* p = new Node;
	if (p == NULL) 
		exit(1);
	p->next = NULL;
	p->prev = NULL;
	p->data = x;
	return p;
}

// Them vao dau dslk
Node* addHead(List& l, int x) 
{
	Node* p = creatNode(x);
	if (isEmpty(l)) 
		l.head = l.tail = p;
	else 
	{
		p->next = l.head; 
		l.head->prev = p; 
		l.head = p; 
	}
	return p;
}
void Xuat(List l) 
{
	Node* p = l.head;
	if (p == NULL)
	{
		cout << "Danh Sach Lien Ket Doi Rong" << endl;
		return;
	}
	while (p != NULL)
	{
		cout << p->data << "\t";

		p = p->next;
	}
}
// them vao cuoi dslk
Node* addTail(List& l, int x) 
{
	Node* p = creatNode(x);
	if (isEmpty(l)) 
		addHead(l, x);
	else 
	{
		l.tail->next = p; 
		p->prev = l.tail; 
		l.tail = p; 
	}
	return p;

}
//chieu dai List
int Size(List l)
{
	Node* PH = l.head, * PT = l.tail;  
	int len = 0; 
	if (PH != NULL) 
		len = 1;
	while (PH != NULL) 
	{
		if (PH == PT) break;
		PH = PH->next;
		len++;
		if (PH == PT) break;
		PT = PT->prev; 
		len++;
	}
	return len; 
}
// chen vi tri bat ki;
void addSomeWhere(List& l, int x, int k) 
{ 
	if (isEmpty(l) || k <= 1) 
		addHead(l, x);
	else if (k >= Size(l)) 
		addTail(l, x);
	else 
	{
		Node* p = creatNode(x);
		Node* q = new Node, * w = new Node;
		Node* r = l.head;
		int dem = 0;
		while (r != NULL) 
		{
			dem++;
			q = r;
			if (dem == k) break;
			else r = r->next;
		}
		w = l.head;
		while (w->next != q) w = w->next;
		w->next = p; p->prev = w;
		p->next = r;  r->prev = p;
	}
}

void delHead(List& l) 
{
	if (!isEmpty(l)) 
	{
		Node* p = l.head;
		l.head = l.head->next; 
		l.head->prev = NULL;
		delete p; 
	}
	return;
}

void delTail(List& l) 
{
	if (!isEmpty(l)) 
	{
		Node* p = l.tail;
		l.tail = l.tail->prev; 
		l.tail->next = NULL;
		p->prev = NULL;
		delete p;
	}
	return;
}

// xoa vi tri bat ky
void deleteSomeWhere(List& l, int k) 
{
	if (k <= 1) 
		delHead(l);
	else if (k >= Size(l)) 
		delTail(l);
	else {
		int dem = 0;
		if (!isEmpty(l)) {
			Node* p = l.head;
			Node* q = new Node;
			while (p != NULL) 
			{ 
				dem++;
				q = p;
				if (dem == k) break; 
				else p = p->next; 
			}
			Node* r = l.head;
			while (r->next != q) r = r->next; 
			r->next = q->next; 
			(q->next)->prev = r;
			delete q;
		}
	}
}
void deleteList(List& l)
{
	Node* k = NULL;
	while (l.head != NULL)
	{
		k = l.head;
		l.head = l.head->next;
		delete k;
	}
}
// lay [han tu dau
int getHead(List l)
{
	if (isEmpty(l))
		return NULL;\
	return l.head->data;
}
//lay phan tu cuoi
int getTail(List l)
{
	if (isEmpty(l))
		return NULL;
	return l.tail->data;
}
//lay bat ky 
int Get(List l, int index)
{
	int k = 0;
	Node* p = l.head;
	while (p->next != NULL && k != index)
	{
		++k;
		p = p->next;
	}
	return p->data;
}
Node* Search(List l, int key)
{
	if (isEmpty(l))
		return NULL;
	Node* p = creatNode(key);
	for (Node* i = l.head; i != NULL; i = i->next)
	{
		if (key == i->data)
		{
			return p;
		}
	}
	return NULL;

}

List Noi(List l1, List l2)
{
	List l3;
	if (l1.head == NULL && l2.head != NULL)
		l3 = l2;
	if (l1.head != NULL && l2.head == NULL)
		l3 = l1;
	if (l1.head != NULL && l2.head != NULL)
	{
		l3 = l1;
		for (Node* i = l2.head; i != NULL; i = i->next)
		{
			addTail(l3, i->data);
		}
	}

	return l3;
}