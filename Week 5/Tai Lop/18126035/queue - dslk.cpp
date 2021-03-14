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

// hàm khởi tạo queue
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
void Push(QUEUE& q, int x)
{
	NODE* p = createNODE(x);
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p; // NODE p chính là NODE đầu và NODE cuối
	}
	else // danh sách đã có phần tử
	{
		q.pTail->pNext = p; 
		q.pTail = p; 
	}
}

// //lay ptu dau va huy di
void Pop(QUEUE& q) // x chính là giá trị cần lấy trong NODE
{
	// nếu danh sách rỗng
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

 //hàm xuất danh sách queue
void Output(QUEUE q)
{
	while (IsEmpty(q) == false)
	{
		int x;
		Front(q, x);
		cout << x << "\t";
		Pop(q);
	}

}

int main()
{
	QUEUE q;
	Init(q);
	Push(q, 1);
	Push(q, 2);
	Push(q, 3);
	Push(q, 4);
	Push(q, 5);
	Output(q);
	return 0;
}
