#include<iostream>
using namespace std;

struct NODE
{
	int data; 
	struct NODE* pNext; 
};
struct QUEUE
{
	NODE* pHead; 
	NODE* pTail;  
};

// ham khoi tao  
void Init(QUEUE& q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

NODE* createNODE(int x)
{
	NODE* p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; 
	p->pNext = NULL;
	return p;
}

// ktra queue co rong hay ko
bool IsEmpty(QUEUE q)
{
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;
}

// them ptu vao queue
void Enqueue(QUEUE& q, int x)
{
	NODE* p = createNODE(x);
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p;
	}
	else 
	{
		q.pTail->pNext = p; 
		q.pTail = p; 
	}
}

// //lay ptu dau va huy di
void Dequeue(QUEUE& q) // 
{
	if (IsEmpty(q) == true)
	{
		cout << "Rong";
	}
	else
	{
		int x;
		NODE* p = q.pHead; 
		x = p->data; 
		q.pHead = q.pHead->pNext; 
		delete p; 
	}

}


//xem thong tin ptu dau queue
void Front(QUEUE& q, int& x) 
{
	if (IsEmpty(q) == true)
	{
		cout << "Rong";
	}
	x = q.pHead->data;
}
void Output(QUEUE q)
{
	while (IsEmpty(q) == false)
	{
		int x;
		Front(q, x);
		cout << x << "\t";
		Dequeue(q);
	}

}

int main()
{
	QUEUE q;
	Init(q);
	Enqueue(q, 1);
	Enqueue(q, 2);
	Enqueue(q, 3);
	Enqueue(q, 4);
	Enqueue(q, 5);
	Dequeue(q); 
	Output(q);
	return 0;
}
